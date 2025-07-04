#include "CartItem.h"

CartItem::CartItem(Product* product, int quantity) : product(product), quantity(quantity) {}

Product* CartItem::getProduct() const {
    return product;
}

int CartItem::getQuantity() const {
    return quantity;
}

void CartItem::setProduct(Product* product) {
    this->product = product;
}

void CartItem::setQuantity(const int quantity) {
    this->quantity = quantity;
}

