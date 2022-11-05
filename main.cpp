#include "customer.cpp"

vector<Customer> customers;

void readData(string path);

int main()
{
    readData(FILE_PATH);
    system("pause");
    return 0;
}

void readData(string path = FILE_PATH)
{
    ifstream input(path);
    if (!input.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    string ID, name, email, phone, bill, temp;
    deque<string> rawData;
    getline(input, temp);
    while (getline(input, temp) && temp != "")
    {
        stringstream splitData(temp);
        string word;
        while (splitData >> word)
        {
            rawData.push_back(word);
        }
        ID = rawData.front();
        rawData.pop_front();
        bill = rawData.back();
        rawData.pop_back();
        bill = rawData.back() + " " + bill;
        rawData.pop_back();
        phone = rawData.back();
        rawData.pop_back();
        email = rawData.back();
        name = "";
        while (!rawData.empty())
        {
            name += rawData.front() + " ";
            rawData.pop_front();
        }
        name.pop_back();
        customers.push_back(Customer(ID, name, email, phone, bill));
    }
    input.close();
}