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

///
/// Checks objects variable.
///
void checko() {
	if (objects != true) {
		err("\n\n\n\n\n: err : OBJECT CALLED WHILE OBJECTS NOT ALLOWED\n\n\n\n\n");
	}
}

// Objects...

///
/// a water object
///
bool water(int x, int z, int px, int pz, int speed) {

	checko();

	if (x == px && z == pz) {
		cout << "player Is steping through water. This Will Take A While" << endl;
		sleep(speed);
	}
	return true;
}

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
