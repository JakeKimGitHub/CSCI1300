// CSCI1300 Spring 2021
// Author: Jake Kim
// Partner: Sergio Borrego
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #7

#include "Customer.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// This function splits a string and creates an array of strings with the split pieces
// parameters: string, seperator(char), array(string), size of the array(int)
// return: number of split pieces(int)
int split(string str, char seperator, string array[], unsigned int size_array)
{
    unsigned int num_pieces = 1, starting_point = 0;
    int j = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == seperator)
        {
            array[j] = str.substr(starting_point, i - starting_point);
            
            starting_point = i + 1;  

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

// This function loads the customer purchases by reading a txt file
/* Parameters: 
        *filename(string)
        *array of Customer objects
        *number of customers currently stored in the array(int)
        *capacity of the customers arrays(int)
        *maximum number of columns(int)
*/
/* Return:
        *if numCustomersStored >= custArrSize, return -2
        *if the file cannot be opened, return -1
        *if numCustomersStored < size of customers array, append data to the arrays, return total number of customers
*/
int readPurchases(string filename, Customer customers[], int numCustomersStored, int custArrSize, int maxCol)
{
    if (numCustomersStored >= custArrSize)
    {
        return -2;
    }

    else
    {
        // create file stream objects/variables  
        ifstream file;

        // Associate the file stream object with the file 
        file.open(filename); // Open input file

        string line;

        // check if file opened successfully 
        if (file.fail())
        {
            return -1;
        }

        int i = numCustomersStored; // initialized to numCustomersStored because the data fills up the rest of the array instead of starting over
        string arr[maxCol];
        // Read lines from file
        while (getline(file, line))
        {
            // process each line
            if (line.length() > 1)
            {
                split(line, ',', arr, maxCol);

                customers[i].setCustomerName(arr[0]);
                
                for (int j = 1; j < maxCol; j++)
                {
                    customers[i].setPurchasesAt(j - 1, stoi(arr[j]));
                }
                i++;

                if (i == custArrSize)
                {
                    break;
                }
            }
        }

        // Close file
        file.close();

        return i;
    }
}

// test run
int main()
{
    Customer customers[100];
    cout << readPurchases("purchases.txt", customers, 0, 100, 51) << endl;
}