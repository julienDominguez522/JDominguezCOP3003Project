/* File: JDominguezCOP3003Project.cpp
 * Class: COP 3003, Spring 2023
 * Developer: Julien Dominguez
 * Description: COP 3003 Project: Inventory Management System
 * A code intended to keep inventory for a variety of individuals/businesses who may want to keep track of
 * or reference items that they have in their inventory or storage.
/*------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <ostream>
#include "SystemFunctions.h"
#include "SystemFunctions.cpp"

/* This is the standard main function that will always access the menuPrompt. I chose to only return to the menu prompt because
 * I would prefer to not reprint the ascii art every time the user returns the menu*/
int main() {
    cout << "  _____                      _                     __  __                                             _   \n"
            " |_   _|                    | |                   |  \\/  |                                           | |  \n"
            "   | |  _ ____   _____ _ __ | |_ ___  _ __ _   _  | \\  / | __ _ _ __   __ _  ___ _ __ ___   ___ _ __ | |_ \n"
            "   | | | '_ \\ \\ / / _ \\ '_ \\| __/ _ \\| '__| | | | | |\\/| |/ _` | '_ \\ / _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|\n"
            "  _| |_| | | \\ V /  __/ | | | || (_) | |  | |_| | | |  | | (_| | | | | (_| |  __/ | | | | |  __/ | | | |_ \n"
            " |_____|_| |_|\\_/ \\___|_| |_|\\__\\___/|_|   \\__, | |_|  |_|\\__,_|_| |_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|\n"
            "                                            __/ |                      __/ |                              \n"
            "                                           |___/                      |___/                               \n";
    menuPrompt();
}
