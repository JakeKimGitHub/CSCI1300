// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #1

#include <string>
#include "Product.h"

using namespace std;

Product::Product() // Default constructor
{
    name = "";
    price = 0;
    category = "";
}
Product::Product(string n, double p, string c) // Parameterized constructor
{
    name = n;
    price = p;
    category = c;
}
void Product::setName(string n) // Assigns name the value of the input
{
    name = n;
}
void Product::setPrice(double p) // Assigns price the value of the input
{
    price = p;
}
void Product::setCategory(string c) // Assigns category the value of the input
{
    category = c;
}
string Product::getName() const // Returns name
{
    return name;
}
double Product::getPrice() const // Returns price
{
    return price;
}
string Product::getCategory() const // Returns category
{
    return category;
}