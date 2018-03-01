///
/// a water object
///
#ifndef WATER_H
#define WATER_H
#pragma once
#include <string>
#include <iostream>

#include "../gfx/Textures/texture.h"

#define DEFAULT_WATER_WALK_SPEED 2 // walk speed = time it will take to walk through the water.

class water {
protected:
	int px = 0;
	int pz = 0;
	int speed = 0;
	texture waterTexture = texture(NO_TEXTURE);// Sets up a texture instance in the class
	// The water class contains:
	// * operator=
	// * get()
	// * update()
public:

	water(int _px, int _pz, int _speed, std::string _texture = NO_TEXTURE) {
		px = _px;
		pz = _pz;
		speed = _speed;
		//waterTexture.update(_texture);//Old,just testing if the other one works, this should be removed
		waterTexture = _texture;
	}
	// Check if the player is stepping in water, in which case pre from the actions
	// inside the if statment.
	void check(int x, int z) {

		if (x == px && z == pz) {
			std::cout << "player Is steping through water. This Might Take A While" << std::endl;
			sleep(speed);
		}
	}
	virtual ~water() {};
};

#endif // WATER_H
