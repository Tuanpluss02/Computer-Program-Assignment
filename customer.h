#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include "CppConsoleTable.hpp"

using ConsoleTable = samilton::ConsoleTable;

#define FILE_PATH "E:\\CODE\\Cpp\\Computer-Program-Assignment\\data.txt"
#define CLEAR_SCREEN system("cls")

string CMD = "notepad \"E:\\CODE\\Cpp\\Computer-Program-Assignment\\data.txt\"";

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
    string getID();      // get ID
    string getName();    // get name
    string getEmail();   // get email
    string getBill();    // get bill
    string getPhone();   // get phone
    string getGender();  // get Gender
    string getAddress(); // get address
    void printCustomer();
};

bool isValidBill(string bill);
bool isValidEmail(string email); // check if email is valid
bool isValidID(string ID);       // check if ID is valid
bool isValidPhone(string phone); // check if phone is valid

void quickSort(vector<Customer> &customers, int left, int, int option, bool isAscending); // quick sort
int partitionAsccending(vector<Customer> &customers, int left, int right, int option);
int partitionDescending(vector<Customer> &customers, int left, int right, int option);

long searchCustomer(vector<Customer> &customers, string token, int option);     // search customer by ID or free text
vector<Customer> searchCustomerRegex(vector<Customer> customers, string token); // search customer by regex
long searchCustomerBinarySearch(vector<Customer> customers, size_t ID);         // search customer by binary search
long searchCustomerFibonacciSearch(vector<Customer> customers, size_t ID);      // search customer by linear search

Customer setCustomerInformation(vector<Customer> customers, bool isUpdate, long index); // set customer information
void printAllCustomer(vector<Customer> customers);                                      // print all customer

void deleteCustomer(vector<Customer> &customers);
void addCustomer(vector<Customer> &customers);
void updateCustomer(vector<Customer> &customers);

vector<Customer> filterBill(vector<Customer> customers, string bill, int option);
vector<Customer> filterBill(vector<Customer> customers, unsigned long long start, unsigned long long end);

string formatAddressForPrint(string address);
string formatName(string name);
string formatBill(string bill);
unsigned long long stringToNumber(string str);

void saveData(vector<Customer> customers);
string getLastName(string name);

#endif // CUSTOMER_H