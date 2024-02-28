/*
 Program Name: PreferredCustomer.cpp
 Programmer: Moris Gomez
 Date: Saturday, 02/26/2024
 Version Control: 2.0
 About: Week 2, CSCI 2, HW.
 Description:
 Design a class named PreferredCustomer, which is derived from the 
 customerData class you created in Lab assignment. The
 preferredCustomer class should have the following member variables:
    - purchaseAmount (a double)
    - discountLevel (a double)
*/

#include <iostream>
#include <string>
#include <iomanip> //for money: 2 decimal values after whole #.
using namespace std;

class CustomerData
{
protected:
    int customerNumber;
    bool mailingList;
    
public:
    //default constructor:
    CustomerData()
    {
        customerNumber = 000;
        mailingList = false; //default is false for yes/no on list.
    }
    
    //constructor w/ 2 variables:
    CustomerData(int number, bool list)
    {
        customerNumber = number;
        mailingList = list;
    }
    
    //getters:
    int getCustomerNumber()
    {
        return customerNumber;
    }
    bool getMailList()
    {
        return mailingList;
    }
    
    //setters:
    void setCustomerNumber(int num)
    {
        customerNumber = num;
    }
    void setMailingList(bool lis)
    {
        mailingList = lis;
    }
    
    //other member functions:
    void display()
    {
        cout << endl << "-------your information:--------" << endl;
        cout << "customer number: " << customerNumber << endl;
        cout << "do you wish to be on mailing list: " << mailingList << endl;
    }
}; //close class CustomerData.

//create child class Preffered Customer.
class PreferredCustomer : public CustomerData //child class.
{
private:
    double purchaseAmount;
    double discountLevel;
public:
    //default constructor for subclass w/ inherited members:
    PreferredCustomer()
    {
        purchaseAmount = 0.0;
        discountLevel = 0.0;
        CustomerData(); //brings down default constructor from parent class.
    }
    
    //constructor w/ 4 arg:
    PreferredCustomer(int number, bool list, double purchase, double discount):CustomerData(number, list)
        //inherits non-default constructor from parent class.
    {
        purchaseAmount = purchase;
        discountLevel = discount;
    }
    
    //getters:
    double getPurchase()
    {
        return purchaseAmount;
    }
    double getDiscount()
    {
        return discountLevel;
    }
    //setters:
    void setPurchase(double pur)
    {
        purchaseAmount = pur;
    }
    void setDiscount(double dis)
    {
       discountLevel = dis;
    }
    //other functions:
    void calPrice()
    {
        if(purchaseAmount >= 2000.0)
        {
            discountLevel = 10.0;
            purchaseAmount = purchaseAmount - (discountLevel / 100 * purchaseAmount);
        }
        else if(purchaseAmount >= 1500.0)
        {
            discountLevel = 7.0;
            purchaseAmount = purchaseAmount - (discountLevel / 100 * purchaseAmount);
        }
        else if(purchaseAmount >= 1000.0)
        {
            discountLevel = 6.0;
            purchaseAmount = purchaseAmount - (discountLevel / 100 * purchaseAmount);
        }
        else if(purchaseAmount >= 500.0)
        {
            discountLevel = 5.0;
            purchaseAmount = purchaseAmount - (discountLevel / 100 * purchaseAmount);
        }
    } //close calPrice function.
    void display()
    {
        if (purchaseAmount < 0)
        {
            cout << "ERROR: PURCHASE VALUE CANNOT BE NEGATIVE!" << endl;
        }
        else
        {
            cout << endl << "-------your information:--------" << endl;
            cout << "your customer number is: " << customerNumber << endl;
            cout << "do you wish to be on mailing list: " << mailingList << endl;
            cout << "your discount is: " << fixed << setprecision(1) << discountLevel << "%" << endl;
            cout << "your new purchase total is: $" << fixed << setprecision(2) << purchaseAmount << endl;
        }
    }
}; //close child class PrefferedCustomer.


//Driver: main function.
int main()
{
    //user input for number:
    int custNumInput;
    cout << "input your customer number:";
    cin >> custNumInput;
    
    //user input for bool:
    bool custMaiListInput;
    cout << "do you wish to be on out mailing list (type 1 for yes or 0 for no)?";
    cin >> custMaiListInput;
    
    //user input for purchase:
    double custPurchaseInput;
    cout << "how much was your purchase?";
    cin >> custPurchaseInput;
    
    //user input for discount:
    double custDiscountInput;
    cout << "enter any discounts you are aware of (type 0 if none)?";
    cin >> custDiscountInput;
    
    //create object w/ user inputs:
    PreferredCustomer userOne(custNumInput, custMaiListInput, custPurchaseInput, custDiscountInput);
    userOne.calPrice(); //call func to select discount based on purchase input.
    userOne.display();
    //above: display function from child class. is there a way to pass down that function from parent?
    return 0;
} //close driver: main.
