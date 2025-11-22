#include "keyDetectorFactory.h"
#include "keyDetector.h"
#include <memory>

/**
 * @breif Static method that returns a std::unique_ptr that points to the correct Derived DetectKey class
 *
 * @param keyCode - sf::Keyboard::Key
 *
 * @return - std::unique_ptr to correct derived class or nullptr
 */
std::unique_ptr<DetectKey> keyDetectorFactory::createKeyDetector(const sf::Keyboard::Key keyCode)
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