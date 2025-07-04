#ifndef STORE_H
#define STORE_H

#include <map>
#include "Product.h"
#include "ShippingService.h"

// Forward declaration to avoid circular dependency
class Customer;

class Store {
private:
    std::map<std::string, Product*> products;
    ShippingService* shippingService;
public:
    Store();
    ShippingService* getShippingService() const;
    Product* getProduct(const std::string& productName) const;
    void addProduct(Product* product);
    void buyProduct(const std::string& productName, int quantity);
    void registerCustomer(Customer* customer);
    bool isProductAvailable(const std::string& productName) const;
};



#endif //STORE_H
