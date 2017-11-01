///
/// a water object
///
#include <string>
#include <iostream>

class water {
protected:
	int px = 0;
	int pz = 0;
	int speed = 0;
	std::string texture = "headers/gfx/Textures/std/untextured.jpg";
public:

	water(int _px, int _pz, int _speed, std::string _texture = "headers/gfx/Textures/std/untextured.jpg") {
		px = _px;
		pz = _pz;
		speed = _speed;
		texture = _texture;
	}
	void check(int x, int z) {

		if (x == px && z == pz) {
			std::cout << "player Is steping through water. This Might Take A While" << std::endl;
			sleep(speed);
		}
	}
	virtual ~water() {};
};
