#include "customer.cpp"
#include <conio.h>
using ConsoleTable = samilton::ConsoleTable;

vector<Customer> customers;

using namespace std;

void login();
string encrypt(string password);
void gotoXY(SHORT x, SHORT y);
void SetColor(WORD color);
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
    table[2][0] = "          Do Ngoc Tuan - B20DCVT330               ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 9)
        {
            SetColor(4);
            cout << "Invalid choice! Please enter again!" << endl;
            SetColor(7);
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
        SetColor(2);
        cout << "File opened successfully!" << endl;
        SetColor(7);
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
    table[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 8)
        {
            SetColor(4);
            cout << "Invalid choice! Please enter again!" << endl;
            SetColor(7);
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
    sortOption[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
    cout << setw(40) << sortOption;
    int choice2;
    bool isAscending;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice2;
        if (choice2 > 3 || choice2 < 1)
        {
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
        }

    } while (choice2 > 3 || choice2 < 1);
    CLEAR_SCREEN;
    switch (choice2)
    {
    case 1:
        isAscending = true;
        quickSort(customers, 0, customers.size() - 1, choice1, isAscending);
        saveData(FILE_PATH, customers);
        afterDone(customers);
        break;
    case 2:
        isAscending = false;
        quickSort(customers, 0, customers.size() - 1, choice1, isAscending);
        saveData(FILE_PATH, customers);
        afterDone(customers);
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
    table[1][0] = "[1] Print the result\n[2] Export the result\n[3] Print all customer\n[4] Open data file\n[5] Back to main menu\n[0] Exit";
    table[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice > 5 || choice < 0)
        {
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
        }

    } while (choice > 5 || choice < 0);
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
        exportMenu(Customers);
        break;
    case 3:
        printAllCustomer(customers);
        system("pause");
        CLEAR_SCREEN;
        mainMenu();
        break;
    case 4:
        system(CMD.c_str());
        SetColor(2);
        cout << "File opened successfully!" << endl;
        SetColor(7);
        mainMenu();
        break;
    case 5:
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
    table[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
    cout << setw(40) << table;
    int choice1;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice1;
        if (choice1 < 0 || choice1 > 4)
        {
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
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
        SetColor(4);
        cout << "No result found!" << endl;
        SetColor(7);
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
    string id;
    bool isValidId = false;
    do
    {
        cout << "Enter ID: ";
        cin >> id;
        isValidId = isValidID(id);
        if (!isValidId)
        {
            SetColor(4);
            cout << "Invalid ID! Please try again!" << endl;
            SetColor(7);
        }
        else
            break;

    } while (!isValidId);
    long index = searchCustomer(customers, id, 1);
    if (index == -1)
    {
        SetColor(4);
        cout << "Not found!" << endl;
        SetColor(7);
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
    table[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
    cout << setw(40) << table;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 3)
        {
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
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
    table[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
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
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
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
            SetColor(4);
            cout << "No result found!" << endl;
            SetColor(7);
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone(result);
        break;
    case 2:
        cout << "Enter bill to filter: ";
        cin >> bill;
        result = filterBill(customers, bill, 2);
        if (result.size() == 0)
        {
            SetColor(4);
            cout << "No result found!" << endl;
            SetColor(7);
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone(result);
        break;
    case 3:
        cout << "Enter bill to filter: ";
        cin >> bill;
        result = filterBill(customers, bill, 3);
        if (result.size() == 0)
        {
            SetColor(4);
            cout << "No result found!" << endl;
            SetColor(7);
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone(result);
        break;
    case 4:
        cout << "Enter start bill: ";
        cin >> start;
        cout << "Enter end bill: ";
        cin >> end;
        result = filterBill(customers, stringToNumber(start), stringToNumber(end));
        if (result.size() == 0)
        {
            SetColor(4);
            cout << "No result found!" << endl;
            SetColor(7);
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone(result);
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
    table[2][0] = "           Do Ngoc Tuan - B20DCVT330             ";
    cout << setw(40) << table;
    vector<Customer> result;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 0 || choice > 4)
        {
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
        }
    } while (choice < 0 || choice > 4);
    CLEAR_SCREEN;
    switch (choice)
    {
    case 1:
        result = linearSearch(customers, "Male", 6);
        if (result.size() == 0)
        {
            SetColor(4);
            cout << "No result found!" << endl;
            SetColor(7);
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone(result);
        break;
    case 2:
        result = searchCustomerRegex(customers, "Female");
        if (result.size() == 0)
        {
            SetColor(4);
            cout << "No result found!" << endl;
            SetColor(7);
        }
        else
        {
            printAllCustomer(result);
        }
        system("pause");
        CLEAR_SCREEN;
        afterDone(result);
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
    vector<string> rawData, files;
    for (const auto &entry : fs::directory_iterator(import_path))
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
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
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
            SetColor(4);
            cout << "Invalid choice! Please try again!" << endl;
            SetColor(7);
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
    afterDone(Customers);
}

void exportMenu(vector<Customer> &Customers)
{
    vector<string> rawData, files;
    for (const auto &entry : fs::directory_iterator(export_path))
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
            SetColor(4);
            cout << "File is exsit! Please try again!" << endl;
            SetColor(7);
            continue;
        }
        else
        {
            isExist = false;
        }
    } while (isExist);
    fileName = export_path + fileName;
    saveData(fileName, Customers);
    SetColor(2);
    cout << "Export successfully! The file is saved at " << export_path << endl;
    SetColor(7);
    afterDone(Customers);
}

void login()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Welcome to the customer management system\nPlease enter your username and password to login";
    table[1][0] = "Username: ";
    table[2][0] = "Password: ";
    cout << setw(40) << table;
    gotoXY(55, 4);
    string username, password;
    cin >> username;
    getchar();
    gotoXY(55, 6);
    int x = 55;
    size_t charr;
    for (charr = 0; charr < 9; charr++)
    {
        password += _getch();
        gotoXY(x++, 6);
        _putch('*');
    }
    if (username == "admin" && encrypt(password) == encrypt_key)
    {
        CLEAR_SCREEN;
        SetColor(2);
        cout << "Login successfully!" << endl;
        SetColor(7);
        readData(FILE_PATH, customers);
        mainMenu();
    }
    else
    {
        gotoXY(53, 8);
        SetColor(4);
        cout << "Login failed! Please try again!" << endl;
        SetColor(7);
        system("pause");
        CLEAR_SCREEN;
        login();
    }
}

string encrypt(string password)
{
    // encrypt password using round shift with K = 4
    string result = "";
    for (int i = 0; i < password.length(); i++)
    {
        result += (char)(password[i] + 4) % 256;
    }
    return result;
}

void gotoXY(SHORT x, SHORT y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}