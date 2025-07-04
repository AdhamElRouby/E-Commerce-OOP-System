#ifndef SHIPPINGSERVICE_H
#define SHIPPINGSERVICE_H

#include <vector>
#include <utility>

#include "ShippingItem.h"

class ShippingService {
private:
    std::vector<std::pair<int, ShippingItem*>> items; // quantity, item
    double totalShippingFee;
public:
    static const double FEE_PER_KG; // shipping fee per kg
    ShippingService();
    std::vector<std::pair<int, ShippingItem*>> getItems() const;
    void setItems(const std::vector<std::pair<int, ShippingItem*>>& items);
    double getTotalShippingFee() const;
    void setTotalShippingFee(double totalShippingFee);
    void display() const;
};

#endif //SHIPPINGSERVICE_H
