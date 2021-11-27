#include<raylib.h>
#include<assert.h>
#include"Game.h"
#include"Player.h"
#include"Cam.h"

 Player player = { 0 };
 Cam cam = { 0 };

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
	cam.InitCam(&player);

	Rectangle frameRec = { 0.0f, 0.0f, (float)player.texture.width / 6, (float)player.texture.height };
	int currentFrame = 0;

	int framesCounter = 0;
	int framesSpeed = 8;

}

void Game::Tick()
{
	BeginDrawing();
	BeginMode2D(cam.camera);
	Update();
	Draw();
	EndMode2D();
	EndDrawing();
}

void Game::Update()
{
	player.UpdatePlayer();
	cam.UpdateCameraPlayerBoundsPush(&cam.camera, &player, GetFrameTime(), GetScreenWidth(), GetScreenHeight());
}


void Game::Draw()
{
	ClearBackground(RAYWHITE);
	DrawRectangle(GetScreenWidth() / 4 * 2 - 60, 100, 120, 60, RED);
	player.DrawPlayer();
}
