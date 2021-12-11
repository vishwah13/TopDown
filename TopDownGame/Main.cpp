#include"Game.h"
#include"raylib.h"



int main(void)
{ 
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int fps = 60;
    float deltaTime;

    Game game{ screenWidth,screenHeight,fps,"Humar Game" };
    game.InitGame();

    //Main app loop
    while (!game.GameWindowClose())
    {
        deltaTime = GetFrameTime();
        game.Tick(deltaTime);
    }


    return 0;
}