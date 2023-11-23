class GameObject {
	double x, y;
	bool should_render;
	public:
		double getX();
		double getY();
		bool should_render();
		virtual void render();
};