#include "customer.cpp"

using ConsoleTable = samilton::ConsoleTable;
vector<Customer> customers;

using namespace std;
void searchByFreeText();
void searchByID();
void mainMenu();
void searchMenu();
void sortMenu();
void subSortMenu();
void afterDone();

void mainMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Menu";
    table[1][0] = "[1] Add new customer\n[2] Search customer\n[3] Edit customer\n[4] Delete customer\n[5] Print all customers\n[6] Sort customer\n[7] Open data file\n[0] Exit";
    table[2][0] = "          Made by Do Ngoc Tuan               ";
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
        addCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 2:
        searchMenu();
        break;
    case 3:
        updateCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 4:
        deleteCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 5:
        printAllCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 6:
        sortMenu();
        break;
    case 7:
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
        if (choice < 1 || choice > 8)
        {
            cout << "Invalid choice! Please enter again!" << endl;
        }
    } while (choice < 1 || choice > 8);
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
        afterDone();
        break;
    case 2:
        isAscending = false;
        quickSort(customers, 0, customers.size() - 1, choice1, isAscending);
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

void afterDone()
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
        printAllCustomer(customers);
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
    table[1][0] = "[1] Sort by ID\n[2] Sort by name\n[3] Sort by email\n[4] Sort by phone\n[5] Sort by bill\n[6] Back to main menu\n[0] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice1;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice1;
        if (choice1 < 0 || choice1 > 6)
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (choice1 < 0 || choice1 > 6);
    CLEAR_SCREEN;
    if (choice1 == 6)
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
        customers[index].printCustomer();
        system("pause");
        CLEAR_SCREEN;
        searchMenu();
    }
}