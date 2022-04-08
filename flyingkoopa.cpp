#include<iostream>
using namespace std;


class flyingKoopa {
private: //private variables can only be seen/used by members of the class
	int xpos;
	int ypos;
	bool isWalking;
	int number;
public: //can be seen and used by everything in your program
	flyingKoopa(); //default constructor: initalizes all the variables in your pig
	flyingKoopa(int num); //parameterized constructor
	void walk();
	void draw();
};//---------------------------------------------------------
int main() {
	flyingKoopa p1(1); //instantiate a pig object
	flyingKoopa p2(2);
	char input;
	cout << "press a letter to start except q" << endl;
	cin >> input;
	while (input != 'q') {
		cout << "1" << endl;
		p1.walk();
		p1.draw();
		cout << "2" << endl;
		p2.walk();
		p2.draw();
		cout << "press any letter to continue but if you want to quit press q" << endl;
		cin >> input;

	}
}//end event loop----------------------------------




flyingKoopa::flyingKoopa() {
	xpos = rand() % 600 + 100;
	ypos = rand() % 600 + 100;
	isWalking = true;
}
flyingKoopa::flyingKoopa(int num) {
	xpos = rand() % 600 + 100;
	ypos = rand() % 600 + 100;
	isWalking = true;
	number = num;
}
void flyingKoopa::walk() {
	//randomly move in one of 8 directions when isWalking is true
	if (isWalking == true) {
		int num = rand() % 8 + 1;
		if (num <= 2) {
			xpos += rand() % 10;
			ypos += rand() % 10;
			cout << "I am going down and right" << endl;
		}
		else if (num <= 4) {
			xpos -= rand() % 10;
			ypos -= rand() % 10;
			cout << "I am going left and up" << endl;
		}
		else if (num <= 6) {
			xpos -= rand() % 10;
			ypos += rand() % 10;
			cout << " I am going left and down" << endl;
		}
		else if (num <= 8) {
			xpos += rand() % 10;
			ypos -= rand() % 10;
			cout << "I am going right and up" << endl;
		}
		int off = rand() % 100 + 1;

		if (off < 30) { //30% chance walking will turn off each turn
			isWalking = false;
			cout << "stopping!" << endl;
		}

		if (xpos >= 799) {
			xpos = 799;
		}

		if (xpos <= 1) {
			xpos = 1;
		}

		if (ypos >= 799) {
			ypos = 799;
		}

		if (ypos <= 1) {
			ypos = 1;
		}
	}

	//10% chance any turn that isWalking will turn ON
	int num = rand() % 100 + 1;
	if (num < 30 and isWalking == false) {
		isWalking = true;
		cout << "walking!" << endl;
	}
}


void flyingKoopa::draw() {
	//eventually this will hold drawing functions to make it graphical
	cout << "Hello I am Koopa # " << number << endl;
	cout << "My position is " << xpos << " , " << ypos << endl;
	cout << "I am ";
	if (isWalking == true) cout << " walking." << endl;
	else cout << " not walking." << endl;
	//system("pause");
}
