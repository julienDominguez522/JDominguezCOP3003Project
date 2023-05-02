#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include "SystemFunctions.h"

using std::cout;
using std::cin;
using std::string;
using std::ofstream;

/* Variable declarations */
string items[100] = {"Eggs", "Milk", "Bread", "Meat", "Fish", "Water", "Soda", "Butter",
                     "Rice", "Cheese", "Vegetables", "Fruit"};
int itemAdd[100];
int itemSubtract[100];
int itemID;
int itemAmount[100];
int subItemNumber[100];
int addItemNumber[100];
ofstream inventoryFile;


/* This is the standard menu prompt that the user will default back to when they are done with the other functions */
void menuPrompt() {
    int userChoice;
    /* basic menu display to show to the user and prompt them to select the action they would like to perform*/
    do {
        std::cout << "**************************************************\n"
                  << " Welcome to the Inventory Management System\n"
                  << "**************************************************\n"
                  << "Please choose from one of the following options:\n"
                  << "[0] Exit\n"
                  << "[1] Add an items to the stock\n"
                  << "[2] Input the items sold (This will delete number of items from the stock)\n"
                  << "[3] Search for item in stock\n"
                  << "[4] View the current stock\n"
                  << "Please enter your choice: ";
        std::cin >> userChoice;

        /* Switch statement to reference the function that the user selects */
        switch (userChoice) {
            case 0:
                std::cout << "Thanks for stopping by!\n";
                break;
            case 1:
                addItem();
                break;
            case 2:
                deleteItem();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                viewStock();
                break;
            default:
                cout << "That input was invalid. Please choose from one of the available options.\n";
                menuPrompt();
        }

    }
    while(userChoice != 0);
}

/* --------------------------------------------------------------------------------------------------------------------
 * This function is to prompt the user to add either the initial stock or add additional stock of a particular item.
 * I put a disclaimer on the add item function because if they try to use it twice, it will reset the entire stock. I
 * hope to be able to correct this when I find more time to polish this code up.
 */
void addItem() {
    int addItemAction;


    cout << "Please choose from one of the following actions: \n"
            "[0] Return to the menu\n"
            "[1] Add intial inventory (This should only be used for the initial stock, any repeated uses will reset the inventory)\n"
            "[2] View the current stock\n"
            "[3] Add more items\n";
    cin >> addItemAction;

    switch (addItemAction) {
        case 0:
            menuPrompt();
            break;
        case 1:
            for (int i = 0; i < 12; i++) {
                cout << "\t Enter the amount of " << items[i] << ": ";
                cin >> itemAmount[i];
            }
        case 2:
            viewStock();
        case 3:
            addAdditionalItems();
        default:
            cout << "That input was invalid. Please choose from one of the available options.\n";
            addItem();
    }

    viewStock();
}

/* --------------------------------------------------------------------------------------------------------------------
 * This function is for the user to add additional stock to a particular item instead of adding the whole stock
 * over again.
 */
void addAdditionalItems() {

    cout << "Which item would you like to add?\n"
            "Product ID's:\n"
            "0 : Eggs\n"
            "1 : Milk\n"
            "2 : Bread\n"
            "3 : Meat\n"
            "4 : Fish\n"
            "5 : Water\n"
            "6 : Soda\n"
            "7 : Butter\n"
            "8 : Rice\n"
            "9 : Cheese\n"
            "10 : Vegetables\n"
            "11 : Fruits\n"
            "Please enter the product ID: \n";
    cin >> itemID;

    if (itemID == 0) {
        cout << "Enter the amount of Eggs: ";
        cin >> itemAdd[0];
        addItemNumber[0] = itemAmount[0] + itemAdd[0];
        addItem();
    } else if (itemID == 1) {
        cout << "Enter the amount of Milk: ";
        cin >> itemAdd[1];
        addItemNumber[1] = itemAmount[1] + itemAdd[1];
        addItem();
    }else if (itemID == 2) {
        cout << "Enter the amount of Bread: ";
        cin >> itemAdd[2];
        addItemNumber[2] = itemAmount[2] + itemAdd[2];
        addItem();
    }else if (itemID == 3) {
        cout << "Enter the amount of Meat: ";
        cin >> itemAdd[3];
        addItemNumber[3] = itemAmount[3] + itemAdd[3];
        addItem();
    }else if (itemID == 4) {
        cout << "Enter the amount of Fish: ";
        cin >> itemAdd[4];
        addItemNumber[4] = itemAmount[4] + itemAdd[4];
        addItem();
    }else if (itemID == 5) {
        cout << "Enter the amount of Water: ";
        cin >> itemAdd[5];
        addItemNumber[5] = itemAmount[5] + itemAdd[5];
        addItem();
    }else if (itemID == 6) {
        cout << "Enter the amount of Soda: ";
        cin >> itemAdd[6];
        addItemNumber[6] = itemAmount[6] + itemAdd[6];
        addItem();
    }else if (itemID == 7) {
        cout << "Enter the amount of Butter: ";
        cin >> itemAdd[7];
        addItemNumber[7] = itemAmount[7] + itemAdd[7];
        addItem();
    }else if (itemID == 8) {
        cout << "Enter the amount of Rice: ";
        cin >> itemAdd[8];
        addItemNumber[8] = itemAmount[8] + itemAdd[8];
        addItem();
    }else if (itemID == 9) {
        cout << "Enter the amount of Cheese: ";
        cin >> itemAdd[9];
        addItemNumber[9] = itemAmount[9] + itemAdd[9];
        addItem();
    }else if (itemID == 10) {
        cout << "Enter the amount of Vegetables: ";
        cin >> itemAdd[10];
        addItemNumber[10] = itemAmount[10] + itemAdd[10];
        addItem();
    }else if (itemID == 11) {
        cout << "Enter the amount of Fruit: ";
        cin >> itemAdd[11];
        addItemNumber[11] = itemAmount[11] + itemAdd[11];
        addItem();
    }else {
        cout << "Oops! Please enter a valid product ID: ";
        addItem();
    }
}

