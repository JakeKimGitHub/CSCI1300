// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #2

#include "Product.h"
#include <iostream>
#include <fstream>

// This function splits a string and creates an array of strings with the split pieces
// parameters: string, seperator(char), array(string), size of the array(int)
// return: number of split pieces(int)
int split(string str, char seperator, string array[], unsigned int size_array)
{
    unsigned int num_pieces = 1, starting_point = 0;
    int j = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == seperator && str [i + 1] != ' ')
        {
            array[j] = str.substr(starting_point, i - starting_point);
            
            starting_point = i + 1;  

            num_pieces++;
            j++;
        }
        else if (str[i] == seperator && str[i + 1] == ' ')
        {
            array[j] = str.substr(starting_point, i - starting_point);
            
            starting_point = i + 2;  

            num_pieces++;
            j++;
        }
        if (i == str.length() - 1)
        {
            array[j] = str.substr(starting_point);
        }
    }
    
    if (num_pieces > size_array)
    {
        return -1;
    }
    else if (str == "")
    {
        return 0;
    }
    else
    {
        return num_pieces;
    }
}

// This function will fill an array of Product objects with name, price, and category information
// Parameters: fileName(string), array of Product objects, 
//             number of products currently stored in the array(int), capacity of the array(int)
// Returns total number of products(int)
// When numProductsStored == theproductArrSize, return -2
// When the file is not opened successfully, return -1
// The priority of the return code -2 is higher than -1
/*
   When numProductsStored is smaller than productArrSize,
   keep the existing elements in the array products,
   then read data from the file and add(append) the data to the array
*/
int readProducts(string fileName, Product products[], int numProductsStored, int productArrSize)
{
    if(numProductsStored >= productArrSize)
    {
        return -2;
    }
    else
    {
        // create file stream objects/variables   
        ifstream in_file;
        
        // Associate the file stream object with the file 
        in_file.open(fileName); // Open input file

        string line;

        // check if file opened successfully   
        if (in_file.fail())    
        {
            return -1;
        }   
        
        int total_num_products = numProductsStored;
        int arr_size = 3;
        string arr[arr_size];
        // Read lines from file
        int i = numProductsStored; // initialized to numProductsStored because the data fills up the rest of the array instead of starting over
        while(getline(in_file, line))
        {
            // process each line
            if(line.length() > 0)
            {
                total_num_products++; // total number of products = number of products already stored + number of lines in the file
            
                split(line, ',', arr, arr_size);
                // arr[0] of each line will be name
                // arr[1] will be price
                // arr[2] will be category
                
                {
                    products[i].setName(arr[0]);
                    products[i].setPrice(stod(arr[1]));
                    products[i].setCategory(arr[2]);
                    
                }
                i++;

                if(i == productArrSize)
                {
                    break;
                }
            }
        }

        // Close files   
        in_file.close();

        return total_num_products;
    }
}

// test run
int main()
{
    Product products[10] = {};
    products[0].setName("name1");
    products[0].setPrice(20.5);
    products[0].setCategory("category1");
    int ret = readProducts("sample_products.txt", products, 1, 10);
    cout << ret << endl;
    cout << products[0].getName() << endl;
    cout << products[1].getName() << endl;
    cout << products[2].getName() << endl;
    cout << products[3].getName() << endl;
}