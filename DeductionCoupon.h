#ifndef DEDUCTION_COUPON_H
#define DEDUCTION_COUPON_H
#include <string>
#include "Coupon.h"
using namespace std;

class DeductionCoupon : public Coupon {
  private:
    int deduction_;
    int minimumPurchase_;
  public:
    DeductionCoupon(Coupon str1, const string &str, unsigned deduction, unsigned minimum);
    double calculateCost(double purchase) const;
    string toString() const;//implement me later
};

#endif