/* --------------------------------------------------------------------------------------------------------------------
 * This function is for the user to input any items that have been sold or deleted from the stock. It takes the initial
 * amount of stock entered and subtracts the amount that the user enters.
 */
void deleteItem() {
    int deleteItemAction;
    cout << "Please choose from one of the following actions: \n"
            "[0] Return to the menu\n"
            "[1] Input items sold\n"
            "[2] View the current stock\n";
    cin >> deleteItemAction;

    switch (deleteItemAction) {
        case 0:
            menuPrompt();
        case 1:
            cout << "Product ID's:\n"
                    "0 : Eggs\n"
                    "1 : Milk\n"
                    "2 : Bread\n"
                    "3 : Meat\n"
                    "4 : Fish\n"
                    "5 : Water\n"
                    "6 : Soda\n"
                    "7 : Butter\n"
                    "8 : Rice\n"
                    "9 : Cheese\n"
                    "10 : Vegetables\n"
                    "11 : Fruit\n"
                    "Please enter the ID of the product sold: ";
            cin >> itemID;

            if (itemID == 0) {
                cout << "Enter the amount of Eggs sold: ";
                cin >> itemSubtract[0];
                subItemNumber[0] = itemAmount[0] - itemSubtract[0];
                deleteItem();
            }
            else if (itemID == 1) {
                cout << "Enter the amount of Milk sold: ";
                cin >> itemSubtract[1];
                subItemNumber[1] = itemAmount[1] - itemSubtract[1];
                deleteItem();
            }
            else if (itemID == 2) {
                cout << "Enter the amount of Bread sold: ";
                cin >> itemSubtract[2];
                subItemNumber[2] = itemAmount[2] - itemSubtract[2];
                deleteItem();
            }else if (itemID == 3) {
                cout << "Enter the amount of Meat sold: ";
                cin >> itemSubtract[3];
                subItemNumber[3] = itemAmount[3] - itemSubtract[3];
                deleteItem();
            }else if (itemID == 4) {
                cout << "Enter the amount of Fish sold: ";
                cin >> itemSubtract[4];
                subItemNumber[4] = itemAmount[4] - itemSubtract[4];
                deleteItem();
            }else if (itemID == 5) {
                cout << "Enter the amount of Water sold: ";
                cin >> itemSubtract[5];
                subItemNumber[5] = itemAmount[5] - itemSubtract[5];
                deleteItem();
            }else if (itemID == 6) {
                cout << "Enter the amount of Soda sold: ";
                cin >> itemSubtract[6];
                subItemNumber[6] = itemAmount[6] - itemSubtract[6];
                deleteItem();
            }else if (itemID == 7) {
                cout << "Enter the amount of Butter sold: ";
                cin >> itemSubtract[7];
                subItemNumber[7] = itemAmount[7] - itemSubtract[7];
                deleteItem();
            }else if (itemID == 8) {
                cout << "Enter the amount of Rice sold: ";
                cin >> itemSubtract[8];
                subItemNumber[8] = itemAmount[8] - itemSubtract[8];
                deleteItem();
            }else if (itemID == 9) {
                cout << "Enter the amount of Cheese sold: ";
                cin >> itemSubtract[9];
                subItemNumber[9] = itemAmount[9] - itemSubtract[9];
                deleteItem();
            }else if (itemID == 10) {
                cout << "Enter the amount of Vegetables sold: ";
                cin >> itemSubtract[10];
                subItemNumber[10] = itemAmount[10] - itemSubtract[10];
                deleteItem();
            }else if (itemID == 11) {
                cout << "Enter the amount of Fruit sold: ";
                cin >> itemSubtract[11];
                subItemNumber[11] = itemAmount[11] - itemSubtract[11];
                deleteItem();
            }else {
                cout << "Oops! Please enter a valid product ID: ";
                deleteItem();
            }
        case 2:
            viewStock();
        default:
            cout << "That input was invalid. Please choose from one of the available options.\n";
            deleteItem();
    }
}

