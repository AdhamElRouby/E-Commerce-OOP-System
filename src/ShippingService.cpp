#include "ShippingService.h"
#include <iostream>
#include <iomanip> // For std::setw and std::setprecision

const double ShippingService::FEE_PER_KG = 5.00; // Example fee per kg

ShippingService::ShippingService() : totalShippingFee(0.0) {}

std::vector<std::pair<int, ShippingItem*>> ShippingService::getItems() const {
    return items;
}

void ShippingService::setItems(const std::vector<std::pair<int, ShippingItem*>>& items) {
    this->items = items;

    totalShippingFee = 0.0; // Reset total fee
    for (const auto& itemPair : items) {
        totalShippingFee += itemPair.second->getWeight() * itemPair.first * FEE_PER_KG;
    }
}

double ShippingService::getTotalShippingFee() const {
    return totalShippingFee;
}

void ShippingService::setTotalShippingFee(double totalShippingFee) {
    this->totalShippingFee = totalShippingFee;
}

void ShippingService::display() const {
    if (items.empty()) {
        return; // No items to display
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n=== Shipping Details ===" << std::endl;
    std::cout << std::left << std::setw(20) << "Item"
              << std::setw(12) << "Quantity"
              << std::setw(19) << "Unit Weight (kg)"
              << std::setw(19) << "Total Weight (kg)" << std::endl;
    std::cout << std::string(62, '-') << std::endl;

    double totalWeight = 0.0;

    for (const auto& itemPair : items) {
        int quantity = itemPair.first;
        ShippingItem* item = itemPair.second;
        double unitWeight = item->getWeight();
        double itemTotalWeight = unitWeight * quantity;
        totalWeight += itemTotalWeight;

        std::cout << std::left << std::setw(20) << item->getName()
                  << std::setw(12) << quantity
                  << std::setw(19) << unitWeight
                  << std::setw(19) << itemTotalWeight << std::endl;
    }

    std::cout << std::string(62, '-') << std::endl;
    std::cout << std::left << std::setw(51) << "Total Weight:"
              << totalWeight << " kg" << std::endl;

    std::cout << "\nThe shipping fee per kg is $" << std::fixed << std::setprecision(2)
              << FEE_PER_KG << ", so the total shipping fee = $"
              << getTotalShippingFee() << std::endl;
}