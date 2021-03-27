// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #6

#include "Customer.h"
#include <string>

using namespace std;

Customer::Customer() // default constructor
{
    customerName = "";
    
    for (int i = 0; i < size; i++)
    {
        purchases[i] = 0;
    }
}
Customer::Customer(string name, int purch[], int sz) // parameterized constructor
{
    customerName = name;

    for (int i = 0; i < sz; i++)
    {
        purchases[i] = purch[i];
    }
    if (sz < size)
    {
        for (int i = sz; i < size; i++)
        {
            purchases[i] = 0;
        }
    }
}
string Customer::getCustomerName() const // returns customerName
{
    return customerName;
}
void Customer::setCustomerName(string name) // assigns customerName the input
{
    customerName = name;
}
int Customer::getPurchasesAt(int index) const // returns the count of purchases stored at the specified index
{
    if (index >= size || index < 0)
    {
        return -1;
    }
    else
    {
        return purchases[index];
    }
}
bool Customer::setPurchasesAt(int index, int value) // sets the count of purchases to value at the specified index
{
    if (index >= 0 && index < size && value > 0)
    {
        purchases[index] = value;

        return true;
    }
    else
    {
        return false;
    }
}
int Customer::getTotalPurchaseCount() // calculates and returns the total number of all products purchased
{
    int total = 0;
    
    for (int i = 0; i < size; i++)
    {
        total += purchases[i];
    }
    return total;
}
int Customer::getNumUniquePurchases() // calculates and returns the number of unique products purchased by the customer
{
    int num_unique = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (purchases[i] != 0)
        {
            num_unique++;
        }
    }
    return num_unique;
}
int Customer::getSize() const // returns size
{
    return size;
}