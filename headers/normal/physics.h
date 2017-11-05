#pragma once
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

// Posison Cordenets
int x = 1;
int z = 1;

///
/// an error function / prints something and quits
///
void err(string txt_) {

	cout << txt_ << endl;
	exit(0);
}

///
/// Consturctor called when loading program.
///
void Load() {

	// Prints Startup Messege
	system("clear");
	cout << "\n\".help\" = For Help!" << endl << endl;

}

///
/// Deconstructor called on exit.
///
void Exit() {
    cout << "Bye!" << endl;
}
///
/// A Function That Prints Something out on the screen and then exits
/// Mainly Used For errors. Can Be used for other things.
///
bool error(string txt_arg0_) {
	cout << txt_arg0_ << endl;
	Exit();
	exit(0);
}
