#include<raylib.h>
#include<assert.h>
#include"Game.h"
#include"Player.h"


static Player player = { 0 };

Game::Game(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
	assert(GetWindowHandle());
	UnloadTexture(player.texture);
	CloseWindow();
}

bool Game::GameWindowClose() const
{
	return WindowShouldClose();
}

void Game::InitGame()
{
	player.PlayerInit();

	Rectangle frameRec = { 0.0f, 0.0f, (float)player.texture.width / 6, (float)player.texture.height };
	int currentFrame = 0;

	int framesCounter = 0;
	int framesSpeed = 8;

	//camera
	/*camera.target = Vector2{player.position.x,player.position.y};
	camera.offset = Vector2{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;*/
}

void Game::Tick()
{
	BeginDrawing();
	Update();
	//UpdateCameraPlayerBoundsPush(&camera, player, GetFrameTime(), GetScreenWidth(), GetScreenHeight());
	Draw();
	EndDrawing();
}

void Game::Update()
{
	player.UpdatePlayer();
}


void Game::Draw()
{
	ClearBackground(RAYWHITE);
	player.DrawPlayer();
}

//void Game::UpdateCameraPlayerBoundsPush(Camera2D* camera, Player player, float delta, int width, int height)
//{
//	static Vector2 bbox = { 0.2f, 0.2f };
//
//	Vector2 bboxWorldMin = GetScreenToWorld2D(Vector2 { (1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height }, * camera);
//	Vector2 bboxWorldMax = GetScreenToWorld2D(Vector2 { (1 + bbox.x) * 0.5f * width, (1 + bbox.y) * 0.5f * height }, * camera);
//	camera->offset = Vector2{ (1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height };
//
//	if (player.position.x < bboxWorldMin.x) camera->target.x = player.position.x;
//	if (player.position.y < bboxWorldMin.y) camera->target.y = player.position.y;
//	if (player.position.x > bboxWorldMax.x) camera->target.x = bboxWorldMin.x + (player.position.x - bboxWorldMax.x);
//	if (player.position.y > bboxWorldMax.y) camera->target.y = bboxWorldMin.y + (player.position.y - bboxWorldMax.y);
//}
