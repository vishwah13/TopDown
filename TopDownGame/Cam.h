#pragma once
#include<raylib.h>

class Cam {
public:
	Camera2D camera = { 0 };
	void InitCam(class Player* player);
	void UpdateCameraPlayerBoundsPush(Camera2D* camera, Player* player, float delta, int width, int height);
private:
};
