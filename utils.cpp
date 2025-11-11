#include "utils.h"
#include <cstdlib> 
#include <ctime>

void generateSpawnPoint(Coordinates& spawnPoint)
{
    srand(time(nullptr));
    spawnPoint.xPos = rand() % static_cast<int>(WINDOW_WIDTH) + 1;
    spawnPoint.yPos = rand() % static_cast<int>(WINDOW_HEIGHT) + 1;
}