#pragma once
#include<string>
#include"raylib.h"



class Game {

public:
	Game(int width, int height, int fps, std::string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;

	bool GameWindowClose() const;

	void InitGame();
	void Tick();
private:
	//Camera2D camera = { 0 };
	void Update();
	void Draw();
	//void UpdateCameraPlayerBoundsPush(Camera2D* camera, Player player, float delta, int width, int height);
};