#define s_buffer 256
#define b_buffer 1024

bool fly_gra = false; // fly/gravety = false // Default makes flying / no gravity imposible
bool onc_wallz = false; // makes it so you cannot go pass the broder +256x and -256x

bool readInput(string in) {

	if (in == ".spawn") {
		x = 1;
		z = 1;
		cout << "You Have Been moved to spawn!" << endl;
	}
	else if (in == ".moveToWallPositive") {
		x = 255;
		z = 1;
	}
	else if (in == ".moveToWallNegative") {
		x = -255;
		z = 1;
	}
	else if (in == ".cheat-fly") {
		fly_gra = true;
	}
	else if (in == ".cheat-noclip") {
		fly_gra = true;
		onc_wallz = true;
	}
	else if (in == ".help") {

		const char *syntax =
			" * -------[Normal] Syntax------- // Nothing before syntax (For Example a dot)\n"
			" * forward : walks forwards [f, forwards]\n"
			" * backward : walks backwards [b, backwards]\n"
			" * jump : jumps [j]\n"
			" * clear : clears all the text on the screen [cls]\n"
			" * exit : exits the program []\n"
			" * clex : clears screen and exits and cleans up program (recomended) [clearexit]\n";
		const char *dotsyntax =
			" * -------[DOT] Syntax-------\n"
			" * .help : help menu\n"
			" * .spawn : retrun you to spawn\n"
			" * .cheat-noclip : Removes Gravity And Walls\n"
			" * .cheat-fly : Removes Gravity\n"
			" * .moveToWallPositive : Makes you go to the corner of the positive x cordinet!\n"
			" * .moveToWallNegative : Makes you go to the corner of the negative x cordinet!\n";
		cout << "Alternetive Commands Are Refured to with []!" << endl << endl;
		cout << syntax << endl;
		cout << endl; // Seperator
		cout << dotsyntax << endl;
	}
	else {
		cout << "INVALID [DOT] COMMAND" << endl;
	}

	return true;
}
