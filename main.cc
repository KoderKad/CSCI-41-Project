#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ncurses.h>
#include <curses.h>
#include <cstdlib>
using namespace std;

void die() {
	cout << "Invalid Input!" << endl;
	exit(1);
}

// Implementing the heap using a vector. It will serve as a max heap / priority queue
template <class T>
class Heap {
	vector<T> list;

	void bubbleUp();
	void bubbleDown();
	void swap(int child, int parent);
	int getLeftChild(int parent);
	int getRightChild(int parent);
	int getParent(int child);
  public:
	Heap();
	void Insert(T);
	T Delete();
	int getSize();

};

//using a linked list as a queue kind of.
struct node {
	int data;
	node *next;
};
class LL {
  private:
	node *head, *tail;
  public:
	LL() {
		head = NULL;
		tail = NULL;
	}
	//inserting at the tail
	void Insert(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		} else {
			tail->next = temp;
			tail = temp;
		}
	}
	// deleting at the head
	int Delete() {
		node *temp = new node;
		temp = head;
		head = head->next;
		return temp->data;
		delete temp;
	}
	void Display() {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\n";
			temp = temp->next;
		}
	}

};

int main() {

	/* LL test
	// Initializing a new list to test
	LL list;
	// loop will make a list with 10 variables ranging from 0 to 9
	for (int i = 0 ; i < 10 ; i++) {
		list.Insert(i);
	}
	// Display() will print out the list
	list.Display();
	// Delete serves as a delete and a serch function
	// it will return the value at head then delete it
	// funtioning like a queue
	for (int i = 0; i < 10; i++) {
		cout << "Head is " << list.Delete() << endl;
	}
	}
	*/
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
	printw("Graphics were created by Kehardip Dhillon, and Data Structure Implementation was done by Abdullah Qarni. Press 1 to start.");
	//get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	//creating input window
	WINDOW *inputwin = newwin(6, xMax - 12, yMax - 8, 5);
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
	if (a == '1') {
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
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (i == highlight)
				wattron(inputwin, A_REVERSE); //attrib on for specific window, color reverse
			mvwprintw(inputwin, i + 1, 1, choices[i].c_str()); //moving throughout menu, (i+1) and x=1, to prevent border fall off left. print our choice last param.
			wattroff(inputwin, A_REVERSE); //if choice highlighted, print what we want then this line turns it off
		}
		choice = wgetch(inputwin); //for user choice
		switch (choice) { //to see what they entered instead of ifs
		case KEY_UP:
			highlight--;
			if (highlight == -1) { //out of bounds check
				highlight = 0;
				break;
			}
		case KEY_DOWN:
			highlight++;
			if (highlight == 4) { //bottom checking 0,1,2,3
				highlight = 3;
				break;
			}
		default: //if user doesnt do above 2 cases
			break;
		}
		if (choice == 10) //user has entered then
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
	height = 40; //10 lines
	width = 160;
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
	
//	int n,n2 = 0;
/*
		srand (time(NULL));
		n = rand() %45 +1;
		srand (time(NULL));
		n2 = rand() % 45 + 1;
	 for (int i = 0; i < 1000; i++){
	sprintf(win,i,i,"%d\n", n);
	sprintf(win,i, i,"%d\n", n2);
	 }
	//for (int i = 0; i < 1000; i++){
	//	            printf(win, i, i, 2186769123921376027113206128370123870000005632 );
	//				        }
*/	//mvwprintw(win, 1, 1, "A, B, C, D, E, "); // window relative, so will be outputed to the (y,x) location of current box.
	wrefresh(win); //refreshes to make box line above visible
	int wait = getch(); //wait will be used for waiting for input


	getch();
	getch(); //makes sure program waits before ending.


	endwin();

	return 0;
}

template <class T>
Heap<T> :: Heap() {

}

template <class T>
int Heap<T> :: getSize() {
	return list.size();
}

template <class T>
void Heap<T>::swap(int child, int parent) {
	T temp;
	temp = list[child];
	list[child] = list[parent];
	list[parent] = temp;
}

template <class T>
int Heap<T> :: getParent(int child) {
	if (child % 2 == 0)
		return (child / 2) - 1;
	else
		return child / 2;

}

template <class T>
int Heap<T> :: getLeftChild(int parent) {
	return 2 * parent + 1;
}

template <class T>
int Heap<T> :: getRightChild(int parent) {
	return 2 * parent + 2;
}
// insets into the heap in any order than sorts it out.
template <class T>
void Heap<T> :: Insert(T value) {

	list.push_back(value);
	bubbleUp();

}
// goes up the heap making sure to maintain its requirements
template <class T>
void Heap <T>:: bubbleUp() {
	int child = list.size() - 1;
	int parent = getParent(child);

	while (list[child] > list[parent] && child >= 0 && parent >= 0) {

		swap(child, parent);
		child = parent;
		parent = getParent(child);

	}


}

// deletes the largegest Number, TOP of the max heap and returns the value
template <class T>
T Heap<T> :: Delete() {
	int child = list.size()  - 1;
	swap(child, 0);

	T value = list.back();
	list.pop_back();

	bubbleDown();

	return value;


}

//goes down the heap making sure to maintan its requirements.
template <class T>
void Heap<T> :: bubbleDown() {
	int parent = 0;

	while (1) {
		int left = getLeftChild(parent);
		int right = getRightChild(parent);
		int length = list.size();
		int largest = parent;

		if (left < length && list[left] > list[largest])
			largest = left;

		if (right < length && list[right] > list[largest])
			largest = right;

		if (largest != parent) {
			swap(largest, parent);
			parent = largest;
		} else
			break;


	}

}
/*heap testing
int main() {
	//making an array that will initialize the heap
	int a[] = {4, 5, 2, 3, 6, 7};
	//declaring our heap
	Heap<int> heap;
	// geting the size of the vector heap
	int len = sizeof(a) / sizeof(int);
	// inserting the array into the heap
	for (int i = 0; i < len; i++) {
		heap.Insert(a[i]);
	}
	// deleting and going through with the priority queue
	while (heap.getSize() > 0) {
		cout << "Heap Max\t" << heap.Delete() << endl;
		cout << "size of the heap is: " << heap.getSize() << endl;
	}


}*/
