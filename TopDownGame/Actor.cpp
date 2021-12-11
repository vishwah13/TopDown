#include"Actor.h"

void Actor::InitActor()
{
	// Initialize player
	position.x = 20;
	position.y = 50;
	rec.width = 50;
	rec.height = 50;
	speed.x = 5;
	speed.y = 5;
	color = WHITE;
	texture = LoadTexture("resources/creature.png");
}

void Actor::UpdateActor()
{
	if (isControllable) 
	{
		// Player movement
		if (IsKeyDown(KEY_RIGHT)) position.x += speed.x;
		if (IsKeyDown(KEY_LEFT)) position.x -= speed.x;
		if (IsKeyDown(KEY_UP)) position.y -= speed.y;
		if (IsKeyDown(KEY_DOWN)) position.y += speed.y;
	}
	

	rec.x = position.x;
	rec.y = position.y;

	// Wall behaviour
	/*if (player.position.x <= 0) player.position.x = 0;
	if (player.position.x + player.position.width >= GetScreenWidth()) player.position.x = GetScreenWidth() - player.position.width;
	if (player.position.y <= 0) player.position.y = 0;
	if (player.position.y + player.position.height >= GetScreenHeight()) player.position.y = GetScreenHeight() - player.position.height;*/
}

void Actor::DrawActor()
{
	DrawRectangleRec(rec,RED);
	DrawTexture(texture, position.x, position.y, color);
}
