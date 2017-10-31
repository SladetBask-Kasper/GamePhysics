#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "physics.h"
#include "commands.h"
//#include "basic.hpp" // basic.hpp used to be a testing playground!

// constant integers that don't need to be changed!
#define floor 0 // Don't CHANGE!!!!
#define roof 256 // The Rest can be changed a little bit.
#define xlimitLeft -256
#define xlimitRight 256
#define inputMsg "input: " // You Can Change This To What Ever U want!

using namespace std;

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

	if (z > floor + 1) {
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
/// Makes It So You Can't Walk Of The Edge Of The World.
///
bool walls() {

	if (x < xlimitLeft + 1) {
		cout << "There Is A Wall There My Fam. ";
		x++;
		x++;
		x++;
		cp();
	}
	if (x > xlimitRight + 1) {
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
 //&input.erase(std::remove(input.begin(),input.end(),' '),input.end());
	//auto rs = std::regex_replace(input,std::regex("\\s+"), "");
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

string tux() {
	cout << "Linux Is The Best!" << endl;
	return "Linux Is The Best!";
}

///
/// Main fucntion. Where All The Main C0de B @.
///
int main() {

	if (floor != 0)
		error("TO LOW/HIGH FLOOR");
	if (xlimitLeft > 0)
		error("xL TO SMALL World");
	if (xlimitRight < 1)
		error("xR TO SMALL World");
	if (roof < 1)
		error("ROOF TO SMALL World");

	string in = "";

	// Initilize / Load Main Stuffz
	Load();

	// Place Down Objects...

	bool water01 = water(-6, floor + 1, x, z, 3);
	if (water01 == false) {
		error("WATER ERORR");
	}

	while (true) {

		cout << inputMsg;
		//cin >> in;
		getline(cin, in);
		//cout << endl;

		//if (ifht(in) == true)
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
			return 0;
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
			return 0;
		}
		else if (in[0] == '#') {
			in = "";
			//cout << "found '#'..." << endl; // <-- Debug Stuff
		}
		else if (in == "") {

		}
		else if (in == "tux()") {
			tux();
		}
		else if (in[0] == '.') { // .at(0)
			//cout << "Found \".\" | " << in[0] << " | " << in << endl;
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

		water01 = water(-6, floor + 1, x, z, 2);
		if (water01 == false) {
			error("WATER ERROR");
		}


		//cout << endl;

	}
}
//
