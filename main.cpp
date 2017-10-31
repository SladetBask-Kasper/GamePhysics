#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "physics.h"
#include "commands.h"

// constant integers that don't need to be changed!
#define FLOOR 0 // Don't CHANGE!!!!
#define ROOF 256 // The Rest can be changed a little bit.
#define XLIMITLEFT -256
#define XLIMITRIGHT 256
#define INPUTMSG "input: " // You Can Change This To What Ever U want!
#define DEFAULT_WATER_WALK_SPEED 2

using namespace std;

///
/// Makes Your Caracter Jump/Incresses z/hight cordinet.
/// Fun Fact : The Jump Function Was The First Function Created and the second one was of course gravity :)
///
bool jump() {

	z++;

	cout << "PLAYER JUMPED. ";
	CuPo();

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
		CuPo();
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
		CuPo();
	}
	else if (in == "backward" || in == "b") {

		// Stuff Left From Debuging...
		// if (x == 0)
		//	x = -250;

		x--;
		cout << "PLAYER WALKED BACKWARDS. ";
		CuPo();
	}

}

///
/// Does nothing
///
void pass() {return;}

///
/// Makes It So You Can't Walk Of The Edge Of The World.
///
bool walls() {

	if (x < XLIMITLEFT + 1) {
		cout << "There Is A Wall There My Fam. ";
		x++;
		x++;
		x++;
		cp();
	}
	if (x > XLIMITRIGHT + 1) {
		cout << "Thats A Wall Mate! ";
		x--;
		x--;
		x--;
		cp();
	}
	return true;

}

///
/// A Function That Prints Something out on the screen and then exits
/// Mainly Used For errors. Can Be used for other things.
///
bool error(string txt_arg0_) {
	cout << txt_arg0_ << endl;
	exit(0);
}

///
/// You Will Never Be able to guess what this functon does.
/// It Removes Spaces!
///
string remove_spaces(string str)
{
	for(int i=0; str[i]; i++)
		if(str[i] == ' ') str[i] = '\b';
	return str;
}

///
/// Wins.
///
/*void win() {
	if (x == winx && z == winz)
		error("YOU WIN!"); // Error Prints Something And Exits. It does not mean that it needs to be an error :)
}*/



///
/// Main fucntion. Where All The Main C0de B @.
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
	water water01(-6, FLOOR + 1, DEFAULT_WATER_WALK_SPEED);

	while (true) {

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
			system("clear");
		else if (in == "exit") {
			break;
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

			system("clear");
			break;
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

		//win();
		if (fly_gra == false)
			gravity();
		if (onc_wallz == false)
			walls();

		water01.check(x, z);

	}
	Exit();
	return EXIT_SUCCESS;
}
