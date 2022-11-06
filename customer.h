#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <deque>
#include <regex>

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

public:
    Customer();                                                                // default constructor
    Customer(string ID, string name, string email, string phone, string bill); // constructor with parameters
    ~Customer();                                                               // destructor
    void setID(string ID);                                                     // set ID
    void setName(string name);                                                 // set name
    void setEmail(string email);                                               // set email
    void setBill(string bill);                                                 // set bill
    void setPhone(string phone);                                               // set phone
    string getID();                                                            // get ID
    string getName();                                                          // get name
    string getEmail();                                                         // get email
    string getBill();                                                          // get bill
    string getPhone();                                                         // get phone
    void printCustomer();
};

bool isValidEmail(string email);                                                          // check if email is valid
bool isValidID(string ID);                                                                // check if ID is valid
void quickSort(vector<Customer> &customers, int left, int, int option, bool isAscending); // quick sort
int partitionAsccending(vector<Customer> &customers, int left, int right, int option);
int partitionDescending(vector<Customer> &customers, int left, int right, int option);
Customer searchCustomer(string token);

#endif // CUSTOMER_H