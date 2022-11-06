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

long searchCustomer(vector<Customer> customers, string token, int option)
{
    if (option == 1)
    {
        return searchCustomerRegex(customers, token);
    }
    else if (option == 2)
    {
        return searchCustomerBinarySearch(customers, stringToNumber(token));
    }
    return -1;
}

void Customer::printCustomer()
{
    ConsoleTable table(1, 1, samilton::Alignment::centre);
    table[0][0] = "ID";
    table[0][1] = "Name";
    table[0][2] = "Email";
    table[0][3] = "Phone";
    table[0][4] = "Bill";
    table[1][0] = ID;
    table[1][1] = name;
    table[1][2] = email;
    table[1][3] = phone;
    table[1][4] = bill;
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
            if (stringToNumber(customers[j].getBill()) < stringToNumber(pivot.getBill()))
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
            if (stringToNumber(customers[j].getBill()) > stringToNumber(pivot.getBill()))
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

unsigned long long stringToNumber(string str)
{
    unsigned long long result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}

long searchCustomerRegex(vector<Customer> customers, string token)
{
    string regexToken = ".*" + token + ".*";
    regex pattern(regexToken);
    for (int i = 0; i < customers.size(); i++)
    {
        if (regex_match(customers[i].getID(), pattern) || regex_match(customers[i].getName(), pattern) || regex_match(customers[i].getEmail(), pattern) || regex_match(customers[i].getPhone(), pattern) || regex_match(customers[i].getBill(), pattern))
        {
            return i;
        }
    }
    return -1;
}

long searchCustomerBinarySearch(vector<Customer> customers, size_t ID)
{
    int left = 0;
    int right = customers.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (stringToNumber(customers[mid].getID()) == ID)
        {
            return mid;
        }
        else if (stringToNumber(customers[mid].getID()) > ID)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

void printAllCustomer(vector<Customer> customers)
{
    ConsoleTable table(1, 1, samilton::Alignment::centre);
    table[0][0] = "ID";
    table[0][1] = "Name";
    table[0][2] = "Email";
    table[0][3] = "Phone";
    table[0][4] = "Bill";
    for (size_t i = 0; i < customers.size(); i++)
    {
        table[i + 1][0] = customers[i].getID();
        table[i + 1][1] = customers[i].getName();
        table[i + 1][2] = customers[i].getEmail();
        table[i + 1][3] = customers[i].getPhone();
        table[i + 1][4] = customers[i].getBill();
    }
    cout << table;
}