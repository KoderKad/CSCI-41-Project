#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ncurses.h>
#include <curses.h>
using namespace std;

void die() {
	cout << "Invalid Input!" << endl;
	exit(1);
}

int main() {
	//initscr(); //intializes the screen and sets up memory/clears screen
	//refresh(); //refreshes the screen to match whats in memory
	//getch(); //waits for user input, return int value of key
	//endwin(); //deallocates memory and ends ncurses
	//move(y, x); //moves the cursor to the specified location, y first. Moves lines based on value.
	//clear(); //clears the screen, takes no parameter.
	//WINDOW * ; //variable type which is a pointer
	//box() //basic border, creates border box (win, 1, 1); ints represent height and width (2 sides each) of square.
	//wborder(win, left, right, top, bottom, tlc, blc, brc); //creates a more customizable border
	//wrefresh //refreshes window we made
	//wprintw //takes 2 param, a window and a const char*. Can we used to output to box
	//cbreak(); //control c ends ncurses program
	//raw(); //takes in all input, not special characters. so using cntrl C wouldn't crash program. but would be typed out
	//noecho(); //whatever user inputs, doesn't get outputed to screen.
	/* -Changing color and font of text:
	// A_NORMAL A_STANDOUT A_REVERSE A_BLINK A_DIM A_BOLD A_PROTECT A_INVIS A_ALTCHARSET A_CHARTEXT
	// COLOR_PAIR(n) COLOR_NameOfColor(CAPS) Black,Red,Green,Yellow,Blue,Magenta,Cyan,White
	//attron(); //attribute on, add parameter from list above, then printw("text");
	//attroff(); //attribute off for text from list above, to turn off feature if using attron() first.
	//init_pair(); //use to create color pairs. for ex. init_pair(1, COLOR_CYAN, COLOR_WHITE); could be used through attron(COLOR_PAIR(1); then printw(text); for implementation.
	-example code-
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE); //color range is 0-999, so could be init_pair(1, 0-999, 0-999), 0-999; not all terminals can do this though. There is a code check you can complete to check.
	attron(A_STANDOUT);
	printw("cool");
	attroff(A_STANDOUT);
	getch();
	endwin();
	} */
	//getxyz(); //gets current position of cursor
	//getbegyx(); //gets top left corner (y,x) coordinate of specified window
	//getmaxyx(); //gives height and width of window
	//getyx(stdscr[standard window we do everything in], y, x); //will take declared variables and puts them into y and x
	cout << "If you would like to play the game, please input any valid letter." << endl;
	cout << "---INSTRUCTIONS---" << endl; //spit out how to play the game
	cout << "---Press any letter to continue---" << endl;
	char q = 0;
	cin >> q;
	if (!cin) die();


	initscr();
	noecho(); //hides input
	cbreak(); //control c ends program
	start_color(); //to start color functionality.
	init_pair(1, COLOR_CYAN, COLOR_BLACK); //creating color pair
	attron(COLOR_PAIR(1));
	printw("Welcome to our CSCI-41 Group Project. ");
	printw("Graphics were created by Kehardip Dhillon, and Data Structure Implementation was done by Abdullah Qarni.");
	//get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	//creating input window
	WINDOW *inputwin = newwin(6, xMax-12, yMax-8, 5);
	box(inputwin, 0, 0);
	refresh();
	char hor = '|';
	char ver = '_';
	char cor = '_';
	int le, ri, to, bo, tl, tr, bl, br;
	le = ri = (int)hor;
	to = bo = (int)ver;
	tl = tr = bl = br = (int)cor;
	wborder(inputwin, le, ri, to, bo, tl, tr, bl, br);
	wrefresh(inputwin);
	int a = wgetch(inputwin);
	if (a == '1'){
		start_color();
		init_pair(2, COLOR_CYAN, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		mvwprintw(inputwin, 1, 1, "--------WARNING: Potential Hardware Failure May Be Experienced When Using This Program. System Ready, Please Stand Back As Your Computer Is Stressed To Its Limit.---------");
		wrefresh(inputwin);
	}
	endwin();
	//using arrow keys for menu
	keypad(inputwin, true);
	string choices[4] = {"A", "B", "C", "D"};
	int choice;
	int highlight = 0;
	while(1){
		for(int i = 0; i < 4; i++){
			if(i == highlight) 
				wattron(inputwin, A_REVERSE); //attrib on for specific window, color reverse
			mvwprintw(inputwin, i+1, 1, choices[i].c_str()); //moving throughout menu, (i+1) and x=1, to prevent border fall off left. print our choice last param.
			wattroff(inputwin, A_REVERSE); //if choice highlighted, print what we want then this line turns it off
		}
		choice = wgetch(inputwin); //for user choice
		switch(choice){ //to see what they entered instead of ifs
			case KEY_UP:
				highlight--; 
				if(highlight == -1){ //out of bounds check
					highlight = 0;
				break;
				}
			case KEY_DOWN:
				highlight++;
				if(highlight == 4){ //bottom checking 0,1,2,3
					highlight = 3;
				break;
				}
			default: //if user doesnt do above 2 cases
				break;
		}
		if(choice == 10) //user has entered then
			break;
	}
	printw(" Choice selected: %s", choices[highlight].c_str());
	/* returns cursor position of specified window
	noecho();
	cbreak();
	int y, x, yBegin, xBegin, yMax, xMax;
	WINDOW *win1 = newwin(30, 30, 30, 30);
	getyx(stdscr, y, x);
	getbegyx(stdscr, yBegin, xBegin);
	getmaxyx(stdscr, yMax, xMax);
	mvprintw(yMax/2,xMax/2, "%d %d", yBegin, xBegin); //%d decimal value, Max/2 is half the screen.
	getch();
	endwin();
	return 0;
	}*/

	int height, width, start_y, start_x;
	height = 10; //10 lines
	width = 20;
	start_y = 10;
	start_x = 10;
	WINDOW *win = newwin(height, width, start_y, start_x); //creates a new window which takes 4 parameters
	refresh();
	//simple border below, went with a complex wborder version
//	box(win, (int)border, (int)border); //window, and 2 integer values as parameters, working in memory, but not being outputed until you refresh screen.
	char horizontal = '='; //used to set border design of box.
	char vertical = '=';
	char corners = '+';
	int left, right, top, bottom, tlc, trc, blc, brc; //declaring window border variables
	left = right = (int)horizontal;
	top = bottom = (int)vertical;
	tlc = trc = blc = brc = (int)corners;
	wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
	mvwprintw(win, 1, 1, "this is my box"); // window relative, so will be outputed to the (y,x) location of current box.
	wrefresh(win); //refreshes to make box line above visible
	int wait = getch(); //wait will be used for waiting for input


	getch();
	getch(); //makes sure program waits before ending.


	endwin();

	return 0;
}
