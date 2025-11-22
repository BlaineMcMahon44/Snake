#pragma once
#include "keyDetector.h"
#include <SFML/Graphics.hpp>

/**
 * @class keyDetectorFactory
 *
 * @brief Uses a static method to create the correct keyDetector derived class
 */
class keyDetectorFactory
{
public:
    static std::unique_ptr<DetectKey> createKeyDetector(const sf::Keyboard::Key keyCode);
};