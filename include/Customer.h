#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CartItem.h"
#include <vector>

// Forward declaration to avoid circular dependency
class Store;

class Customer {
private:
    int id;
    double balance;
    std::vector<CartItem*> cartItems;
    Store* store;
public:
    Customer(int id, double balance);
    int getId() const;
    double getBalance() const;
    std::vector<CartItem*> getCartItems() const;
    Store* getStore() const;
    void setBalance(double newBalance);
    void setStore(Store* store);
    void addToCart(const std::string &productName, int quantity);
    void checkout();
};



#endif //CUSTOMER_H
