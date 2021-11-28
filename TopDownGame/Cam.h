#pragma once
#include<raylib.h>

class Cam {
public:
	Camera2D camera = { 0 };
	void InitCam(class Actor* target);
	void UpdateCameraPlayerBoundsPush(Camera2D* camera, Actor* player, float delta, int width, int height);
private:
};
