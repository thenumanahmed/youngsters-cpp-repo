#pragma once

#ifndef SELECTINGMENU_H
#define SELECTINGMENU_H

#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;


class SelectingMenu {
private:
    string* menu_options;
    int no_of_options;
    int col_size;
    void menu_builder();
    void move_line_up(int);
    void move_line_down(int);
    void displayArrow();
    void line_break();


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
    void message_maker(string message);
};


int SelectingMenu::menu() {
    const int position = no_of_options + 4 ;
    int count = 1;
    char value;


    /////////////////////////////////////////////////////
    //  Message Body : Will Display Options            //
    /////////////////////////////////////////////////////
    line_break();
    message_maker("(W S) or Arow-Keys for Up and Down");
    message_maker("F or Enter for Selecting Option");
    line_break();
    for (int i = 0; i < no_of_options; i++) {
        message_maker( to_string(i+1) + ": " + menu_options[i] );
    }
    line_break();
    message_maker("Choice =>");
    line_break();



    /////////////////////////////////////////////////////
    // Choice Body 
    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////
    //  1 - Displaying Initial Arrow + Choice Value
    /////////////////////////////////////////////////////
        move_line_up(position - count);
        displayArrow();
        move_line_down(position - count - 2); 
        message_maker("Choice =>" + to_string(count));

    /////////////////////////////////////////////////////
    //  2- Loop to take user Input and perform following actions 
    //      a) Skip in case of junk value stored
    //      b) Return slected option value if Enter or F pressed
    //      c) if s/down pressed & not last option 
    //         then retore above value of option index ( 1: ) 
    //         and display arrow below it  
    //      d) if w/up pressed & not first option 
    //         then retore bellow value of option index ( 2: ) 
    //         and display arrow above it  
    //      e) skip if random key is pressed
    /////////////////////////////////////////////////////
    while (true) {
        value = _getch();
        if (int(value) == -32) {
            continue;
        }
        else if (value == 'f' || value == 'F' || value == 13) {
             move_line_down(1);
            return count;
        }
        else if (value == 's' || value == 'S' || int(value) == 80 && count!=no_of_options) {

            count++;
            move_line_up(position - count );
            cout << "| " << count - 1 << ": ";

            move_line_down(1);
            displayArrow();
            move_line_down(position - count -2 );
            message_maker("Choice =>" + to_string(count));
        }
        else if (value == 'w' || value == 'W' || int(value) == 72 && count!= 1) {

            count--;
            move_line_up(position - count - 2);
            cout << "| " << count + 1 << ": ";
            
            move_line_up(1);
            displayArrow();
            move_line_down(position - count -2 );
            message_maker("Choice =>" + to_string(count));
        }
        else {
            continue;
        }   
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
void SelectingMenu::displayArrow()
{
    cout << "| => ";
}

void SelectingMenu::line_break(){
cout << "+";
    for (int i = 0; i < col_size + 2; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}


void SelectingMenu::message_maker(string message){
    cout<<"| "
        <<setw(col_size)<<left<<message
        <<" |"<<endl;
}
#endif