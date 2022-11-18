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

bool isValidBill(string bill)
{
    regex pattern("^[0-9]{1,}$");
    /* ^ : start of string
    [0-9] : any digit
    {1,} : at least 1 digit
    $ : end of string
     */
    return regex_match(bill, pattern);
}

bool isValidEmail(string email)
{
    regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    /*
    \\w+ : at least 1 word character
    (\\.|_)? : . or _ or nothing
    \\w* : 0 or more word character
    @ : need @ after username
    \\w+ : at least 1 word character
    (\\.(\\w+))+ : . and at least 1 word character
    */
    return regex_match(email, pattern);
}

bool isValidID(string ID)
{
    regex pattern("[0-9]+");
    /*
    [0-9]+ : at least 1 digit
    */
    return regex_match(ID, pattern);
}

bool isValidPhone(string phone)
{
    regex pattern("(84|0[3|5|7|8|9])+([0-9]{8})");
    /*
    (84|0[3|5|7|8|9])+ : 84 or 0 and 3 or 5 or 7 or 8 or 9
    ([0-9]{8}) : 8 digits
    */
    return regex_match(phone, pattern);
}

bool isValidName(string name)
{
    // must have name and surname
    regex pattern("([A-Z][a-z]+\\s[A-Z][a-z]+)");
    /*
    ([A-Z][a-z]+\\s[A-Z][a-z]+) : 1 word character and 1 space and 1 word character
    */
    return regex_match(name, pattern);
}

long searchCustomer(vector<Customer> &customers, string token, int option)
{
    if (option == 1)
    {
        quickSort(customers, 0, customers.size() - 1, 1, true);
        return searchCustomerBinarySearch(customers, stringToNumber(token));
    }
    else if (option == 2)
    {
        quickSort(customers, 0, customers.size() - 1, 1, true);
        return searchCustomerFibonacciSearch(customers, stringToNumber(token));
    }
    return -1;
}

ostream &operator<<(ostream &os, const Customer &customer)
{
    ConsoleTable table(1, 1, samilton::Alignment::centre);
    table[0][0] = "ID";
    table[0][1] = "Name";
    table[0][2] = "Email";
    table[0][3] = "Phone";
    table[0][4] = "Bill";
    table[0][5] = "Gender";
    table[0][6] = "Address";
    table[1][0] = customer.ID;
    table[1][1] = customer.name;
    table[1][2] = customer.email;
    table[1][3] = customer.phone;
    table[1][4] = customer.bill;
    table[1][5] = customer.gender;
    table[1][6] = customer.address;
    os << setw(20) << table;
    return os;
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
            if (stringToNumber(customers[j].getID()) < stringToNumber(pivot.getID()))
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 2:
            if (getLastName(customers[j].getName()) < getLastName(pivot.getName()))
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 3:
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
            if (stringToNumber(customers[j].getID()) > stringToNumber(pivot.getID()))
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 2:
            if (getLastName(customers[j].getName()) > getLastName(pivot.getName()))
            {
                i++;
                swap(customers[i], customers[j]);
            }
            break;
        case 3:
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

vector<Customer> searchCustomerRegex(vector<Customer> customers, string token)
{
    regex pattern(".*" + token + ".*", regex_constants::icase);
    vector<Customer> result;
    for (size_t i = 0; i < customers.size(); i++)
    {
        if (regex_match(customers[i].getID(), pattern) || regex_match(customers[i].getName(), pattern) || regex_match(customers[i].getEmail(), pattern) || regex_match(customers[i].getPhone(), pattern) || regex_match(customers[i].getBill(), pattern) || regex_match(customers[i].getGender(), pattern) || regex_match(customers[i].getAddress(), pattern))
        {
            result.push_back(customers[i]);
        }
    }
    return result;
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
    cout << setw(10) << table;
}

void addCustomer(vector<Customer> &customers)
{
    Customer customer = setCustomerInformation(customers, false, 0);
    customers.push_back(customer);
    quickSort(customers, 0, customers.size() - 1, 1, true);
    cout << "Add customer successfully!" << endl;
    cout << customer;
    saveData(FILE_PATH, customers);
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
        hasFound = searchCustomer(customers, ID, 1);
        if (hasFound == -1)
        {
            cout << "ID is not exist. Please enter again: ";
        }
    } while (!validID || hasFound == -1);
    cout << customers[hasFound];
    cout << "Are you sure to delete this customer? (Y/N): ";
    char choice;
    bool validChoice = true;
    do
    {
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            customers.erase(customers.begin() + hasFound);
            cout << "Delete successfully!" << endl;
            saveData(FILE_PATH, customers);
            validChoice = true;
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Delete failed!" << endl;
            validChoice = true;
        }
        else
        {
            cout << "Invalid choice. Please enter again: ";
            validChoice = false;
        }
    } while (!validChoice);
}

