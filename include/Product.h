#ifndef PRODUCT_H
#define PRODUCT_H

#include "ShippingItem.h"
#include "ShippingInfo.h"
#include "ExpirationInfo.h"

class Product: public ShippingItem {
private:
    std::string name;
    double price;
    int quantity;
    ShippingInfo* shippingInfo;
    ExpirationInfo* expirationInfo;
public:
    Product(std::string name, double price, int quantity);
    std::string getName() const override;
    double getPrice() const;
    int getQuantity() const;
    ShippingInfo* getShippingInfo() const;
    ExpirationInfo* getExpirationInfo() const;
    double getWeight() const override;
    void setName(const std::string &name);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setShippingInfo(ShippingInfo* shippingInfo);
    void setExpirationInfo(ExpirationInfo* expirationInfo);
    void buyQuantity(int quantity);
};



#endif //PRODUCT_H
