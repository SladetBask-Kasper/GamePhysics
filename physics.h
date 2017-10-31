#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <typeinfo>
#include <new>
#include <thread>

using namespace std;

/// if objects are enabled or not
bool objects = false;

// Posison Cordenets
int x = 1;
int z = 1;

///
/// CuPo is a fucntion that was made to print the CUrrent POsison (CURRENT PLAYER POSISON).
///
void CuPo() {
	cout << "CURRENT PLAYER X POSISON : " << x << " CURRENT PLAYER Z POSISON : " << z << endl;
}

///
/// Got Sick of Typeing CuPo every time i wanted curent Posison. Now Both work!
/// I am to lazy to remove every time CuPo was mentioned.
///
void cp() {
	CuPo();
}

///
/// initilize objects / change objects = true
///
bool init_objects() {

	if (objects == false)
		objects = true;
	else
		return false;
	return true;
}

///
/// an error function / prints something and quits
///
void err(string txt_) {

	cout << txt_ << endl;
	exit(0);
}

// Objects...

///
/// a water object
///
class water {
protected:
	int px = 0;
	int pz = 0;
	int speed = 0;
public:

	water(int _px, int _pz, int _speed) {
		px = _px;
		pz = _pz;
		speed = _speed;
	}
	void check(int x, int z) {

		if (x == px && z == pz) {
			cout << "player Is steping through water. This Might Take A While" << endl;
			sleep(speed);
		}
	}
	virtual ~water() {};
};


// </Objects>

void Load() {
	// Prints Startup Messege
	system("clear");
	cout << "\n\".help\" = For Help!" << endl << endl;
	// initilize Objects
	init_objects();

}
void Exit() {
    cout << "Bye!" << endl;
}
