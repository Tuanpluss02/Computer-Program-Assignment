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

Customer searchCustomer(vector<Customer> customers, string token)
{
    string regexToken = ".*" + token + ".*";
    regex pattern(regexToken);
    for (int i = 0; i < customers.size(); i++)
    {
        if (regex_match(customers[i].getID(), pattern) || regex_match(customers[i].getName(), pattern) || regex_match(customers[i].getEmail(), pattern) || regex_match(customers[i].getPhone(), pattern) || regex_match(customers[i].getBill(), pattern))
        {
            return customers[i];
        }
    }
    throw "Customer not found";
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

void quickSort(vector<Customer> &customers, int left, int right, int option, bool isAscending)
{
    if (left < right)
    {
        int pivot = isAscending ? partitionAsccending(customers, left, right, option) : partitionDescending(customers, left, right, option);
        quickSort(customers, left, pivot - 1, option, isAscending);
        quickSort(customers, pivot + 1, right, option, isAscending);
    }
}

int partitionAsccending(vector<Customer> &customers, int left, int right, int option)
{
    Customer pivot = customers[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        switch (option)
        {
        case 1:
            if (customers[j].getID() < pivot.getID())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 2:
            if (customers[j].getName() < pivot.getName())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 3:
            if (customers[j].getEmail() < pivot.getEmail())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 4:
            if (customers[j].getPhone() < pivot.getPhone())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 5:
            if (customers[j].getBill() < pivot.getBill())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        }
    }
    swap(customers[i + 1], customers[right]);
    return i + 1;
}

int partitionDescending(vector<Customer> &customers, int left, int right, int option)
{
    Customer pivot = customers[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        switch (option)
        {
        case 1:
            if (customers[j].getID() > pivot.getID())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 2:
            if (customers[j].getName() > pivot.getName())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 3:
            if (customers[j].getEmail() > pivot.getEmail())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 4:
            if (customers[j].getPhone() > pivot.getPhone())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 5:
            if (customers[j].getBill() > pivot.getBill())
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        }
    }
    swap(customers[i + 1], customers[right]);
    return i + 1;
}
