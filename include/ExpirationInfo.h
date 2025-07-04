#ifndef EXPIRATIONINFO_H
#define EXPIRATIONINFO_H

#include "Date.h"

class ExpirationInfo {
private:
    Date expirationDate;
public:
    explicit ExpirationInfo(Date expirationDate);
    ExpirationInfo(int day, int month, int year);
    Date getExpirationDate() const;
    void setExpirationDate(Date expirationDate);
    bool isExpired() const;
};



#endif //EXPIRATIONINFO_H
