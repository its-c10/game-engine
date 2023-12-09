class FPS_Tracker {
	int fps = 0;
	int last_fps;
	double last_time_stamp;
	public: 
		void handle_frames();
		FPS_Tracker();
		int getFPS();
};