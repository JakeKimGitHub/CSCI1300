// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #8

#include "Product.h"
#include "Customer.h"
#include <string>
#include <iostream>

/*
    Parameters:
        * customer name(string)
        * product name(string)
        * array of Customer objects
        * array of Product objects
        * number of customers currently stored
        * number of products currently stored
*/
// return: purhased quantity if both customer and product name are found
//         -3 if the customer or the customer or the product name or both are not found
int getPurchasedQuantity(string name_cust, string name_prod, Customer customers[], Product products[], int num_cust_stored, int num_prod_stored)
{
    int purchased_quantity = 0;
    bool cust_match_found = false;
    bool prod_match_found = false;
    
    for (int i = 0; i < num_cust_stored; i++)
    {
        cust_match_found = false;
        prod_match_found = false;
        
        if (customers[i].getCustomerName() == name_cust) // if there is a match found
        {
            cust_match_found = true;
        }
        for (int j = 0; j < num_prod_stored; j++)
        {
            if (products[j].getName() == name_prod) // if there is a match found
            {
                prod_match_found = true;

                if (cust_match_found == true) // if both the customer and the product match
                {
                    purchased_quantity = customers[i].getPurchasesAt(j);
                    break;
                }
            }    
        }
        if (cust_match_found == true and prod_match_found == true)
        {
            break;
        }
    }
    if (cust_match_found == true and prod_match_found == true)
    {
        return purchased_quantity;
    }
    else
    {
        return -3;
    }
}

// test run
int main()
{
    //Creating 3 products
    Product products[3];
    //Setting product name and price for product 1
    products[0].setName("Garden Gnome");
    products[0].setPrice(2.5);
    //Setting product name and price for product 2
    products[1].setName("Cat Food");
    products[1].setPrice(10);
    //Setting product name and price for product 3
    products[2].setName("Lawn Mower");
    products[2].setPrice(180);

    //Creating 2 customers
    Customer customers[2];
    //Setting customerName and purchases for Customer1
    customers[0].setCustomerName("Customer1");
    customers[0].setPurchasesAt(0,1);
    customers[0].setPurchasesAt(1,4);
    customers[0].setPurchasesAt(2,2);
    //Setting customerName and purchases for Customer1
    customers[1].setCustomerName("Customer2");
    customers[1].setPurchasesAt(0,0);
    customers[1].setPurchasesAt(1,5);
    customers[1].setPurchasesAt(2,2);

    cout << getPurchasedQuantity("Customer1", "Garden Gnome", customers, products, 2, 3) << endl;
    cout << getPurchasedQuantity("A Ghost", "Garden Gnome", customers, products, 2, 3) << endl;
    cout << getPurchasedQuantity("Customer1", "Speed Cola", customers, products, 2, 3) << endl;
    cout << getPurchasedQuantity("A Ghost", "Speed Cola", customers, products, 2, 3) << endl;
}