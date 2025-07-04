#include "Customer.h"
#include "Store.h"
#include "ShippingService.h"
#include <iostream>
#include <iomanip>

Customer::Customer(int id, double balance) : id(id), balance(balance), store(nullptr) {}

int Customer::getId() const {
    return id;
}

double Customer::getBalance() const {
    return balance;
}

std::vector<CartItem*> Customer::getCartItems() const {
    return cartItems;
}

Store* Customer::getStore() const {
    return store;
}

void Customer::setBalance(const double newBalance) {
    balance = newBalance;
}

void Customer::setStore(Store* store) {
    this->store = store;
}

void Customer::addToCart(const std::string &productName, const int quantity) {
    if(store == nullptr) {
        std::cout << "Customer " << id << " need to register for a store first!" << std::endl;
        return;
    }
    if(!store->isProductAvailable(productName)) {
        std::cout << "Product " << productName << " is out of stock." << std::endl;
        return;
    }
    const Product* product = store->getProduct(productName);
    if (product->getQuantity() >= quantity) {
        if(product->getExpirationInfo() != nullptr && product->getExpirationInfo()->isExpired()) {
            std::cout << "Product " << productName << " is expired and cannot be added to the cart."
                                                                                << std::endl;
            return;
        }
        auto* item = new CartItem(store->getProduct(productName), quantity);
        cartItems.push_back(item);
    } else {
        std::cout << "There is no available units of " << productName << " in the store." << std::endl;
        std::cout << "You want to order " << quantity << " units but the store has "
                  << store->getProduct(productName)->getQuantity() << " units." << std::endl;
    }
}

void Customer::checkout() {
    if (store == nullptr) {
        std::cout << "Customer " << id << " need to register for a store first!" << std::endl;
        return;
    }

    // Ensure the cart is not empty
    if (cartItems.empty()) {
        std::cout << "Cart is empty. Cannot checkout." << std::endl;
        return;
    }

    std::cout << "** Checkout for Customer " << id << " **" << std::endl;

    // Calculate total price and check inventory
    double subtotalPrice = 0.0;
    double primitiveShippingFee = 0.0;
    std::vector<std::pair<int, ShippingItem*>> shippingItems;

    // Check if there are enough items in store for each cart item
    for (const auto& cartItem : cartItems) {
        const Product* product = cartItem->getProduct();
        if (product->getQuantity() < cartItem->getQuantity()) {
            std::cout << "Insufficient stock for " << product->getName()
                      << ". Available: " << product->getQuantity()
                      << ", Required: " << cartItem->getQuantity() << std::endl;
            return;
        }
        subtotalPrice += product->getPrice() * cartItem->getQuantity();
        if(product->getShippingInfo() != nullptr) {
            primitiveShippingFee += ShippingService::FEE_PER_KG * product->getShippingInfo()->getWeight()
                                                                    * cartItem->getQuantity();
        }
    }

    // Check if balance is sufficient
    if (balance < subtotalPrice + primitiveShippingFee) {
        std::cout << "Insufficient balance. Required: $" << std::fixed << std::setprecision(2)
                  << subtotalPrice << ", Available: $" << balance << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(2);

    // Print purchase table
    std::cout << "\n=== Purchase Summary ===" << std::endl;
    std::cout << std::left << std::setw(20) << "Item"
              << std::setw(12) << "Quantity"
              << std::setw(15) << "Unit Price"
              << std::setw(15) << "Total Price" << std::endl;
    std::cout << std::string(62, '-') << std::endl;

    // Loop through all items, buy each, add to shipping if available
    for (const auto& cartItem : cartItems) {
        Product* product = cartItem->getProduct();
        const int quantity = cartItem->getQuantity();
        const double unitPrice = product->getPrice();
        const double totalPrice = unitPrice * quantity;

        // Print item details
        std::cout << std::left << std::setw(20) << product->getName()
                  << std::setw(12) << quantity
                  << "$" << std::setw(14) << unitPrice
                  << "$" << std::setw(14) << totalPrice << std::endl;

        // Buy the product (reduce inventory)
        store->buyProduct(product->getName(), quantity);

        // Add to shipping if available (has shipping info)
        if (product->getShippingInfo() != nullptr) {
            // Add the product to shipping list with its quantity as a pair
            shippingItems.emplace_back(quantity, static_cast<ShippingItem*>(product));
        }
    }

    std::cout << std::string(62, '-') << std::endl;
    std::cout << std::left << std::setw(47) << "Subtotal Price:"
              << "$" << subtotalPrice << std::endl;

    // Show shipment data if there are shippable items
    double shippingFee = 0.0;

    if (!shippingItems.empty()) {
        store->getShippingService()->setItems(shippingItems);
        store->getShippingService()->display();
        shippingFee = store->getShippingService()->getTotalShippingFee();
    }

    // Final summary
    const double totalAmount = subtotalPrice + shippingFee;
    std::cout << "\n" << std::string(30, '-') << std::endl;
    std::cout << std::left << std::setw(20) << "Subtotal Price:" << "$" << subtotalPrice << std::endl;
    std::cout << std::left << std::setw(20) << "Shipping Fees:" << "$" << shippingFee << std::endl;
    std::cout << std::left << std::setw(20) << "Amount:" << "$" << totalAmount << std::endl;
    std::cout << std::string(30, '-') << std::endl;

    std::cout << "\nCheckout completed successfully!" << std::endl;
    balance -= totalAmount;
    std::cout << "Remaining balance: $" << balance << std::endl;

}
