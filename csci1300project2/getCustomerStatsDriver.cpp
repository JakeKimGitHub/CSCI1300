// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #10

#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <string>

// This function prints the number of unique products that costomer has purchased and the customer's average purchased quantity per purchased product
/*
    Parameters:
        * name of the customer(string)
        * array of Customer objects
        * number of customers currently stored in the customers array
        * number of products currently stored in the products array
    Return / Output:
        * if the customer is found: 
            <name> purchased <number> products
            <name>'s average purchased quantity was <averagePurchaseQuantity>
            return 1
        * if the customer purchased no products:
            <name> has not purchased any products
            return 0
        * if the customerName is not found:
            <name> does not exist
            return -3
*/
int getCustomerStats(string customerName, Customer customers[], int numCustomersStored, int numProductsStored)
{
    bool existing = false;
    double averagePurchaseQuantity = 0;
    int num_prod_purchased = 0;

    for (int i = 0; i < numCustomersStored; i++) // checks if the name exists
    {
        if (customerName == customers[i].getCustomerName())
        {
            averagePurchaseQuantity = customers[i].getTotalPurchaseCount() * 1.0 / customers[i].getNumUniquePurchases() * 1.0;
            existing = true;

            if(customers[i].getNumUniquePurchases() > 0)
            {
                cout << customerName << " purchased " << customers[i].getNumUniquePurchases() << " products" << endl;
                cout << customerName << "'s average purchased quantity was " << fixed << setprecision(2) << averagePurchaseQuantity << endl;

                num_prod_purchased = customers[i].getNumUniquePurchases();
            }
            else
            {
                cout << customerName << " has not purchased any products" << endl;
            }
            break;
        }
    }
    if (existing == true)
    {
        if (num_prod_purchased > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        cout << customerName << " does not exist" << endl;
        return -3;
    }
}

// test run
int main()
{
    //Creating 3 customers
    Customer customers[3];
    //Setting customerName and purchases for Customer1
    customers[0].setCustomerName("Customer1");
    customers[0].setPurchasesAt(0,1);
    customers[0].setPurchasesAt(1,4);
    customers[0].setPurchasesAt(2,2);
    //Setting customerName and purchases for Customer2
    customers[1].setCustomerName("Customer2");
    customers[1].setPurchasesAt(0,0);
    customers[1].setPurchasesAt(1,5);
    customers[1].setPurchasesAt(2,3);
    //Setting customerName and purchases for Customer3
    customers[2].setCustomerName("Customer3");
    customers[2].setPurchasesAt(0,0);
    customers[2].setPurchasesAt(1,0);
    customers[2].setPurchasesAt(2,0);

    getCustomerStats("Customer1", customers, 3, 3);
}