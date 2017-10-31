#include <string>

///
/// You Will Never Be able to guess what this functon does.
/// It Removes Spaces!
///
std::string remove_spaces(std::string str)
{
	for(int i=0; str[i]; i++)
		if(str[i] == ' ') str[i] = '\b';
	return str;
}

///
/// Does nothing
///
void pass() {return;}

///
/// A Function That Prints Something out on the screen and then exits
/// Mainly Used For errors. Can Be used for other things.
///
bool error(string txt_arg0_) {
	cout << txt_arg0_ << endl;
	exit(0);
}
