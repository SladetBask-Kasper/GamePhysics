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


void print(string txt_ = "") {
	cout << txt_ << endl;
}
void print(int txt_ = 0) {
	cout << txt_ << endl;
}
void print(float txt_ = 0.0) {
	cout << txt_ << endl;
}
void print(double txt_ = 0.0) {
	cout << txt_ << endl;
}
void print(int * txt_ = 0) {
	cout << txt_ << endl;
}
/*void print(char * txt_ = "") {
	cout << txt_ << endl;
}*/
void print(char txt_ = 'C') {
	cout << txt_ << endl;
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

void Load() {
	// Prints Startup Messege
	system("clear");
	cout << "\n\".help\" = For Help!" << endl << endl;
	// initilize Objects
	init_objects();

}
