#include <iostream>
#include "CppConsoleTable.hpp"

using ConsoleTable = samilton::ConsoleTable;

using namespace std;

void mainMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Menu";
    table[1][0] = "1. Add new customer\n2. Search customer\n3. Edit customer\n4. Delete customer\n5. Print all customers\n6. Exit";
    table[2][0] = "          Made by Do Ngoc Tuan               ";
    cout << setw(40) << table;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
}
void searchMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Search Menu";
    table[1][0] = "1. Search by ID\n2. Search by free text\n6. Back to main menu";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
}

void sortMenu()
{
    ConsoleTable table(1, 1, samilton::Alignment::left);
    table[0][0](samilton::Alignment::centre) = "Sort Menu";
    table[1][0] = "1. Sort by ID\n2. Sort by name\n3. Sort by email\n4. Sort by phone\n5. Sort by bill\n6. Back to main menu";
    table[2][0] = "           Made by Do Ngoc Tuan             ";
    cout << setw(40) << table;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
}