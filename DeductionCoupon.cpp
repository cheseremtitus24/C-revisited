/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the DeductionCoupon class.
*/
#include "DeductionCoupon.h"
#include "Coupon.h"
#include <sstream>

DeductionCoupon::DeductionCoupon(Coupon str1, const string &str, unsigned deduction, unsigned minimum)
        : Coupon(str1) {
	//Set the purchase date expiration date
	expiration_ = str;
	DeductionCoupon::deduction_ = deduction;
	DeductionCoupon::minimumPurchase_ = minimum;
}

double DeductionCoupon::calculateCost(double purchase) const
{
	/*if (purchase >= minimumPurchase_)
	{
		purchase = purchase - DeductionCoupon::deduction_;
		return purchase;
	}*/
	if(purchase < minimumPurchase_)
	{
		return purchase;
	}
    else
    {
        purchase = purchase - DeductionCoupon::deduction_;
        return purchase;
    }
}

string DeductionCoupon::toString() const
{
    /*This function overrides the toString method in the base class. It returns a string including
    information about the invoking DeductionCoupon object. It must include the expiration date, the
    deduction amount, and the minimum purchase requirement. Below please find an example
    display of a DeductionCoupon object. For example, “$5 OFF ABOVE $25, Expired on 03/31” or
    “Expiration date: 11/01, $50 OFF purchase of $500 or mor
   */
    stringstream s;
    //s << setfill('0');

    //s<<"$"<<deduction_<<" OFF ABOVE $"<<minimumPurchase_<<", Expired on "<<expiration_<<endl;
    s<<"Expiration: "<<expiration_<<", $"<<deduction_<<" OFF purchase of $"<<minimumPurchase_<<" or more.";
    return s.str();

}