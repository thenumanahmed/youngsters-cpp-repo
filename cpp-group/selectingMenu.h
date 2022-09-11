#pragma once

#ifndef SELECTINGMENU_H
#define SELECTINGMENU_H

#include<iostream>
#include<string>
#include<conio.h>
using namespace std;


class SelectingMenu {
private:
    string* menu_options;
    int no_of_options;
    int col_size;
    void menu_builder();
    void move_line_up(int);
    void move_line_down(int);
    void displayArrowStart();


public:
    SelectingMenu(string* menu_options, int no_of_options) {
        this->no_of_options = no_of_options;
        this->menu_options = new string[no_of_options];
        for (int i = 0; i < no_of_options; i++) {
            this->menu_options[i] = menu_options[i];
        }

        int max = 0;
        for (int i = 0; i < no_of_options; i++) {
            int string_size = sizeof(this->menu_options[i]);
            if (max < string_size) {
                max = string_size;
            }
        }

        if (max <= 30) {
            col_size = 30 + 10;
        }
        else col_size = max + 5;
    }
    int menu();
};

int SelectingMenu::menu() {
    const int position = 12;
    int count = 1;
    char value;
    //cout << "+----------------------------------------+" << endl;
    //cout << "| 1: To Buy Ticket                       |" << endl;
    //cout << "| 2: Total Sales                         |" << endl;
    //cout << "| 3: Total Seats Sold                    |" << endl;
    //cout << "| 4: Total Seats Avaliable               |" << endl;
    //cout << "| 5: Total Seats in selected Row         |" << endl;
    //cout << "| 6: Quit                                |" << endl;
    //cout << "+----------------------------------------+" << endl;
    //cout << "| Please W,S for UP,Down moving Cursor | |" << endl;
    //cout << "| Please ( F ) to Select                 |" << endl;
    //cout << "+----------------------------------------+" << endl;

    // first line 
    cout << "+";
    for (int i = 0; i < col_size + 4; i++) {
        cout << "-";
    }
    cout << "+" << endl;

    // Loop for mid things 
    // for (int i = 0; i < no_of_options; i++) {
    //     // message_builder (index,menu_option[index]); 
    // }
    
    // loop for third line
    cout << "+";
    for (int i = 0; i < col_size + 4; i++) {
        cout << "-";
    }
    cout << "+" << endl;


    cout << "| Choice =>                              |" << endl;
    // to set the cursor just right next to => of choice
    move_line_up(position - count);
    displayArrowStart();
    move_line_down(position - count - 1);
    cout << "| Choice =>" << count;
    move_line_down(1);

    while (true) {
        value = _getch();
        if (int(value) == -32) {
            continue;
        }
        else if (value == 's' || value == 'S' || int(value) == 80) {
            if (count >= 6) {
                continue;
            }
            count++;
            move_line_up(position - count + 1);
            cout << "| " << count - 1 << ": ";
            move_line_down(1);
        }
        else if (value == 'w' || value == 'W' || int(value) == 72) {
            if (count <= 1) {
                continue;
            }
            count--;
            move_line_up(position - count - 1);
            cout << "| " << count + 1 << ": ";
            move_line_up(1);
        }
        else if (value == 'f' || value == 'F' || value == 13) {
            /* cout << "selected" << count << endl;
             break;*/
            return count;
        }
        else {
            continue;
        }
        displayArrowStart();
        move_line_down(position - count - 1);
        cout << "| Choice =>" << count;
        move_line_down(1);
    }
}

void SelectingMenu::move_line_up(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << "\x1b[A";
    }
    cout << "\b\b\b\b\b\b\b\b\b\b\b\b";

}
void SelectingMenu::move_line_down(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << "\n";
    }
}
void SelectingMenu::displayArrowStart()
{
    cout << "| => ";
}


#endif