/* --------------------------------------------------------------------------------------------------------------------
 * This function is for the user to reference an item in particular in the instance that they want to reference just
 * the stock of that item. It displays the product name as well as the number of that item in stock.
 */
void searchItem() {
    int searchItemAction;

    cout << "Please choose from one of the following actions: \n"
            "[0] Return to the menu\n"
            "[1] Search for an item\n"
            "[2] View the current stock\n";
    cin >> searchItemAction;

    switch (searchItemAction) {
        case 0:
            menuPrompt();
        case 1:
            cout << "Which product would you like to search for?\n"
                    "Product ID's:\n"
                    "0 : Eggs\n"
                    "1 : Milk\n"
                    "2 : Bread\n"
                    "3 : Meat\n"
                    "4 : Fish\n"
                    "5 : Water\n"
                    "6 : Soda\n"
                    "7 : Butter\n"
                    "8 : Rice\n"
                    "9 : Cheese\n"
                    "10 : Vegetables\n"
                    "11 : Fruit\n"
                    "Please enter the ID of the product you would like to search for: ";
            cin >> itemID;

            if (itemID == 0) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[0] << "\n";
                cout << "Amount in stock: " << subItemNumber[0] << "\n";
                searchItem();
            }else if (itemID == 1) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[1] << "\n";
                cout << "Amount in stock: " << subItemNumber[1] << "\n";
                searchItem();
            }else if (itemID == 2) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[2] << "\n";
                cout << "Amount in stock: " << subItemNumber[2] << "\n";
                searchItem();
            }else if (itemID == 3) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[3] << "\n";
                cout << "Amount in stock: " << subItemNumber[3] << "\n";
                searchItem();
            }else if (itemID == 4) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[4] << "\n";
                cout << "Amount in stock: " << subItemNumber[4] << "\n";
                searchItem();
            }else if (itemID == 5) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[5] << "\n";
                cout << "Amount in stock: " << subItemNumber[5] << "\n";
                searchItem();
            }else if (itemID == 6) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[6] << "\n";
                cout << "Amount in stock: " << subItemNumber[6] << "\n";
                searchItem();
            }else if (itemID == 7) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[7] << "\n";
                cout << "Amount in stock: " << subItemNumber[7] << "\n";
                searchItem();
            }else if (itemID == 8) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[8] << "\n";
                cout << "Amount in stock: " << subItemNumber[8] << "\n";
                searchItem();
            }else if (itemID == 9) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[9] << "\n";
                cout << "Amount in stock: " << subItemNumber[9] << "\n";
                searchItem();
            }else if (itemID == 10) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[10] << "\n";
                cout << "Amount in stock: " << subItemNumber[10] << "\n";
                searchItem();
            }else if (itemID == 11) {
                cout << "PRODUCT INFORMATION\n";
                cout << "Product Name: " << items[11] << "\n";
                cout << "Amount in stock: " << subItemNumber[11] << "\n";
                searchItem();
            }
        case 2:
            viewStock();
        default:
            cout << "That input was invalid. Please choose from one of the available options.\n";
            searchItem();

    }
}


/*--------------------------------------------------------------------------------------------------------------------
 * This function is what is references anytime the user wants to view the stock. It uses an open file to export the
 * information over to a txt file for printing. The initial items that they add as the default are taken into account
 * as well as the number of items they additionally add or subtract from the stock.
 */
void viewStock() {
    cout << "Product ID\t\t"
         << "Products"
         << "\t"
         << "Number of Products" << std::endl;
    for (itemID = 0; itemID < 12; itemID++) {
        itemAmount[itemID] = (itemAmount[itemID] + itemAdd[itemID]) - itemSubtract[itemID];
        cout << itemID << "\t\t\t" << items[itemID] << "\t\t\t" << itemAmount[itemID] << std::endl;
    }
    inventoryFile.open("defaultInventory");

    inventoryFile << "ProductID\t\t"
                  << "Products"
                  << "\t"
                  << "Number of Products" << std::endl;
    for (itemID = 0; itemID < 12; itemID++) {
        inventoryFile << itemID << "\t\t\t" << items[itemID] << "\t\t\t" << itemAmount[itemID] << "\t\t\t" << std::endl;
    }
    cout << "Inventory has been saved\n";

    int returnmenu;
    cout << "Please enter 1 to return to menu ";
    cin >> returnmenu;
    if (returnmenu != 0)
    {
        menuPrompt();
    }
}