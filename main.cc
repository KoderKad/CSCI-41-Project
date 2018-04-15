//#include <iostream>
//#include <queue>
//#include <algorithm>
#include <curses.h>
using namespace std;

void die() {
	cout << "Invalid Input!" << endl;
	exit(1);
}



int main() {
	/*
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

	*/
	//initscr(); //intializes the screen and sets up memory/clears screen
	//refresh(); //refreshes the screen to match whats in memory
	//getch(); //waits for user input, return int value of key
	//endwin(); //deallocates memory and ends ncurses
	//move(y, x); //moves the cursor to the specified location, y first. Moves lines based on value.
	//clear(); //clears the screen, takes no parameter.
	//WINDOW * ; //variable type which is a pointer
	//box //creates border
	//wrefresh //refreshes window we made

	initscr();
	int height, width, start_y, start_x;
	height = 10; //10 lines
	width = 20;
	start_y = 10;
	start_x = 10;
	WINDOW * win = newwin(height, width, start_y, start_x); //creates a new window which takes 4 parameters
	box(win, 0 , 0); //window, and 2 integer values as parameters, working in memory, but not being outputed until you refresh screen.
	wrefresh(win); //refreshes to make line above visible







	endwin();



	return 0;
}