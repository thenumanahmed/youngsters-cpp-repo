//		selecting the menu through awsd
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "selectingMenu.h"

using namespace std;

int main()
{
    int size_of_menu = 6;
    //comment
    int choice;
    string menu_options[6] = {
        "To Buy Ticket",
        "Total Sales",
        "Total Seats Sold",
        "Total Seats Avaliable",
        "Total Seats in selected Row",
        "Quit"
    };

    SelectingMenu  homeMenu(menu_options, size_of_menu);

    choice = homeMenu.menu();

    cout << " You Have Selected " << choice << endl;
    return 0;
}