void updateCustomer(vector<Customer> &customers)
{

    string ID;
    bool validID, validEmail;
    long hasFound, selectGender = 0;
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
        hasFound = searchCustomer(customers, ID, 1);

        if (hasFound == -1)
        {
            cout << "ID is not exist. Please enter again: ";
        }
    } while (!validID || hasFound == -1);
    cout << customers[hasFound];
    cout << "Are you sure to update this customer? (Y/N): ";
    char choice;
    do
    {
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            cout << "If you don't want to update any field, just press 0" << endl;
            customers[hasFound] = setCustomerInformation(customers, true, hasFound);
            cout << "Update successfully!" << endl;
            cout << customers[hasFound];
            saveData(FILE_PATH, customers);
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Cancelled!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please enter again : ";
        }
    } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
}

string formatAddressForPrint(string address)
{
    for (auto &i : address)
    {
        if (i == ',' || i == '-')
            i = '\n';
    }
    return address;
}

string formatName(string name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name[0] = toupper(name[0]);
    for (size_t i = 1; i < name.length(); i++)
    {
        if (name[i - 1] == ' ' && name[i] != ' ')
        {
            name[i] = toupper(name[i]);
        }
    }
    return name;
}

string formatBill(string bill)
{
    int count = 0;
    for (int i = bill.length() - 1; i >= 0; i--)
    {
        count++;
        if (count == 3 && i != 0)
        {
            bill.insert(i, ",");
            count = 0;
        }
    }
    bill += " VND";
    return bill;
}

long searchCustomerFibonacciSearch(vector<Customer> customers, size_t ID)
{
    long fibo2 = 0;
    long fibo1 = 1;
    long fiboCur = fibo2 + fibo1;
    while (fiboCur < customers.size())
    {
        fibo2 = fibo1;
        fibo1 = fiboCur;
        fiboCur = fibo2 + fibo1;
    }
    long offset = -1;
    long cusSize = customers.size();
    while (fiboCur > 1)
    {
        long i = min(offset + fibo2, cusSize - 1);

        if (stringToNumber(customers[i].getID()) < ID)
        {
            fiboCur = fibo1;
            fibo1 = fibo2;
            fibo2 = fiboCur - fibo1;
            offset = i;
        }
        else if (stringToNumber(customers[i].getID()) > ID)
        {
            fiboCur = fibo2;
            fibo1 = fibo1 - fibo2;
            fibo2 = fiboCur - fibo1;
        }
        else
            return i;
    }
    if (fibo1 && stringToNumber(customers[offset + 1].getID()) == ID)
        return offset + 1;
    return -1;
}

void saveData(string filePath, vector<Customer> customers)
{
    ofstream file(filePath);
    file << left << setw(20) << "ID" << setw(40) << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(10) << "Gender" << setw(50) << "Address" << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        file << left << setw(20) << customers[i].getID() << setw(40) << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(10) << customers[i].getGender() << setw(50) << customers[i].getAddress() << endl;
    }
    file.close();
}

string getLastName(string name)
{
    string lastName = "";
    for (int i = name.length() - 1; i >= 0; i--)
    {
        if (name[i] == ' ')
        {
            break;
        }
        lastName = name[i] + lastName;
    }
    return lastName;
}

