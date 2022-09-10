//		selecting the menu through awsd
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;
void move_line_up(int);
void move_line_down(int);
void displayArrowStart();
void displayArrowEnd(int);

int main()
{
    const int position = 12;
    int count = 1;
    char value;
    cout << "+----------------------------------------+" << endl;
    cout << "| 1: To Buy Ticket                       |" << endl;
    cout << "| 2: Total Sales                         |" << endl;
    cout << "| 3: Total Seats Sold                    |" << endl;
    cout << "| 4: Total Seats Avaliable               |" << endl;
    cout << "| 5: Total Seats in selected Row         |" << endl;
    cout << "| 6: Quit                                |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "| Please W,S for UP,Down moving Cursor | |" << endl;
    cout << "| Please ( F ) to Select                 |" << endl;
    cout << "+----------------------------------------+" << endl;
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
            cout << "selected" << endl;
            break;
        }
        else {
            cout << endl << "\n\n\n\n\n wrong value" << int(value) << "--------";
            break;
        }
        displayArrowStart();
        move_line_down(position - count - 1);
        cout << "| Choice =>" << count;
        move_line_down(1);

    }
}

void move_line_up(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << "\x1b[A";
    }
    cout << "\b\b\b\b\b\b\b\b\b\b\b\b";

}
void move_line_down(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << "\n";
    }
}
void displayArrowStart()
{
    cout << "| => ";
}
void displayArrowEnd(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << "\t";
    }
    cout << "<==";
}


// 
//int main() {
//	//72 75 77 80
//	//char c;
//	//for (int i = 0; i < 100; i++) {
//	//c = _getch();
//	//cout << int(c)<< endl;
//	//}
//	char c;
//	for (int i = 0; i < 100; i++) {
//	c = _getch();
//	c = _getch();
//	cout << c<< endl;
//	}
//	/*cout << int(c) << endl;
//
//	c = _getch();
//	cout << int(c) << endl;
//	
//	c = _getch();
//	cout << int(c) << endl;
//	
//	c = _getch();
//	cout << int(c) << endl;*/
//	return 0;
//}

