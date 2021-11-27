#include"Game.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int fps = 60;

    Game game{ screenWidth,screenHeight,fps,"2D Top Down" };
    game.InitGame();

    //Main app loop
    while (!game.GameWindowClose())
    {
        game.Tick();
    }


    return 0;
}