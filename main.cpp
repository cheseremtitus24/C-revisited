/*
  Visit https://bit.ly/2WlhC0A for detailed description of the project.
  You are encouraged to focus on implementing and testing the member functions before processing the "transactions.txt" file.
*/
#include <iostream>
#include "Date.h"
#include "Coupon.h"
#include "DeductionCoupon.h"
#include "PercentageCoupon.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <typeinfo>


int main() {

    Date dobj;
    Date pi_day, april_fool, independence_day;
	cout<<"============================================="<<endl;
    cout<<"Part 1"<<endl;
    cout<<"Testing Input " <<endl;

    pi_day = "03/14";
    april_fool = "04/01";
    independence_day = "07/04";
    cout.setf(ios :: boolalpha);
    cout << "Pi Day < April Fool Day: " << (pi_day < april_fool) << endl;
    cout << '\n';
    cout << "April Fool day < Independence Day: " << (april_fool < independence_day) << endl;
    cout << '\n';
    cout << "April Fool Day < Pi Day: " << (april_fool < pi_day) << endl;
    cout << '\n';
    cout << "April Fool Day <  April Fool Day: " << (april_fool < april_fool) << endl;


    //(dobj = "12/31");
    // << // Friend Function 
	cout<<"============================================="<<endl;
    cout<<"Part 2"<<endl;
    cout<<"\n\n Testing string to date conversion"<<endl;
    cout<<"April fools day is which day of the year:" << april_fool<<endl;

	cout<<"============================================="<<endl;
    cout<<"Part 3 Coupon Class" <<endl;
    cout<<"Beginning of the Coupon Class implementation "<<endl;

    ///// Coupon class
    Coupon coupon_obj("11/30");
    coupon_obj.toString();
    cout<<"compare  '11/30' < '10/21' returns the following: "<<endl;
    cout<<coupon_obj.hasExpired("10/21");
    cout<<"\ninverse compare  '10/21' < '11/30' returns the following: "<<endl;
    Coupon coupon_obj2("10/21");
    cout<<coupon_obj2.hasExpired("11/31");


    cout<<"\n\n============================================="<<endl;
    cout<<"Part 4 DeductionCoupon Class\n\n" <<endl;

    ///// DeductionCoupon class

    //set coupon expiration date as october 21
    Coupon deductobj("10/21");
    cout<<"Coupon deductobj(\"10/21\"); // instantiating Coupon class Object that is to be passed as a parameter in the deductclass constructor "<<endl;
    DeductionCoupon deobj(deductobj,"10/20",5,50);
    cout<<"DeductionCoupon deobj(deductobj,\"10/20\",5,50); // parameters: //coupon obj //exipiration date // deduction/discount amount// discount available for items above this amount"<<endl;
    cout<<"cout<<deobj.toString();"<<endl;
    cout<<deobj.toString();

    //do calculate cost
    cout<<"Item of $60 is purchased at a cost of : $"<<deobj.calculateCost(60)<<endl;
    cout<<"Item of $50 is purchased at a cost of : $"<<deobj.calculateCost(50)<<endl;
    cout<<"No Discount - Item of $40 is purchased at a cost of : $"<<deobj.calculateCost(40)<<endl;

    cout<<"\n\n============================================="<<endl;
    cout<<"Part 5 PercentageCoupon Class" <<endl;

    ///// PercentageCoupon class
    basic_string<char, char_traits<char>, allocator<char>> percentobj("10/21");
    PercentageCoupon peobj(percentobj,"10/22",10);
    cout<<peobj.toString();
    cout<<"Selling price= $100 "<<"after a 10% discount Buying Price= $"<<peobj.calculateCost(100)<<endl;
    Date purchase_date;
    purchase_date = "10/24";
    cout<< "Making a purchase on "<< purchase_date<< " has my coupon expired : ";
    cout<<peobj.hasExpired("10/24")<<endl;
    purchase_date = "10/14";
    cout<< "Making a purchase on "<< purchase_date<< " has my coupon expired : ";
    cout<<peobj.hasExpired("10/14");

    cout<<"\n\n============================================="<<endl;
    cout<<"Part 6 processing values from a file from Class" <<endl;

//============================= Reading First Line of File ==========================

    ifstream file;

    file.open("transactions.txt");
    string line;

    if (!file) //checks to see if file opens properly
    {
        cerr << "Error: Could not find the requested file.";
    }
    else
    {

        if (getline(file, line)) cout << ""; // Get and print the line.
        file.close(); // Remember to close the file.
    }
//stringstream ss( "1,1,1,1, or something else ,1,1,1,0" );
    stringstream ss( line);
    vector<string> result;
    string name,descr;
    string arr[2];
    int k =0;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, ',' );
        //cout<<substr;
        arr[k] = substr;
        k++;
        //result.push_back( substr );

    }
    cout <<"\nCaptured purchase month/day String from file :"<< arr[0]<<endl;
    Date items_purchase_date;
    items_purchase_date = arr[0];
    cout<<"Processed purchasing  date is :  "<<items_purchase_date<<endl;
    //items_purchase_date = "10/15";


