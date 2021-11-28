#pragma once
#include<raylib.h>


class Actor {

public:
	Vector2 position;
	Texture2D texture;
	float frameWidth;
	int maxframe;
	float timer = 0.0f;
	int frame = 0;
	Vector2 speed;
	Color color;

	void InitActor();
	void UpdateActor();
	void DrawActor();
private:
};


