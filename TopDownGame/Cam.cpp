#include "Cam.h"
#include"Player.h"

void Cam::InitCam(Player* player)
{
	camera.target = Vector2{ player->position.x,player->position.y };
	camera.offset = Vector2{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
}

void Cam::UpdateCameraPlayerBoundsPush(Camera2D* camera, Player* player, float delta, int width, int height)
{
	static Vector2 bbox = { 0.2f, 0.2f };

	Vector2 bboxWorldMin = GetScreenToWorld2D(Vector2{ (1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height }, *camera);
	Vector2 bboxWorldMax = GetScreenToWorld2D(Vector2{ (1 + bbox.x) * 0.5f * width, (1 + bbox.y) * 0.5f * height }, *camera);
	camera->offset = Vector2{ (1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height };

	if (player->position.x < bboxWorldMin.x) camera->target.x = player->position.x;
	if (player->position.y < bboxWorldMin.y) camera->target.y = player->position.y;
	if (player->position.x > bboxWorldMax.x) camera->target.x = bboxWorldMin.x + (player->position.x - bboxWorldMax.x);
	if (player->position.y > bboxWorldMax.y) camera->target.y = bboxWorldMin.y + (player->position.y - bboxWorldMax.y);
}
