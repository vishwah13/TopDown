#include<raylib.h>
#include<assert.h>
#include"Game.h"
#include"Actor.h"
#include"Cam.h"

static Actor player = { 0 };
static Actor npc = { 0 };
static Cam cam = { 0 };

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
	SCREEN_WIDTH = GetScreenWidth();
	SCREEN_HEIGHT = GetScreenHeight();

	 boxA = { 10, GetScreenHeight() / 2.0f - 50, 200, 100 };

	player.InitActor();
	player.isControllable = true;

	//npc
	npc.InitActor();
	npc.color = GREEN;
	npc.position = Vector2{ 100,120 };
	

	cam.InitCam(&player);

	//animation
	Rectangle frameRec = { 0.0f, 0.0f, (float)player.texture.width / 6, (float)player.texture.height };
	int currentFrame = 0;

	int framesCounter = 0;
	int framesSpeed = 8;

}

void Game::Tick(float deltaTime)
{
	BeginDrawing();
	BeginMode2D(cam.camera);
	Update(deltaTime);
	Draw();
	EndMode2D();
	EndDrawing();
}

void Game::Update(float deltaTime)
{
	player.UpdateActor();

	npc.UpdateActor();

	cam.UpdateCameraPlayerBoundsPush(&cam.camera, &player, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void Game::Draw()
{
	ClearBackground(RAYWHITE);
	//DrawRectangle(GetScreenWidth() / 4 * 2 - 60, 100, 120, 60, RED);
	DrawRectangleRec(boxA,BLUE);
	player.DrawActor();
	npc.DrawActor();
}
