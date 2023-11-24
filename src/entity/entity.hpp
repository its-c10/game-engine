#include <iostream>
#include <string>
class Entity {
	double x, y;
	bool render;
	std::string identitifer;
	public:
		double getX();
		double getY();
		bool should_render();
		void render();
};