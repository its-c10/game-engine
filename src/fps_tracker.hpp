class FPS_Tracker {
private:
	int last_fps;
	int fps;
	double last_time_stamp;
public:
	FPS_Tracker();
	void handle_frames();
};