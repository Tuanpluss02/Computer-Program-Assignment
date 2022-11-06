#include "menu.hpp"

void readData(string fileName);
void formatAddress(string &address);

int main()
{
    readData(FILE_PATH);
    printAllCustomer(customers);
    // mainMenu();
    // searchMenu();
    // sortMenu();
    system("pause");
    return 0;
}

void readData(string fileName)
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
        formatAddress(address);
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
        customers.push_back(Customer(ID, name, email, phone, bill, gender, address));
        index = 1;
        address = "";
    }
    input.close();
}

void formatAddress(string &address)
{
    for (auto &i : address)
    {
        if (i == ',' || i == '-')
            i = '\n';
    }
}