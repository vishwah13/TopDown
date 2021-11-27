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
	void Update();
	void Draw();
};