//////////////  =============== Reading consecutive file lines =================

    //Read other file lines and call respective functions
    fstream newfile;
    newfile.open("transactions.txt",ios::in); //open a file to perform read operation using file
    int i = 0; //helper to skip the first line

    if (newfile.is_open()){   //checking whether the file is open
        //Pretty print the header

        int seed_row_counter = 1;

        cout<<"\nTRANS\t TOTAL\t\t\t\t COUPON\t\t\t\t\t\t\t STATUS\t\t\t\t FINAL COST"<<endl;

        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            if (i == 0)
            {
                //skip first line by doing nothing
                i++;
                continue;
            }
            else
            {

                //cout << tp << "\n"; //print the data of the string
                //parse for key words in order to call the respective functions
                // Used to split string around spaces.
//                cout<<"line "<<i<<" sentence is "<<tp<<endl;
                i++;
                istringstream ss(tp);

                string word; // for storing each word

                // Traverse through all words
                // while loop till we get
                // strings to store in string word
                string arr[5];
                int j = 0;
                while (ss >> word)
                {
                    //store seperated words to an arr
//                    cout<<"\n";
                    arr[j] = word;
//                    cout<<word<<endl;

                    j++;
                }
                // print the read word
//                cout << word << "\n";
                //todo: read 2 more indexes from the array
                string selling_price = arr[0];
                double sell_price =std::stod(selling_price);
                // process percentage coupon type
                string coupon_type = arr[1];
                //todo:first let's check if coupon is active therefore, not expired
                Date expiration_date;
                expiration_date = arr[2];
                bool has_expired = expiration_date < items_purchase_date  ;
                //cout<<"has the item expired: "<< has_expired<<endl;
                // if item has expired update the Status Column with index 2
                string expiry = arr[2];
                if (arr[1] == "percentage")
                {

                    string percentage_discount = arr[3];
                    //remove empty spaces
                    std::string strrr = percentage_discount;
                    strrr.erase(remove(strrr.begin(), strrr.end(), ' '), strrr.end());
//                        std::cout << strrr; // Output Hello
                    string strr = strrr;
//                    cout<<"Read in percentage discount as cleaned string is "<<strr<<endl;

                    // Convert string to int

                    //Convert string to doubleoo
                    unsigned pd = std::stoi(strr);
                    if (has_expired)
                    {
                        arr[2] = "Expired";
                        // Update  Final Cost

                        basic_string<char, char_traits<char>, allocator<char>> percobj(expiry);
                        PercentageCoupon peobj1(percobj,expiry,pd);
                        arr[1] = peobj1.toString();
                        arr[3] = selling_price;

                    }
                    else
                    {
                        arr[2] = "In effect";

                        basic_string<char, char_traits<char>, allocator<char>> percobj(expiry);
                        PercentageCoupon peobj2(percobj,expiry,pd);
                        arr[1] = peobj2.toString();
//                        cout<<"Selling price= $100 "<<"after a 10% discount Buying Price= $"<<peobj.calculateCost(sp)<<endl;
//                        cout<<sell_price<<endl;
//                        cout<<pd<<endl;
                        double final_price = peobj2.calculateCost(sell_price);
//                        cout<<final_price;
                        std::ostringstream strs;
                        strs << final_price;
                        std::string buying_price = strs.str();

                        // Update the selling price after percentage discount awarded
                        arr[3]  = buying_price; //should be a string since we are accessing it from a string array





//                        arr[0] = "changed";
                    }


                    cout<<seed_row_counter;
                    seed_row_counter++;

                    for (int k = 0; k<4;k++)
                    {
                        cout<<"\t\t"<<arr[k]<<" ";
                    }

//                    cout<<"\n"<<endl;

                   // accobj.getFollowing(arr[1]);



                }
                else if (arr[1] == "deduction")
                {
                    //first check if coupon is still valid else skip offer of discount
                    // capture the date first

                    //preprocess the strings to be unsigned int
                    string deduction_string = arr[3];
                    string min_purchase_string = arr[4];

                    //remove empty spaces
                    std::string strrr = deduction_string;
                    std::string strrr1 = min_purchase_string;

                    strrr.erase(remove(strrr.begin(), strrr.end(), ' '), strrr.end());
                    strrr1.erase(remove(strrr1.begin(), strrr1.end(), ' '), strrr1.end());
//                        std::cout << strrr; // Output Hello
                    string strr = strrr;
                    string strr1 = strrr1;

                    // Convert cleaned string to unsigned int

                    //Convert string to doubleoo
                    unsigned deduction = std::stoi(strr);
                    unsigned min_purchase = std::stoi(strr1);


                    if (has_expired)
                    {

                        //skip deductions
                        //selling price remains and so does the final cost
                        Coupon deductobj(expiry);
                        DeductionCoupon peobj22(deductobj,expiry,deduction,min_purchase);
//                        cout<<"DeductionCoupon deobj(deductobj,\"10/20\",5,50); // parameters: //coupon obj //exipiration date // deduction/discount amount// discount available for items above this amount"<<endl;
//                        cout<<"cout<<deobj.toString();"<<endl;
                        arr[1] = peobj22.toString();
                        arr[2] = "Expired";
//                        basic_string<char, char_traits<char>, allocator<char>> percobj(expiry);
//                        DeductionCoupon peobj3(percobj,expiry,pd);
//                        arr[1] = peobj2.toString();
                        arr[3] = arr[0];
                    }
                    else
                    {
                        //skip deductions
                        //selling price remains and so does the final cost
                        Coupon deductobj1(expiry);
                        DeductionCoupon peobj23(deductobj1,expiry,deduction,min_purchase);
//                        cout<<"DeductionCoupon deobj(deductobj,\"10/20\",5,50); // parameters: //coupon obj //exipiration date // deduction/discount amount// discount available for items above this amount"<<endl;
//                        cout<<"cout<<deobj.toString();"<<endl;
                        arr[1] = peobj23.toString();
                        arr[2] = "In effect";
                        //perform deductions and update final Cost
                        // Final step is to ensure that sell_price is above minimum purchase else do nothing
                        if (sell_price >= min_purchase)
                        {
                            double final_price = peobj23.calculateCost(sell_price);
                            //convert double to string for saving to string array
                            std::ostringstream strs1;
                            strs1 << final_price;
                            std::string buying_price_string = strs1.str();
                            arr[3] = buying_price_string;
                        }
                        else
                        {
                            arr[3] = arr[0];

                        }



                    }

                    cout<<seed_row_counter;
                    seed_row_counter++;

                    for (int l = 0; l<4;l++)
                    {
                        cout<<"\t\t"<<arr[l];
                    }

                    //Save the values to respective variable names
                    string selling_price = arr[0];
                    string coupon_type = arr[1];
                    string expiration_date = arr[2];
                    string deduction_amount = arr[3];
                    string minimum_purchase = arr[4];
                    //accobj.unFollow(arr[1]);
                }
//                cout<<"\n"<<endl;

            }
                cout<<"\n"<<endl;
        }
        newfile.close();
    }





}
