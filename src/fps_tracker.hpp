class FPSTracker {
private:
	int lastFps = -1;
	int fps = 0;
	double lastTimeStamp;
public:
	FPSTracker();
	void handleFrames();
};