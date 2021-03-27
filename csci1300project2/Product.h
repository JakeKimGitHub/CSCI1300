// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #1

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
    public:
        Product(); // Default constructor
        Product(string n, double p, string c); // Parameterized constructor
        void setName(string n); // Assigns name the value of the input
        void setPrice(double p); // Assigns price the value of the input
        void setCategory(string c); // Assigns category the value of the input
        string getName() const; // Returns name
        double getPrice() const; // Returns price
        string getCategory() const; // Returns category
    private:
        string name;
        double price;
        string category;
};

#endif