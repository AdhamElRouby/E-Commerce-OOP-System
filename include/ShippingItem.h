#ifndef SHIPPINGITEM_H
#define SHIPPINGITEM_H
#include <string>


class ShippingItem {
public:
    virtual ~ShippingItem() = default;
    virtual std::string getName() const = 0;
    virtual double getWeight() const = 0;
};



#endif //SHIPPINGITEM_H
