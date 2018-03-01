//
// Just any function that I might use at multible places and want to have it one place.
//

#pragma once
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
