#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <deque>
#include <regex>
#include "CppConsoleTable.hpp"

using ConsoleTable = samilton::ConsoleTable;

#define FILE_PATH "E:\\CODE\\Cpp\\Computer-Program-Assignment\\data.txt"

using namespace std;

class Customer
{
private:
    string ID;
    string name;
    string email;
    string bill;
    string phone;
    string gender;
    string address;

public:
    Customer();                                                                                               // default constructor
    Customer(string ID, string name, string email, string phone, string bill, string gender, string address); // constructor with parameters
    ~Customer();                                                                                              // destructor
    void setID(string ID);                                                                                    // set ID
    void setName(string name);                                                                                // set name
    void setEmail(string email);                                                                              // set email
    void setBill(string bill);                                                                                // set bill
    void setPhone(string phone);                                                                              // set phone
    void setGender(string gender);
    void setAddress(string address);
    string getID();    // get ID
    string getName();  // get name
    string getEmail(); // get email
    string getBill();  // get bill
    string getPhone(); // get phone
    string getGender();
    string getAddress();
    void printCustomer();
};

unsigned long long stringToNumber(string str);
bool isValidEmail(string email);                                                          // check if email is valid
bool isValidID(string ID);                                                                // check if ID is valid
bool isValidPhone(string phone);                                                          // check if phone is valid
void quickSort(vector<Customer> &customers, int left, int, int option, bool isAscending); // quick sort
int partitionAsccending(vector<Customer> &customers, int left, int right, int option);
int partitionDescending(vector<Customer> &customers, int left, int right, int option);
long searchCustomer(vector<Customer> customers, string token, int option); // search customer by ID or free text
long searchCustomerRegex(vector<Customer> customers, string token);        // search customer by regex
long searchCustomerBinarySearch(vector<Customer> customers, size_t ID);    // search customer by binary search
long searchCustomerFibonacciSearch(vector<Customer> customers, size_t ID); // search customer by linear search
void printAllCustomer(vector<Customer> customers);
void formatAddress(string &address);
void deleteCustomer(vector<Customer> &customers, string ID);
void addCustomer(vector<Customer> &customers, Customer customer);
void updateCustomer(vector<Customer> &customers, string ID);

#endif // CUSTOMER_H