Customer setCustomerInformation(vector<Customer> customers, bool isUpdate, long index)
{
    string ID = "0", name, email, phone, bill, gender, address;
    long selectGender, hasFound;
    bool validID, validEmail, validPhone, validBill;
    vector<Customer> forSearch = customers;
    cout << "Enter ID: ";
    do
    {
        cin >> ID;
        if (ID == "0")
        {
            if (!isUpdate)
            {

                cout << "ID can't be 0. Please enter again: ";
                continue;
            }
            else
            {
                break;
            }
        }
        validID = isValidID(ID);
        if (!validID)
        {
            cout << "Invalid ID. Please enter again: ";
            continue;
        }
        hasFound = searchCustomer(forSearch, ID, 1);
        if (hasFound != -1)
        {
            cout << "ID is not available. Please enter again: ";
        }
    } while (!validID || hasFound != -1);
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    if (name != "0")
        name = formatName(name);
    cout << "Enter email: ";
    do
    {
        cin >> email;
        if (email == "0")
        {
            if (!isUpdate)
            {
                cout << "Invalid email. Please enter again:  ";
                continue;
            }
            else
            {
                break;
            }
        }
        validEmail = isValidEmail(email);
        if (!validEmail)
        {
            cout << "Invalid email. Please enter again: ";
            continue;
        }
    } while (!validEmail);
    cout << "Enter phone: ";
    do
    {
        cin >> phone;
        if (phone == "0")
        {
            if (!isUpdate)
            {
                cout << "Invalid phone. Please enter again:  ";
                continue;
            }
            else
            {
                break;
            }
        }
        validPhone = isValidPhone(phone);
        if (!validPhone)
        {
            cout << "Invalid phone. Please enter again: ";
        }
    } while (!validPhone);
    cout << "Enter bill: ";
    do
    {
        cin >> bill;
        if (bill == "0")
        {
            if (!isUpdate)
            {
                cout << "Bill can't be 0. Please enter again: ";
                continue;
            }
            else
            {
                break;
            }
        }
        validBill = isValidBill(bill);
        if (!validBill)
        {
            cout << "Invalid bill. Please enter again: ";
        }
    } while (!validBill);
    if (bill != "0")
        bill = formatBill(bill);
    cout << "Enter gender: ";
    cout << "[1] Male           [2] Female" << endl;
    do
    {
        cin >> selectGender;
        if (selectGender == 0)
        {
            if (isUpdate)
                break;
            else
                cout << "INVALID. Please enter again: ";
        }

    } while (selectGender > 2 && selectGender < 0);
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    address = formatName(address);
    gender = (selectGender == 1) ? "Male" : "Female";
    if (isUpdate)
    {
        ID = (ID == "0") ? customers[index].getID() : ID;
        name = (name == "0") ? customers[index].getName() : name;
        email = (email == "0") ? customers[index].getEmail() : email;
        phone = (phone == "0") ? customers[index].getPhone() : phone;
        address = (address == "0") ? customers[index].getAddress() : address;
        bill = (bill == "0") ? customers[index].getBill() : bill;
        gender = (selectGender == 0) ? customers[index].getGender() : gender;
    }
    return Customer(ID, name, email, phone, bill, gender, address);
}

vector<Customer> filterBill(vector<Customer> customers, string bill, int option)
{
    vector<Customer> result;
    for (int i = 0; i < customers.size(); i++)
    {
        if (option == 2)
        {
            if (stringToNumber(customers[i].getBill()) > stringToNumber(bill))
            {
                result.push_back(customers[i]);
            }
        }
        else if (option == 3)
        {
            if (stringToNumber(customers[i].getBill()) < stringToNumber(bill))
            {
                result.push_back(customers[i]);
            }
        }
        else if (option == 1)
        {
            if (stringToNumber(customers[i].getBill()) == stringToNumber(bill))
            {
                result.push_back(customers[i]);
            }
        }
    }
    return result;
}

vector<Customer> filterBill(vector<Customer> customers, unsigned long long start, unsigned long long end)
{
    vector<Customer> result;
    for (int i = 0; i < customers.size(); i++)
    {
        if (stringToNumber(customers[i].getBill()) >= start && stringToNumber(customers[i].getBill()) <= end)
        {
            result.push_back(customers[i]);
        }
    }
    return result;
}

void readData(string fileName, vector<Customer> &customers)
{
    ifstream input(fileName);
    if (!input.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    string ID, name, email, phone, bill, gender, address = "", temp;
    map<size_t, string> rawData;
    size_t index = 1, rawDataSize;
    getline(input, temp);
    while (getline(input, temp) && temp != "")
    {
        stringstream splitData(temp);
        string word;
        while (splitData >> word)
        {
            rawData[index++] = word;
        }
        while (rawData[index - 1] != "Male" || rawData[index - 1] != "Female")
        {
            address = rawData[index - 1] + " " + address;
            index--;
            if (rawData[index - 1] == "Male" || rawData[index - 1] == "Female")
                break;
        }
        address.pop_back();
        address = formatName(address);
        ID = rawData[1];
        gender = rawData[index - 1];
        bill = rawData[index - 3] + " " + rawData[index - 2];
        phone = rawData[index - 4];
        email = rawData[index - 5];
        name = "";
        for (size_t i = 2; i < index - 5; i++)
        {
            name += rawData[i] + " ";
        }
        name.pop_back();
        name = formatName(name);
        customers.push_back(Customer(ID, name, email, phone, bill, gender, address));
        index = 1;
        address = "";
    }
    input.close();
}

void importData(string filePath, vector<Customer> &customers, bool isReplace)
{
    if (isReplace)
        customers.clear();
    size_t oldSize = customers.size();
    readData(filePath, customers);
    size_t newSize = customers.size();
    size_t id = 1;
    for (auto &cus : customers)
    {
        cus.setID(to_string(id++));
    }
    saveData(FILE_PATH, customers);
    cout << "Import successfully. Added " << newSize - oldSize << " customers to database" << endl;
}
