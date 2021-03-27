// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #6

#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // testing the default constructor
    Customer b;

    // Checking Paramterized Constructor
    int purchases[] = {3,4,5};
    Customer c = Customer("Punith", purchases, 3);
    cout << c.getCustomerName() << endl;
    cout << "getPurchasesAt(0) = " << c.getPurchasesAt(0) << endl;
    cout << "getPurchasesAt(1) = "<< c.getPurchasesAt(1) << endl;
    cout << "getPurchasesAt(2) = "<< c.getPurchasesAt(2) << endl;
    cout << "getPurchasesAt(9) = "<< c.getPurchasesAt(9) << endl;
    cout << "getPurchasesAt(29) = "<< c.getPurchasesAt(29) << endl;
    cout << "getPurchasesAt(49) = "<< c.getPurchasesAt(49) << endl;
    cout << "getPurchasesAt(-9) = "<< c.getPurchasesAt(-9) << endl;
    cout << "getPurchasesAt(-29) = "<< c.getPurchasesAt(-29) << endl;
    cout << "getPurchasesAt(52) = "<< c.getPurchasesAt(52) << endl;

    // Checking Setter and Getter for Customer Name
    Customer d = Customer();
    d.setCustomerName("John");
    cout << d.getCustomerName() << endl;

    cout << "setPurchasesAt(-10, 1)" << (d.setPurchasesAt(-10, 1) ? " = True" : " = False") << endl;
    cout << "setPurchasesAt(-1, 5)" << (d.setPurchasesAt(-1, 5) ? " = True" : " = False") << endl;
    cout << "setPurchasesAt(52, 7)" << (d.setPurchasesAt(52, 7) ? " = True" : " = False") << endl;
    cout << "setPurchasesAt(60, 9)" << (d.setPurchasesAt(60, 9) ? " = True" : " = False") << endl;

    for (int i=0; i<50; i+=10)
    {
        if (d.setPurchasesAt(i, i))
            cout << "setPurchasesAt(" << i << "," << i << ") = True" << endl;
        else
            cout << "setPurchasesAt(" << i << "," << i << ") = False" << endl;
        cout << d.getPurchasesAt(i) << endl;
    }
    cout << "getPurchasesAt(15) = " << d.getPurchasesAt(15) << endl;
    cout << "getPurchasesAt(-10) = " << d.getPurchasesAt(-10) << endl;
    cout << "getPurchasesAt(-1) = " << d.getPurchasesAt(-1) << endl;
    cout << "getPurchasesAt(52) = " << d.getPurchasesAt(52) << endl;
    cout << "getPurchasesAt(60) = " << d.getPurchasesAt(60) << endl;

    // Checking Getter for Size
    Customer e = Customer();
    cout << e.getSize() << endl;
    
    // Checking Getter for Total Purchase Count
    Customer f = Customer();
    f.setCustomerName("Jimmy");
    for(int i=0; i<f.getSize(); i+=15)
        f.setPurchasesAt(i,i);
    cout << f.getCustomerName() << "'s Total Purchase Count is: " << f.getTotalPurchaseCount() << endl;

    // Checking Getter for Total Purchase Count
    Customer g = Customer();
    g.setCustomerName("Jimmy");
    for(int i=0; i<g.getSize(); i+=10)
        g.setPurchasesAt(i,i);
    cout << g.getCustomerName() << "'s Total Purchase Count is: " << g.getTotalPurchaseCount() << endl;

    // Checking Getter for Number of Unique Purchases
    Customer h = Customer();
    h.setCustomerName("Jimmy");
    for(int i=1; i<h.getSize(); i+=10)
        h.setPurchasesAt(i,i);
    cout << h.getCustomerName() << "'s Number of Unique Purchases is: " << h.getNumUniquePurchases() << endl;
}