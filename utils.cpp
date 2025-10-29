#include "utils.h"
#include <cstdlib> 
#include <ctime>

void generateSpawnPoint(Coordinates& spawnPoint)
{
    srand(time(0));
    spawnPoint.xPos = rand() % WINDOW_WIDTH + 1;
    spawnPoint.yPos = rand() % WINDOW_HEIGHT + 1;
}