// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #9

#include "Customer.h"
#include <string>
#include <iostream>

// This function adds a customer with the values of all purchases at 0 to the customers array
/*
    Parameters:
        * name of the customer to be added(string)
        * array of Customer objects
        * number of products(int)
        * number of customers currently stored(int)
        * capacity of the customers array(int)
    Return:
        * if numCustomersStored >= customersArrSize, return -2
        * if a customer with the same name already exists, return -1
        * if name is empty, return -1
        * add the customer object to the array and return the new total number of customers in the array
*/
int addCustomer(string customerName, Customer customers[], int numProducts, int numCustomersStored, int customersArrSize)
{
    bool existing = false;
    
    if (numCustomersStored >= customersArrSize)
    {
        return -2;
    }
    else if (customerName.length() == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < numCustomersStored; i++) // checks if the name already exists
        {
            if (customerName == customers[i].getCustomerName())
            {
                existing = true;
                break;
            }
        }
        if (existing == true)
        {
            return -1;
        }
        else
        {
            customers[numCustomersStored].setCustomerName(customerName);
            for (int i = 0; i < numProducts; i++)
            {
                customers[numCustomersStored].setPurchasesAt(i, 0);
            }
            return numCustomersStored + 1; // One customer got added
        }
    }
}

// test case
int main()
{        
    Customer customers[10];
    int customersArrSize = 10;
    int numProducts  = 5;

    customers[0].setCustomerName("Knuth");
    customers[1].setCustomerName("Richie");

    for(int i=0; i<5; i++) 
    {
        customers[0].setPurchasesAt(i, i);
        customers[1].setPurchasesAt(i, 5-i);
    }

    int numCustomersStored = 2;

    int val = addCustomer("Ninja", customers, numProducts, numCustomersStored, customersArrSize);

    cout << val << endl;
}