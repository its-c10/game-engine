class Vec2 {
	float x;
	float y;
	public:
		Vec2();
		Vec2(float x, float y);
		float getX();
		float getY();
		float dot(Vec2 vec);
		Vec2 add(Vec2 vec);
};