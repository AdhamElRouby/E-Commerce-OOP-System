#ifndef SHIPPINGINFO_H
#define SHIPPINGINFO_H



class ShippingInfo {
private:
    double weight;
public:
    explicit ShippingInfo(double weight);
    double getWeight() const;
    void setWeight(double weight);
};



#endif //SHIPPINGINFO_H
