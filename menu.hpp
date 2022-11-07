#include "customer.cpp"

using ConsoleTable = samilton::ConsoleTable;
vector<Customer> customers;

using namespace std;

void mainMenu();
void searchMenu();
void sortMenu();
void subSortMenu();
void afterSort();

void mainMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Menu";
    table[1][0] = "[1] Add new customer\n[2] Search customer\n[3] Edit customer\n[4] Delete customer\n[5] Print all customers\n[6] Sort customer\n[7] Exit";
    table[2][0] = "          Made by Do Ngoc Tuan               ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid choice! Please enter again!" << endl;
        }
    } while (choice < 1 || choice > 7);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        addCustomer(customers);
        break;
    case 2:
        searchMenu();
        break;
    case 3:
        // updateCustomer(customers);
        break;
    case 4:
        // deleteCustomer(customers);
        break;
    case 5:
        printAllCustomer(customers);
        break;
    case 6:
        sortMenu();
        break;
    case 7:
        exit(0);
        break;
    }
}
void searchMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Search Menu";
    table[1][0] = "[1] Search by ID\n[2] Search by free text\n[6] Back to main menu";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    do
    {
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
    } while (true);
}

void subSortMenu(int choice1)
{
    ConsoleTable sortOption(1, 1, samilton::Alignment::left);
    sortOption[0][0](samilton::Alignment::centre) = "Sort Option";
    sortOption[1][0] = "[1] Ascending\n[2] Descending\n[3] Back to sort menu";
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
        afterSort();
        break;
    case 2:
        isAscending = false;
        quickSort(customers, 0, customers.size() - 1, choice1, isAscending);
        afterSort();
        break;
    default:
        sortMenu();
        break;
    }
}

void afterSort()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Sort successfully!";
    table[1][0] = "[1] Print all customers\n[2] Back to sort menu\n[3] Back to main menu\n[4] Exit";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice > 4 || choice < 1)
            cout << "Invalid choice! Please try again!" << endl;
    } while (choice > 4 || choice < 1);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        printAllCustomer(customers);
        break;
    case 2:
        sortMenu();
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
    table[1][0] = "[1] Sort by ID\n[2] Sort by name\n[3] Sort by email\n[4] Sort by phone\n[5] Sort by bill\n[6] Back to main menu";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    int choice1;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice1;
        if (choice1 < 1 || choice1 > 6)
        {
            cout << "Invalid choice! Please try again!" << endl;
            continue;
        }
    } while (choice1 < 1 || choice1 > 6);
    CLEAR_SCREEN;
    if (choice1 == 6)
    {
        mainMenu();
    }
    else
    {
        subSortMenu(choice1);
    }
}
