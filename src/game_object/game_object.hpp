#include <iostream>
#include <string>
class GameObject {
	double x, y;
	bool should_render;
	std::string identitifer;
	public:
		double getX();
		double getY();
		bool get_should_render();
		void render();
};