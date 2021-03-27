// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #1

#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

int main() 
{

    // testing the parameterized constructor
    Product iPhone("Iphone", 799.99, "Electronics");

    // testing the default constructor
    Product macBook;
    
    // testing the setName() member function (MF)
    macBook.setName("MacBook");
    
    // testing the setPrice MF
    macBook.setPrice(1299.99);
    
    // testing the setCategory MF
    macBook.setCategory("Electronics");
    
    // testing the getName() MF
    cout << macBook.getName() << endl;
    // testing the getPrice() MF
    cout << macBook.getPrice() << endl;
    // testing the getCategory() MF
    cout << macBook.getCategory() << endl;


    return 0;
}
