// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #6

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer
{
    public:
        Customer(); // default constructor
        Customer(string, int [], int); // parameterized constructor
        string getCustomerName() const; // returns customerName
        void setCustomerName(string); // assigns customerName the input
        int getPurchasesAt(int index) const; // returns the count of purchases stored at the specified index
        bool setPurchasesAt(int index, int value); // sets the count of purchases to value at the specified index
        int getTotalPurchaseCount(); // calculates and returns the total number of all products purchased
        int getNumUniquePurchases(); // calculates and returns the number of unique products purchased by the customer
        int getSize() const; // returns size
    private:
        string customerName;
        static const int size = 50;
        int purchases[size];
};

#endif