#pragma once
#include<string>
#include"raylib.h"


class Game {

public:
	Game(int width, int height, int fps, std::string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	bool GameWindowClose() const;

	void InitGame();
	void Tick(float deltaTime);
private:
	void Update(float deltaTime);
	void Draw();

	//for testing collision
	Rectangle boxA;
};