#include "customer.h"

Customer::Customer()
{
    ID = "";
    name = "";
    email = "";
    bill = "";
    phone = "";
}

Customer::Customer(string ID, string name, string email, string phone, string bill)
{
    this->ID = ID;
    this->name = name;
    this->email = email;
    this->bill = bill;
    this->phone = phone;
}

Customer::~Customer()
{
}

void Customer::setID(string ID)
{
    this->ID = ID;
}

void Customer::setName(string name)
{
    this->name = name;
}

void Customer::setEmail(string email)
{
    this->email = email;
}

void Customer::setBill(string bill)
{
    this->bill = bill;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}

string Customer::getID()
{
    return ID;
}

string Customer::getName()
{
    return name;
}

string Customer::getEmail()
{
    return email;
}

string Customer::getBill()
{
    return bill;
}

string Customer::getPhone()
{
    return phone;
}

bool isValidEmail(string email)
{
    regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

bool isValidID(string ID)
{
    regex pattern("[0-9]+");
    return regex_match(ID, pattern);
}

Customer Customer::searchCustomer(string token)
{
    string regexToken = ".*" + token + ".*";
    regex pattern(regexToken);
    if (regex_match(ID, pattern) || regex_match(name, pattern) || regex_match(email, pattern) || regex_match(phone, pattern) || regex_match(bill, pattern))
    {
        return *this;
    }
    else
    {
        return Customer();
    }
}
void Customer::printCustomer()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Bill: " << bill << endl;
    cout << endl;
}