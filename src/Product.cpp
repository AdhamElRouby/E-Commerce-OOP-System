#include "Product.h"

#include <stdexcept>

Product::Product(std::string name, double price, int quantity)
    : name(name), price(price), quantity(quantity), shippingInfo(nullptr), expirationInfo(nullptr) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

ShippingInfo* Product::getShippingInfo() const {
    return shippingInfo;
}

ExpirationInfo* Product::getExpirationInfo() const {
    return expirationInfo;
}

double Product::getWeight() const {
    return shippingInfo ? shippingInfo->getWeight() : 0.0;
}

void Product::setName(const std::string &name) {
    this->name = name;
}

void Product::setPrice(const double price) {
    this->price = price;
}

void Product::setQuantity(const int quantity) {
    this->quantity = quantity;
}

void Product::setShippingInfo(ShippingInfo* shippingInfo) {
    this->shippingInfo = shippingInfo;
}

void Product::setExpirationInfo(ExpirationInfo* expirationInfo) {
    this->expirationInfo = expirationInfo;
}

void Product::buyQuantity(int quantity) {
    if (quantity > this->quantity) return;
    this->quantity -= quantity;
}