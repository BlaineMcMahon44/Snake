#include "keyDetectorFactory.h"
#include "keyDetector.h"
#include <memory>

/*
* return a pointer to the derived class based on the keyCode
*/
std::unique_ptr<DetectKey> keyDetectorFactory::createKeyDetector(sf::Keyboard::Key keyCode)
{
    switch(keyCode)
    {
        case(sf::Keyboard::Key::Left):
            return std::make_unique<MoveKeyLeft>();
            break;
        case(sf::Keyboard::Key::Right):
            return std::make_unique<MoveKeyRight>();
            break;
        case(sf::Keyboard::Key::Down):
            return std::make_unique<MoveKeyDown>();
            break;   
        case(sf::Keyboard::Key::Up):
            return std::make_unique<MoveKeyUp>();
            break;
        case(sf::Keyboard::Key::Escape):
            return std::make_unique<EscapeKey>();
            break;
        default:
            return nullptr;
    }
}