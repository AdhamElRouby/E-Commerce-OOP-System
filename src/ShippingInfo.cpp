#include "ShippingInfo.h"

ShippingInfo::ShippingInfo(const double weight) : weight(weight) {}

double ShippingInfo::getWeight() const {
    return weight;
}

void ShippingInfo::setWeight(const double weight) {
    this->weight = weight;
}
