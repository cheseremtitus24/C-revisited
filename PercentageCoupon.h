#ifndef PERCENTAGE_COUPON_H
#define PERCENTAGE_COUPON_H
#include <string>
#include "Coupon.h"
using namespace std;

class PercentageCoupon : public Coupon {
  private:
    unsigned discountPercent_;
  public:
    PercentageCoupon(const string &str1, const string &str, unsigned percent);
    double calculateCost(double purchase) const;
    string toString() const;//implement me later
};

#endif
