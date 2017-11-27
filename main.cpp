///
/// Note: This is the file you wanna compile.
///

// standard includes
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// normal files
#include "headers/normal/physics.h"
#include "headers/normal/commands.h"
#include "headers/normal/functions.h"

// objects
#include "headers/objects/water.h"

// gfx

// constant integers that don't need to be changed!
#define FLOOR 0 // Don't CHANGE!!!!
#define ROOF 256 // The Rest can be changed a little bit.
#define XLIMITLEFT -256
#define XLIMITRIGHT 256
#define INPUTMSG "input: " // You Can Change This To What Ever U want!
#define CLEAR_SCREEN "clear" // On win32 cange to "cls"

using namespace std;

///
/// cp is a function that was made to print the Current Posison (CURRENT PLAYER POSISON).
///
void cp() {
	cout << "CURRENT PLAYER X POSISON : " << x << " CURRENT PLAYER Z POSISON : " << z << endl;
}

///
/// Makes Your Caracter Jump/Incresses z/hight cordinet.
/// Fun Fact : The Jump Function Was The First Function Created and the second one was of course gravity :)
///
bool jump() {

	z++;

	cout << "PLAYER JUMPED. ";
	cp();

	return true;
}

///
/// The Laws Of Gravity.
///
bool gravity() {

	if (z > FLOOR + 1) {
		cout << "PLAYER IS FALLING... ";
		z--;
		sleep(1);
		cout << "PLAYER LANDED. ";
		cp();
	}

	return true;
}

///
/// Makes You Caracter Walk/Incresses x/floor Cordenet
///
void walk(string in) {

	if (in == "forward" || in == "f") {

		// Stuff Left From Debuging...
		//if (x == 0)
		//	x = 250;

		x++;
		cout << "PLAYER WALKED FORWARDS. ";
		cp();
	}
	else if (in == "backward" || in == "b") {

		// Stuff Left From Debuging...
		//if (x == 0)
		//	x = -250;

		x--;
		cout << "PLAYER WALKED BACKWARDS. ";
		cp();
	}

}

///
/// Makes It So You Can't Walk Of The Edge Of The World.
///
bool walls() {

	if (x < XLIMITLEFT + 1) {
		cout << "There Is A Wall There My Fam. ";
		x++;
		x++;
		cp();
	}
	if (x > XLIMITRIGHT + 1) {
		cout << "Thats A Wall Mate! ";
		x--;
		x--;
		cp();
	}
	return true;

}

///
/// Main fucntion. Where All The Main C0D3 B @.
///
int main() {

	if (FLOOR != 0)
		error("TO LOW/HIGH FLOOR");
	if (XLIMITLEFT > 0)
		error("xL TO SMALL World");
	if (XLIMITRIGHT < 1)
		error("xR TO SMALL World");
	if (ROOF < 1)
		error("ROOF TO SMALL World");

	string in = "";

	// Initilize / Load Main Stuffz
	Load();

	// Place Down Objects...
	water water01(-6, FLOOR + 1, DEFAULT_WATER_WALK_SPEED, NO_TEXTURE);

	while (!ExitStatus) {

		cout << INPUTMSG;
		getline(cin, in);

		in = remove_spaces(in);

		//cout << "INPUT RECIVED : '" << in << "'" << endl;

		if (in == "jump" || in == "j")
			jump();
		else if (in == "forward" || in == "f" || in == "forwards")
			walk(in);
		else if (in == "backward" || in == "b" || in == "backwards")
			walk(in);
		else if (in == "clear" || in == "cls")
			system(CLEAR_SCREEN);
		else if (in == "exit") {
			ExitStatus = true;
		}
		else if (in == "reset_cord" || in == "rc") {
			x = 1;
			z = 1;
			cout << "Cordenets Reset. ";
			cp();
		}
		else if (in == "clearexit" || in == "clex") {
			x = 0;
			z = 0;
			in = "";

			system(CLEAR_SCREEN);
			ExitStatus = true;
		}
		else if (in[0] == '#') {
			in = "";
		}
		else if (in == "") {
			pass();
		}
		else if (in[0] == '.') {
			readInput(in);
		}
		else if (in == "getCord") {
			cp();
		}
		else
			cout << "INVALID COMMAND..." << endl;

		if (fly_gra == false)
			gravity();
		if (onc_wallz == false)
			walls();

		water01.check(x, z);
	}
	Exit();
	return EXIT_SUCCESS;
}
