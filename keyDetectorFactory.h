#include "keyDetector.h"
#include <SFML/Graphics.hpp>

#pragma once

/**
 * @class keyDetectorFactory
 * @brief Uses a static method to create the correct keyDetector derived class
 */
class keyDetectorFactory
{
public:
    static std::unique_ptr<DetectKey> createKeyDetector(sf::Keyboard::Key keyCode);
};