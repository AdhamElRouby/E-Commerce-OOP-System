#include <iostream>
#include "Store.h"
#include "Product.h"
#include "Customer.h"
#include "ExpirationInfo.h"
#include "ShippingInfo.h"
using namespace std;

int main() {

    cout << "*** E-commerce System ***" << endl;

    // Create a store
    Store* store = new Store();

    cout << "\n=== Creating Products ===" << endl;

    // Create Cheese (with expiration info and shipping info)
    Product* cheese = new Product("Cheese", 15.99, 10);
    cheese->setExpirationInfo(new ExpirationInfo(15, 8, 2025)); // Expires Aug 15, 2025
    cheese->setShippingInfo(new ShippingInfo(0.5)); // 0.5 kg
    store->addProduct(cheese);
    cout << "Added Cheese - Price: $15.99, Quantity: 10, Expires: Aug 15, 2025, Weight: 0.5kg" << endl;

    // Create Biscuits (with expiration info and shipping info)
    Product* biscuits = new Product("Biscuits", 8.50, 20);
    biscuits->setExpirationInfo(new ExpirationInfo(30, 12, 2025)); // Expires Dec 30, 2025
    biscuits->setShippingInfo(new ShippingInfo(0.3)); // 0.3 kg
    store->addProduct(biscuits);
    cout << "Added Biscuits - Price: $8.50, Quantity: 20, Expires: Dec 30, 2025, Weight: 0.3kg" << endl;

    // Create Chocolate (with expired date: 6/4/2025)
    Product* chocolate = new Product("Chocolate", 12.99, 5);
    chocolate->setExpirationInfo(new ExpirationInfo(4, 6, 2025)); // Expired June 4, 2025
    chocolate->setShippingInfo(new ShippingInfo(0.2)); // 0.2 kg
    store->addProduct(chocolate);
    cout << "Added Chocolate - Price: $12.99, Quantity: 5, Expires: June 4, 2025 (EXPIRED), Weight: 0.2kg" << endl;

    // Create TV (shipping info only)
    Product* tv = new Product("TV", 899.99, 3);
    tv->setShippingInfo(new ShippingInfo(15.0)); // 15 kg
    store->addProduct(tv);
    cout << "Added TV - Price: $899.99, Quantity: 3, Weight: 15kg" << endl;

    // Create Mobile (no shipping or expiration)
    Product* mobile = new Product("Mobile", 599.99, 8);
    store->addProduct(mobile);
    cout << "Added Mobile - Price: $599.99, Quantity: 8" << endl;

    cout << "\n=== Creating Customers ===" << endl;

    // Customer 1: No issues
    Customer* customer1 = new Customer(1, 1000.0);
    store->registerCustomer(customer1);
    cout << "Created Customer 1 - ID: 1, Balance: $1000.00" << endl;

    cout << "\n--- Customer 1: Normal Purchase ---" << endl;
    customer1->addToCart("Cheese", 2);
    customer1->addToCart("Biscuits", 3);
    customer1->checkout();

    // Customer 2: Bought expired chocolate & tried to add something with not enough quantity
    Customer* customer2 = new Customer(2, 500.0);
    store->registerCustomer(customer2);
    cout << "\nCreated Customer 2 - ID: 2, Balance: $500.00" << endl;

    cout << "\n--- Customer 2: Attempting to buy expired chocolate ---" << endl;
    customer2->addToCart("Chocolate", 2); // Should fail due to expiration

    cout << "\n--- Customer 2: Attempting to buy more TVs than available ---" << endl;
    customer2->addToCart("TV", 5); // Should fail due to insufficient quantity (only 3 available)

    // Customer 3: Empty cart & tried to checkout later with insufficient balance
    Customer* customer3 = new Customer(3, 50.0);
    store->registerCustomer(customer3);
    cout << "\nCreated Customer 3 - ID: 3, Balance: $50.00" << endl;

    cout << "\n--- Customer 3: Attempting checkout with empty cart ---" << endl;
    customer3->checkout(); // Should fail due to empty cart

    cout << "\n--- Customer 3: Adding expensive item with insufficient balance ---" << endl;
    customer3->addToCart("TV", 1); // Should succeed in adding to cart
    customer3->checkout(); // Should fail due to insufficient balance ($50 < $899.99)

    cout << "\n=== Test Complete ===" << endl;

    return 0;
}