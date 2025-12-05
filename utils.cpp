#include "utils.h"
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <random> // For random number generation
#include <chrono> // For seeding with time

void generateSpawnPoint(Coordinates& spawnPoint)
{
    constexpr int spawnWindowMin = static_cast<int>(WINDOW_WIDTH) / 4;
    int spawnWindowMax = 0;

    if (spawnPoint.isSnake)
    {
        spawnWindowMax = static_cast<int>(WINDOW_WIDTH) / 2;
    }
    else
    {
        spawnWindowMax = static_cast<int>(WINDOW_WIDTH) - (static_cast<int>(WINDOW_WIDTH) / 4);
    }
    spawnPoint.xPos = static_cast<float>(generateRandomNumber(spawnWindowMin, spawnWindowMax));
    spawnPoint.yPos = static_cast<float>(generateRandomNumber(spawnWindowMin, spawnWindowMax));
}

int generateRandomNumber(const int min, const int max)
{
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(min, max);
    const int randomNumber = dist(rng);

    return randomNumber;
}

void spawnEntity(sf::RectangleShape& entity, const bool isSnake)
{
    try
    {
        Coordinates entitySpawnCoordinates = {0, 0, isSnake};
        generateSpawnPoint(entitySpawnCoordinates);
        std::cout << "Snake spawned at " << entitySpawnCoordinates.xPos << " " << entitySpawnCoordinates.yPos << "\n";
        entity.setPosition({entitySpawnCoordinates.xPos, entitySpawnCoordinates.yPos});

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}