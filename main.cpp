#include "customer.cpp"
#include "menu.hpp"
vector<Customer> customers;

void readData(string fileName);

int main()
{
    readData(FILE_PATH);
    mainMenu();
    searchMenu();
    sortMenu();
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
    string ID, name, email, phone, bill, temp;
    map<size_t, string> rawData;
    size_t index = 1;
    getline(input, temp);
    while (getline(input, temp) && temp != "")
    {
        stringstream splitData(temp);
        string word;
        while (splitData >> word)
        {
            rawData[index++] = word;
        }
        ID = rawData[1];
        bill = rawData[index - 2] + " " + rawData[index - 1];
        phone = rawData[index - 3];
        email = rawData[index - 4];
        name = "";
        for (size_t i = 2; i < index - 4; i++)
        {
            name += rawData[i] + " ";
        }
        name.pop_back();
        customers.push_back(Customer(ID, name, email, phone, bill));
        index = 1;
    }
    input.close();
}
