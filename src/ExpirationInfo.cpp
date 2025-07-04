#include "ExpirationInfo.h"

ExpirationInfo::ExpirationInfo(const Date expirationDate) : expirationDate(expirationDate) {}

ExpirationInfo::ExpirationInfo(const int day, const int month, const int year) :
                                                    expirationDate(day, month, year) {}

Date ExpirationInfo::getExpirationDate() const {
    return expirationDate;
}

void ExpirationInfo::setExpirationDate(const Date expirationDate) {
    this->expirationDate = expirationDate;
}

bool ExpirationInfo::isExpired() const {
    const Date today; // today's date
    return expirationDate.getYear() < today.getYear() ||
           (expirationDate.getYear() == today.getYear() && expirationDate.getMonth() < today.getMonth()) ||
           (expirationDate.getYear() == today.getYear() && expirationDate.getMonth() == today.getMonth() &&
            expirationDate.getDay() < today.getDay());
}

