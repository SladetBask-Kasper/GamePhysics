///
/// a water object
///
#ifndef WATER_H
#define WATER_H
#pragma once
#include <string>
#include <iostream>

#include "../gfx/Textures/texture.h"

#define DEFAULT_WATER_WALK_SPEED 2

class water {
protected:
	int px = 0;
	int pz = 0;
	int speed = 0;
	texture waterTexture = texture(NO_TEXTURE);
public:

	water(int _px, int _pz, int _speed, std::string _texture = NO_TEXTURE) {
		px = _px;
		pz = _pz;
		speed = _speed;
		waterTexture.update(_texture);
	}
	void check(int x, int z) {

		if (x == px && z == pz) {
			std::cout << "player Is steping through water. This Might Take A While" << std::endl;
			sleep(speed);
		}
	}
	virtual ~water() {};
};

#endif // WATER_H
