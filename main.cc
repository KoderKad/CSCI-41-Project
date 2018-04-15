#include <iostream>
//#include <queue>
#include <algorithm>
#include <ncurses.h>
#include <curses.h>
using namespace std;

void die() {
	cout << "Invalid Input!" << endl;
	exit(1);
}



int main() {
	
	cout << "Welcome to our Role Playing Game" << endl; //intro
	cout << "This section was created by Kehardip Dhillon." << endl;
	cout << "If you would like to play the game, please input any valid letter." << endl;
	char q = 0;
	cin >> q;
	if (!cin) die();
	cout << "---INSTRUCTIONS---" << endl; //spit out how to play the game
	cout << "---Press any letter to continue---" << endl;
	cin >> q;
	if (!cin) die();

	
	//initscr(); //intializes the screen and sets up memory/clears screen
	//refresh(); //refreshes the screen to match whats in memory
	//getch(); //waits for user input, return int value of key
	//endwin(); //deallocates memory and ends ncurses
	//move(y, x); //moves the cursor to the specified location, y first. Moves lines based on value.
	//clear(); //clears the screen, takes no parameter.
	//WINDOW * ; //variable type which is a pointer
	//box() //creates border box (win, 1, 1); ints represent height and width (2 sides each) of square.
	//wrefresh //refreshes window we made
	//wprintw //takes 2 param, a window and a const char*. Can we used to output to box
	//cbreak(); //control c ends ncurses program
	//raw(); //takes in all input, not special characters. so using cntrl C wouldn't crash program. but would be typed out
	//noecho(); //whatever user inputs, doesn't get inputed to screen.
	//
	//
		




	initscr();
	int height, width, start_y, start_x;
	height = 10; //10 lines
	width = 20;
	start_y = 10;
	start_x = 10;
	WINDOW *win = newwin(height, width, start_y, start_x); //creates a new window which takes 4 parameters
	refresh();
	char border = '-'; //used to set border design of box.
	box(win, (int)border, (int)border); //window, and 2 integer values as parameters, working in memory, but not being outputed until you refresh screen.
	mvwprintw(win, 1, 1, "this is my box"); // window relative, so will be outputed to the (0,0) location of current box.
	wrefresh(win); //refreshes to make box line above visible
	int wait = getch(); //wait will be used for waiting for input

	getch();





	endwin();



	return 0;
}
