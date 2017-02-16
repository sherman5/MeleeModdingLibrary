#include <mml/AI.h>

AI player2;
player2.initialized = false;
player2.port = 2;
player2.characters = FALCO || FOX;

void loadDefaultLogic()
{
    addLogic(&player2, {&chance, 0.01}, {&addMove, &player2, &shNeutralB});
}

void _main()
{
    if (!player2.initialized) { initAI(&player2);}

    if (needLogic(&player2)) { loadDefaultLogic();}

    updateAI(&player2);
}




















