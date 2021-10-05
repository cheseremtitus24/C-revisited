/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the Coupon class.
*/
#include <string>
#include "Coupon.h"

using namespace std;

//Do not change this function
double Coupon::calculateCost(double purchase) const {
  return 0;
}

//Do not change this function
string Coupon::toString() const {
  return "TBD";
}

Coupon::Coupon(const string& str)
{
	expiration_ = str;
}




////
bool Coupon::hasExpired(const string& str) const
{

    Date current_date;
    current_date = str;
    bool result = (expiration_ < current_date);

    return result;
}
