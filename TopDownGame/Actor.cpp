#include"Actor.h"

void Actor::InitActor()
{
	// Initialize player
	position.x = 20;
	position.y = 50;
	position.x = 20;
	position.y = 20;
	speed.x = 5;
	speed.y = 5;
	color = WHITE;
	texture = LoadTexture("resources/creature.png");
}

void Actor::UpdateActor()
{
	// Player movement
	if (IsKeyDown(KEY_RIGHT)) position.x += speed.x;
	if (IsKeyDown(KEY_LEFT)) position.x -= speed.x;
	if (IsKeyDown(KEY_UP)) position.y -= speed.y;
	if (IsKeyDown(KEY_DOWN)) position.y += speed.y;

	// Wall behaviour
	/*if (player.position.x <= 0) player.position.x = 0;
	if (player.position.x + player.position.width >= GetScreenWidth()) player.position.x = GetScreenWidth() - player.position.width;
	if (player.position.y <= 0) player.position.y = 0;
	if (player.position.y + player.position.height >= GetScreenHeight()) player.position.y = GetScreenHeight() - player.position.height;*/
}

void Actor::DrawActor()
{
	//DrawRectangleRec(player.position, player.color);
	DrawTexture(texture, position.x, position.y, color);
}
