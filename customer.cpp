#include "customer.h"

Customer::Customer()
{
    ID = "";
    name = "";
    email = "";
    bill = "";
    phone = "";
}

Customer::Customer(string ID, string name, string email, string phone, string bill, string gender, string address)
{
    this->ID = ID;
    this->name = name;
    this->email = email;
    this->bill = bill;
    this->phone = phone;
    this->gender = gender;
    this->address = address;
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

void Customer::setGender(string gender)
{
    this->gender = gender;
}

void Customer::setAddress(string address)
{
    this->address = address;
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
string Customer::getGender()
{
    return gender;
}
string Customer::getAddress()
{
    return address;
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

bool isValidPhone(string phone)
{
    regex pattern("(84|0[3|5|7|8|9])+([0-9]{8})");
    return regex_match(phone, pattern);
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
    table[0][5] = "Gender";
    table[0][6] = "Address";
    table[1][0] = ID;
    table[1][1] = name;
    table[1][2] = email;
    table[1][3] = phone;
    table[1][4] = bill;
    table[1][5] = gender;
    table[1][6] = address;
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
    table[0][5] = "Gender";
    table[0][6] = "Address";
    for (size_t i = 0; i < customers.size(); i++)
    {
        table[i + 1][0] = customers[i].getID();
        table[i + 1][1] = customers[i].getName();
        table[i + 1][2] = customers[i].getEmail();
        table[i + 1][3] = customers[i].getPhone();
        table[i + 1][4] = customers[i].getBill();
        table[i + 1][5] = customers[i].getGender();
        table[i + 1][6] = customers[i].getAddress();
    }
    cout << table;
}

void addCustomer(vector<Customer> &customers)
{
    string ID, name, email, phone, bill, gender, address;
    bool validID, validEmail;
    long isExist;
    cout << "Enter ID: ";
    do
    {
        cin >> ID;
        validID = isValidID(ID);
        if (!validID)
        {
            cout << "Invalid ID. Please enter again: ";
            continue;
        }
        isExist = searchCustomerBinarySearch(customers, stringToNumber(ID));
        if (isExist != -1)
        {
            cout << "ID is already exist. Please enter again: ";
            continue;
        }
    } while (!validID || isExist != -1);
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter email: ";
    do
    {
        cin >> email;
        validEmail = isValidEmail(email);
        if (!validEmail)
        {
            cout << "Invalid email. Please enter again: ";
            continue;
        }
    } while (!validEmail);
    cout << "Enter phone: ";
    cin >> phone;
    cout << "Enter bill: ";
    cin >> bill;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    customers.push_back(Customer(ID, name, email, phone, bill, gender, address));
}

void deleteCustomer(vector<Customer> &customers)
{
    string ID;
    bool validID;
    long hasFound;
    cout << "Enter ID: ";
    do
    {
        cin >> ID;
        validID = isValidID(ID);
        if (!validID)
        {
            cout << "Invalid ID. Please enter again: ";
            continue;
        }
        hasFound = searchCustomerBinarySearch(customers, stringToNumber(ID));
        if (hasFound == -1)
        {
            cout << "ID is not exist. Please enter again: ";
        }
    } while (!validID || hasFound == -1);
    customers.erase(customers.begin() + hasFound);
}

void updateCustomer(vector<Customer> &customers, string ID)
{
    string name, email, phone, bill, gender, address;
    bool validID, validEmail;
    long hasFound;
    cout << "Enter ID: ";
    do
    {
        cin >> ID;
        validID = isValidID(ID);
        if (!validID)
        {
            cout << "Invalid ID. Please enter again: ";
            continue;
        }
        hasFound = searchCustomerBinarySearch(customers, stringToNumber(ID));
        if (hasFound == -1)
        {
            cout << "ID is not exist. Please enter again: ";
        }
    } while (!validID || hasFound == -1);
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter email: ";
    do
    {
        cin >> email;
        validEmail = isValidEmail(email);
        if (!validEmail)
        {
            cout << "Invalid email. Please enter again: ";
            continue;
        }
    } while (!validEmail);
    cout << "Enter phone: ";
    cin >> phone;
    cout << "Enter bill: ";
    cin >> bill;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    customers.push_back(Customer(ID, name, email, phone, bill, gender, address));
}

void formatAddress(string &address)
{
    for (auto &i : address)
    {
        if (i == ',' || i == '-')
            i = '\n';
    }
}

void formatName(string &name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (size_t i = 0; i < name.length() - 1; i++)
    {
        if (i == 0 || (name[i] == ' ' && name[i + 1] != ' '))
        {
            name[i] = toupper(name[i]);
        }
    }
}

long searchCustomerFibonacciSearch(vector<Customer> customers, size_t ID)
{
    size_t fiboMMn2 = 0;
    size_t fiboMMn1 = 1;
    size_t fiboM = fiboMMn2 + fiboMMn1;
    while (fiboM < customers.size())
    {
        fiboMMn2 = fiboMMn1;
        fiboMMn1 = fiboM;
        fiboM = fiboMMn2 + fiboMMn1;
    }
    size_t offset = -1;
    while (fiboM > 1)
    {
        size_t i = min(offset + fiboMMn2, customers.size() - 1);

        if (stringToNumber(customers[i].getID()) < ID)
        {
            fiboM = fiboMMn1;
            fiboMMn1 = fiboMMn2;
            fiboMMn2 = fiboM - fiboMMn1;
            offset = i;
        }
        else if (stringToNumber(customers[i].getID()) > ID)
        {
            fiboM = fiboMMn2;
            fiboMMn1 = fiboMMn1 - fiboMMn2;
            fiboMMn2 = fiboM - fiboMMn1;
        }
        else
            return i;
    }
    if (fiboMMn1 && stringToNumber(customers[offset + 1].getID()) == ID)
        return offset + 1;
    return -1;
}