/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the PercentageCoupon class.
*/
#include <sstream>
#include "PercentageCoupon.h"
PercentageCoupon::PercentageCoupon(const string &str1, const string &str, unsigned percent) : Coupon(str1) {
//	cout<<"Inititial Expiration DAte "<<expiration_<<end;
    expiration_ = str;
	PercentageCoupon::discountPercent_ = percent;
}

double PercentageCoupon::calculateCost(double purchase) const
{
	purchase = (purchase * (100-discountPercent_))/100;
//    cout<<"Gotten purchase price is "<<purchase<<endl;
//    cout<<"Gotten Discount % is "<< discountPercent_<<endl;
	return purchase;
}
string PercentageCoupon::toString() const
{
    /*This function overrides the toString method in the base class. It returns a string including
    information about the invoking DeductionCoupon object. It must include the expiration date, the
    deduction amount, and the minimum purchase requirement. Below please find an example
    display of a PercentageCoupon object. For example, “15% OFF, Expired on 03/31” or
    “Expiration date: 11/01, 25% OFF”.
     */
    stringstream s;
    //s << setfill('0');
    // Check if coupon has expired
//    Date buy_date()

    s <<  "Expiration: "<<expiration_ <<", "<< discountPercent_<<"% OFF. ";//deduction_<<" "<< minimumPurchase_ ;
    //s <<  discountPercent_<<"% OFF, "<<"Expired on "<<expiration_<<endl;//deduction_<<" "<< minimumPurchase_ ;
    return s.str();
}




