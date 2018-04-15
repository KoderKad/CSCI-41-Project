#include <iostream>
#include <cstdlib>
using namespace std;

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
