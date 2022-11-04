#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>

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
    Customer();
    Customer(string ID, string name, string email, string phone, string bill);
    ~Customer();
    void setID(string ID);
    void setName(string name);
    void setEmail(string email);
    void setBill(string bill);
    void setPhone(string phone);
    string getID();
    string getName();
    string getEmail();
    string getBill();
    string getPhone();
};

#endif // CUSTOMER_H