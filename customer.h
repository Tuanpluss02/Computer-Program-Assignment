#ifndef _CUSTOMER_H_ // include guard
#define _CUSTOMER_H_

#include <iostream>            // cin, cout
#include <filesystem>          // directory_iterator
#include <string>              // string
#include <vector>              // vector
#include <fstream>             // ifstream, ofstream
#include <sstream>             // stringstream
#include <regex>               // regex, regex_match
#include <windows.h>           // HANDLE, GetStdHandle, SetConsoleTextAttribute
#include "CppConsoleTable.hpp" // create table in console

using ConsoleTable = samilton::ConsoleTable; // define alias
namespace fs = std::filesystem;

#define CLEAR_SCREEN system("cls")

// define clear screen
const string FILE_PATH = "E:\\CODE\\Cpp\\Computer-Program-Assignment\\asset\\data\\data.txt";       // define file path
const string CMD = "notepad \"E:\\CODE\\Cpp\\Computer-Program-Assignment\\asset\\data\\data.txt\""; // define command to open file in notepad
const string export_path = "E:\\CODE\\Cpp\\Computer-Program-Assignment\\asset\\exportData\\";       // define data export path
const string import_path = "E:\\CODE\\Cpp\\Computer-Program-Assignment\\asset\\importData\\";       // define data import path
const string encrypt_key = "ehqmrD567";                                                             // admin@123

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
    string getID();                                                    // get ID
    string getName();                                                  // get name
    string getEmail();                                                 // get email
    string getBill();                                                  // get bill
    string getPhone();                                                 // get phone
    string getGender();                                                // get Gender
    string getAddress();                                               // get address
    friend ostream &operator<<(ostream &os, const Customer &customer); // friend function to overload operator <<
};

//============== VALIDATION FUNCTIONS ==============
bool isValidBill(string bill);   // check bill is valid or not
bool isValidEmail(string email); // check if email is valid
bool isValidID(string ID);       // check if ID is valid
bool isValidPhone(string phone); // check if phone is valid
bool isValidName(string name);   // check if name is valid

//============== SORT FUNCTIONS ==============
void quickSort(vector<Customer> &customers, int left, int, int option, bool isAscending); // quick sort
int partitionAsccending(vector<Customer> &customers, int left, int right, int option);    // partition for quick sort to sort in ascending order
int partitionDescending(vector<Customer> &customers, int left, int right, int option);    // partition for quick sort to sort in descending order

//============== SEARCH FUNCTIONS ==============
long searchCustomer(vector<Customer> &customers, string token, int option);          // search customer by ID or free text
vector<Customer> searchCustomerRegex(vector<Customer> customers, string token);      // search customer by regex
long searchCustomerBinarySearch(vector<Customer> customers, size_t ID);              // search customer by binary search
long searchCustomerFibonacciSearch(vector<Customer> customers, size_t ID);           // search customer by linear search
vector<Customer> linearSearch(vector<Customer> customers, string token, int option); // search customer by linear search
//============== MAIN FEATURES ==============
void deleteCustomer(vector<Customer> &customers); // delete customer
void addCustomer(vector<Customer> &customers);    // add customer
void updateCustomer(vector<Customer> &customers); // update customer information

vector<Customer> filterBill(vector<Customer> customers, string bill, int option);                          // filter customer by bill (>=, <=, =)
vector<Customer> filterBill(vector<Customer> customers, unsigned long long start, unsigned long long end); // filter customer by bill between start and end

//============= FORMATTING FUNCTIONS ==============
string formatAddressForPrint(string address);  // change address to fit in table
string formatName(string name);                // uppercase first letter of each word
string formatBill(string bill);                // add comma and currency to bill
unsigned long long stringToNumber(string str); // convert string to number

//============== OTHER FUNCTIONS ==============

string getLastName(string name);                                                        // get last name of customer
Customer setCustomerInformation(vector<Customer> customers, bool isUpdate, long index); // set customer information
void printAllCustomer(vector<Customer> customers);                                      // print all customer
void importData(string filePath, vector<Customer> &customers, bool isReplace);          // import customers from other file
void readData(string fileName, vector<Customer> &customers);
void saveData(string filePath, vector<Customer> customers); // save data to file

#endif // CUSTOMER_H