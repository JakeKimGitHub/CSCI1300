// CSCI1300 Spring 2021
// Author: Jake Kim
// Recitation: 117 – Elizabeth Spaulding and Ash Duy
// Project 2 - Problem #11

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    public:
        Customer(); // default constructor
        Customer(string, int [], int); // parameterized constructor
        string getCustomerName() const; // returns customerName
        void setCustomerName(string); // assigns customerName the input
        int getPurchasesAt(int index) const; // returns the count of purchases stored at the specified index
        bool setPurchasesAt(int index, int value); // sets the count of purchases to value at the specified index
        int getTotalPurchaseCount(); // calculates and returns the total number of all products purchased
        int getNumUniquePurchases(); // calculates and returns the number of unique products purchased by the customer
        int getSize() const; // returns size
    private:
        string customerName;
        static const int size = 50;
        int purchases[size];
};

#endif

// Customer.cpp
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

// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

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

// Product.cpp
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

// This function displays the contents of your online store
// Parameters: array of Product objects, number of products in the array(int)
// If the number of products is 0 or less than 0, print "No products are stored"
// Otherwise, print “Here is a list of products” and then each product in a new line
// cout << products[i].getName() << " costs ";
// cout << products[i].getPrice() << endl;
void printAllProducts(Product products[], int num_products)
{
    if(num_products > 0)
    {
        cout << "Here is a list of products" << endl;
        for(int i = 0; i < num_products; i++)
        {    
            cout << products[i].getName() << " costs ";
            cout << products[i].getPrice() << endl;
        }
    }
    else
    {
        cout << "No products are stored" << endl;
    }
}

// This function counts all products of a particular category
// Parameters: category(string), array of Product objects, number of products in the array(int)
// Return: count of products under the category / 0 if no products match
int countCategory(string category, Product products[], int numProductsStored)
{
    int num_match_category = 0;

    for(int i = 0; i < numProductsStored; i++)
    {    
        if (products[i].getCategory() == category)
        {
            num_match_category++;
        }
    }

    return num_match_category;
}

// This function prints all products of a particular category where the product name includes the given search word
// Parameters: category(string), word to be used for filtering(string), array of product objects, number of products in the array(int)
// Return: count of products that match filter criteria / 0 if no products match
/* Output format:
            -If no products match, print "No matching products found."
            -Otherwise, print "Here is a list of products that match this category-search word pair:"
                        cout << products[i].getName() << endl;
*/
int searchNameCategory(string category, string searchWord, Product products[], int numProductsStored)
{
    int num_match = 0;

    for (int i = 0; i < numProductsStored; i++)
    {
        if (products[i].getCategory() == category)
        {
            for (int j = 0; j < products[i].getName().length(); j++)
            {
                if (searchWord == products[i].getName().substr( j, searchWord.length() ))  // when the substring is found print the name of the product
                {
                    num_match++;
                }
            }
        }
    }

    if (num_match == 0)
    {
        cout << "No matching products found." << endl;

        return num_match;
    }
    else
    {
        cout << "Here is a list of products that match this category-search word pair:" << endl;
        for (int i = 0; i < numProductsStored; i++)
        {
            if (products[i].getCategory() == category)
            {
                for (int j = 0; j < products[i].getName().length(); j++)
                {
                    if (searchWord == products[i].getName().substr( j, searchWord.length() ))  // when the substring is found print the name of the product
                    {
                        cout << products[i].getName() << endl;
                    }
                }
            }
        }
        
        return num_match;
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

/*
    menu:
        1. Read products from file
        2. Print all products
        3. Product-count by category
        4. Filter products by category, search word
        5. Add customer
        6. Read purchases from file
        7. Get product purchases by a customer
        8. Get customer statistics
        9. Quit
*/
int main()
{
    int choice = 0;
    string filename;
    string category;
    string search_word;
    string cust_name;
    int num = 0;
    int size = 50;
    int cust_size = 100;
    int num_customer = 0;
    int ret_add_customer = 0;
    Product products[size];
    Customer customers[cust_size];
    int ret = 0;

    while (choice != 9)
    {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read products from file" << endl;
        cout << "2. Print all products" << endl;
        cout << "3. Product-count by category" << endl;
        cout << "4. Filter products by category, search word" << endl;
        cout << "5. Add customer" << endl;
        cout << "6. Read purchases" << endl;
        cout << "7. Get purchased quantity" << endl;
        cout << "8. Get customer statistics" << endl;
        cout << "9. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1: // Read products from file
                cout << "Enter a product file name:" << endl;
                cin >> filename;
                
                ret = readProducts(filename, products, num, size);
                
                if(ret == -1)
                {
                    cout << "No products saved to the database." << endl;
                }
                else if(ret == -2)
                {
                    ret = 50; // when it is full, the first 50 stays
                    cout << "Database is already full. No products were added." << endl;
                }
                else if(ret == size)
                {
                    cout << "Database is full. Some products may have not been added." << endl;
                }
                else
                {
                    num = ret;
                    cout << "Total products in the database: " << ret << endl;
                }
                break;
                size = num;
            
            case 2: // Print all products
                printAllProducts(products, num);
                break;
            
            case 3: // Product-count by category
                cout << "Enter the category:" << endl;
                cin >> category;
                cout << "Total " << category << " products in the database: " << countCategory(category, products, num) << endl;
                break;

            case 4: // Filter products by category, search word
                cout << "Enter the category:" << endl;
                cin >> category;
                cout << "Enter search word:" << endl;
                cin >> search_word;
                cout << "Number of products found for this filter: " << endl << searchNameCategory(category, search_word, products, num) << endl;
                break;

            case 5: // Add customer
                cout << "Enter a customer name:" << endl;
                cin >> cust_name;
                addCustomer(cust_name, customers, size, num_customer, cust_size);

                if (ret_add_customer == -2)
                {
                   cout << "Database is already full. Customer cannot be added." << endl;
                }
                else if (ret_add_customer == -1)
                {
                    cout << "Customer already exists or the customerName is empty." << endl;
                }
                else
                {
                    cout << "Welcome, " << cust_name << "!" << endl;
                }
                break;
                
            case 6: // Read purchases
                cout << "Enter the purchases file name:" << endl;
                cin >> filename;
                readPurchases(filename, customers, num_customer, cust_size, size);
            case 9:
                cout << "Good bye!" << endl;
                break;
            
            default:
                cout << "Invalid input." << endl;
                break;

        }
    }
}