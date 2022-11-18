#include "customer.cpp"

using ConsoleTable = samilton::ConsoleTable;

vector<Customer> customers;

using namespace std;
void searchByFreeText();
void filterMenu();
void filterBillMenu();
void filterGenderMenu();
void searchByID();
void mainMenu();
void searchMenu();
void sortMenu();
void subSortMenu();
void afterDone(vector<Customer> &Customers);
void importMenu(vector<Customer> &Customers);
void exportMenu(vector<Customer> &Customers);

void mainMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Menu";
    table[1][0] = "[1] Add new customer\n[2] Delete customer\n[3] Edit customer\n[4] Search customer\n[5] Sort customer\n[6] Filter customer\n[7] Import data\n[8] Print all customer\n[9] Open data file\n[0] Exit";
    table[2][0] = "          Made by Do Ngoc Tuan               ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 9)
        {
            cout << "Invalid choice! Please enter again!" << endl;
        }
    } while (choice < 0 || choice > 9);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        addCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 2:
        deleteCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 3:
        updateCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 4:
        searchMenu();
        break;
    case 5:
        sortMenu();
        break;
    case 6:
        filterMenu();
        break;
    case 7:
        importMenu(customers);
        break;
    case 8:
        printAllCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 9:
        system(CMD.c_str());
        cout << "File opened successfully!" << endl;
        mainMenu();
        break;

    case 0:
        exit(0);
        break;
    }
}

void searchMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Search Menu";
    table[1][0] = "[1] Search by ID\n[2] Search by free text\n[3] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 8)
        {
            cout << "Invalid choice! Please enter again!" << endl;
        }
    } while (choice < 0 || choice > 8);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        searchByID();
        break;
    case 2:
        searchByFreeText();
        break;
    case 3:
        mainMenu();
        break;
    case 0:
        exit(0);
        break;
    }
}

void subSortMenu(int choice1)
{
    ConsoleTable sortOption(1, 1, samilton::Alignment::left);
    sortOption[0][0](samilton::Alignment::centre) = "Sort Option";
    sortOption[1][0] = "[1] Ascending\n[2] Descending\n[3] Back to sort menu\n[4] Back to main menu";
    sortOption[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << sortOption;
    int choice2;
    bool isAscending;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice2;
        if (choice2 > 3 || choice2 < 1)
            cout << "Invalid choice! Please try again!" << endl;
    } while (choice2 > 3 || choice2 < 1);
    CLEAR_SCREEN;
    switch (choice2)
    {
    case 1:
        isAscending = true;
        quickSort(customers, 0, customers.size() - 1, choice1, isAscending);
        saveData(FILE_PATH, customers);
        afterDone();
        break;
    case 2:
        isAscending = false;
        quickSort(customers, 0, customers.size() - 1, choice1, isAscending);
        saveData(FILE_PATH, customers);
        afterDone();
        break;
    case 3:
        sortMenu();
        break;
    case 4:
        mainMenu();
        break;
    }
}

void afterDone(vector<Customer> &Customers)
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Done!";
    table[1][0] = "[1] Print all customers\n[2] Open data file\n[3] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice > 3 || choice < 0)
            cout << "Invalid choice! Please try again!" << endl;
    } while (choice > 3 || choice < 0);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        printAllCustomer(Customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 2:
        system(CMD.c_str());
        cout << "File opened successfully!" << endl;
        mainMenu();
        break;
    case 3:
        mainMenu();
        break;
    default:
        exit(0);
        break;
    }
}

void sortMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Sort Menu";
    table[1][0] = "[1] Sort by ID\n[2] Sort by name\n[3] Sort by bill\n[4] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice1;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice1;
        if (choice1 < 0 || choice1 > 4)
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (choice1 < 0 || choice1 > 4);
    CLEAR_SCREEN;
    if (choice1 == 4)
    {
        mainMenu();
    }
    else if (choice1 == 0)
    {
        exit(0);
    }
    else
    {
        subSortMenu(choice1);
    }
}

void searchByFreeText()
{
    string keyword;
    cout << "Enter keyword: ";
    cin.ignore();
    getline(cin, keyword);
    vector<Customer> res = searchCustomerRegex(customers, keyword);
    if (res.size() == 0)
    {
        cout << "No result found!" << endl;
        system("pause");
        CLEAR_SCREEN;
        searchMenu();
    }
    else
    {
        printAllCustomer(res);
        system("pause");
        CLEAR_SCREEN;
        searchMenu();
    }
}

void searchByID()
{
    size_t id;
    cout << "Enter ID: ";
    cin >> id;
    long index = searchCustomerBinarySearch(customers, id);
    if (index == -1)
    {
        cout << "Not found!" << endl;
        system("pause");
        CLEAR_SCREEN;
        searchMenu();
    }
    else
    {
        cout << customers[index];
        system("pause");
        CLEAR_SCREEN;
        searchMenu();
    }
}

void filterMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Filter Menu";
    table[1][0] = "[1] Filter by bill\n[2] Filter by gender\n[3] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 3)
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (choice < 0 || choice > 3);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        filterBillMenu();
        break;
    case 2:
        filterGenderMenu();
        break;
    case 3:
        mainMenu();
        break;
    default:
        exit(0);
        break;
    }
}

void filterBillMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Filter by bill";
    table[1][0] = "[1] Filter by bill equal to \n[2] Filter by bill greater than\n[3] Filter by bill less than\n[4] Filter by bill between\n[5] Back to filter menu\n[6] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice;
    string bill, start, end;
    vector<Customer> result;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 6)
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (choice < 0 || choice > 6);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        cout << "Enter bill to filter: ";
        cin >> bill;
        result = filterBill(customers, bill, 1);
        if (result.size() == 0)
        {
            cout << "No result found!" << endl;
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone();
        break;
    case 2:
        cout << "Enter bill to filter: ";
        cin >> bill;
        result = filterBill(customers, bill, 2);
        if (result.size() == 0)
        {
            cout << "No result found!" << endl;
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone();
        break;
    case 3:
        cout << "Enter bill to filter: ";
        cin >> bill;
        result = filterBill(customers, bill, 3);
        if (result.size() == 0)
        {
            cout << "No result found!" << endl;
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone();
        break;
    case 4:
        cout << "Enter start bill: ";
        cin >> start;
        cout << "Enter end bill: ";
        cin >> end;
        result = filterBill(customers, stringToNumber(start), stringToNumber(end));
        if (result.size() == 0)
        {
            cout << "No result found!" << endl;
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone();
        break;
    case 5:
        filterMenu();
        break;
    case 6:
        mainMenu();
        break;
    default:
        exit(0);
        break;
    }
}
void filterGenderMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre);
    table[1][0] = "[1] Filter by male\n[2] Filter by female\n[3] Back to filter menu\n[4] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    vector<Customer> result;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 4)
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (choice < 0 || choice > 4);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        result = searchCustomerRegex(customers, "Male");
        if (result.size() == 0)
        {
            cout << "No result found!" << endl;
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone();
        break;
    case 2:
        result = searchCustomerRegex(customers, "Female");
        if (result.size() == 0)
        {
            cout << "No result found!" << endl;
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone();
        break;
    case 3:
        filterMenu();
        break;
    case 4:
        mainMenu();
        break;
    default:
        exit(0);
        break;
    }
}
void importMenu(vector<Customer> &Customers)
{
    string path = "E:\\CODE\\Cpp\\Computer-Program-Assignment\\asset";
    vector<string> rawData, files;
    for (const auto &entry : fs::directory_iterator(path))
        rawData.push_back(entry.path().string());
    for (auto file : rawData)
    {
        stringstream ss(file);
        string token = "";
        while (getline(ss, token, '\\'))
            ;
        files.push_back(token);
    }
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Chose file to import";
    string tmp = "", fileName = "";
    for (int i = 0; i < files.size(); i++)
    {
        tmp += "[" + to_string(i + 1) + "] " + files[i] + '\n';
    }
    table[1][0] = tmp;
    cout << setw(40) << table;
    cout << "Choose file to import: " << endl;
    int selection;
    do
    {
        cout << "Enter your choice: ";
        cin >> selection;
        if (selection < 1 || selection > files.size())
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (selection < 1 || selection > files.size());
    fileName = export_path + files[selection - 1];
    cout << "Do you want to replace current data? (Y/N): ";
    char choice;
    bool isReplace = false;
    do
    {
        cin >> choice;
        if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
        else
        {
            if (choice == 'Y' || choice == 'y')
            {
                isReplace = true;
            }
            else if (choice == 'N' || choice == 'n')
            {
                isReplace = false;
            }
        }
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    CLEAR_SCREEN;
    importData(fileName, Customers, isReplace);
    afterDone();
}

void exportMenu(vector<Customer> &Customers)
{
    string path = "E:\\CODE\\Cpp\\Computer-Program-Assignment\\asset";
    vector<string> rawData, files;
    for (const auto &entry : fs::directory_iterator(path))
        rawData.push_back(entry.path().string());
    for (auto file : rawData)
    {
        stringstream ss(file);
        string token = "";
        while (getline(ss, token, '\\'))
            ;
        files.push_back(token);
    }
    string fileName;
    bool isExist = false;
    cout << "Enter file name: ";
    do
    {
        cin >> fileName;
        fileName += ".txt";
        if (find(files.begin(), files.end(), fileName) != files.end())
        {
            isExist = true;
            cout << "File is exsit! Please try again!" << endl;
            continue;
        }
        else
        {
            isExist = false;
        }
    } while (isExist);
    fileName = export_path + fileName;
    saveData(fileName, Customers);
    cout << "Export successfully! The file is saved at " << export_path << endl;
    afterDone(Customers);
}