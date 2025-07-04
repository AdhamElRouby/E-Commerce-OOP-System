#include "Store.h"
#include "Customer.h"

Store::Store() : shippingService(new ShippingService()) {
    // Initialize the store with an empty product map and a new ShippingService instance
};

ShippingService* Store::getShippingService() const {
    return shippingService;
}

Product* Store::getProduct(const std::string& productName) const {
    auto it = products.find(productName);
    if (it != products.end()) {
        return it->second;
    }
    return nullptr; // Product not found
}

void Store::addProduct(Product* product) {
    products[product->getName()] = product;
}

void Store::buyProduct(const std::string& productName, int quantity) {
    auto it = products.find(productName);
    if (it != products.end()) {
        Product* product = it->second;
        if (product->getQuantity() >= quantity) {
            product->buyQuantity(quantity);
        }
    }
}

void Store::registerCustomer(Customer* customer) {
    customer->setStore(this);
}

bool Store::isProductAvailable(const std::string& productName) const {
    const auto it = products.find(productName);
    if (it != products.end()) {
        return it->second->getQuantity() > 0; // Check if the product has available units
    }
    return false; // Product not found
}