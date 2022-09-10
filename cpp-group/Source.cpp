//		selecting the menu through awsd
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "selectingMenu.h"

using namespace std;

int main()
{
    //comment
    int choice;
    const int size_of_menu = 9;
    string menu_options[size_of_menu] = {
        "To Buy Ticket",
        "Total Sales",
        "Total Seats Sold",
        "Total Seats Avaliable",
        "Total Seats in selected Row",
        "Total Seats in selected Row",
        "Total Seats in selected Row",
        "Total Seats in selected Row",
        "Quit"
    };

    SelectingMenu  homeMenu(menu_options, size_of_menu );
    choice = homeMenu.menu();

    homeMenu.message_maker(" You Have Selected " + to_string(choice));
    return 0;
}

