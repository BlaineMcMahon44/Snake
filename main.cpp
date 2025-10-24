#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>   

float random(int axis)
{
    srand(time(0));
    float randomAxis = rand() % axis + 1;
    return randomAxis;
}

int main() {
    const int xAxis {800};
    const int yAxis {600};

    float xPos = random((xAxis/2));
    float yPos = random((yAxis/2));

    float velocity {0.1};

    sf::RenderWindow window(sf::VideoMode({xAxis,yAxis}), "Snake");

    enum Direction {
        UP,    // Default value is 0
        DOWN,  // Default value is 1
        LEFT,  // Default value is 2
        RIGHT, // Default value is 3
    };

    Direction myDirection {LEFT};

    // Create rectangle and position it randomly within the grid
    sf::RectangleShape rectangle({10.0f, 10.0f});
    rectangle.setPosition({xPos, yPos});
    // Set the frame rate to 60 which is good enough for snake
    window.setFramerateLimit(60);
    sf::Vector2f movePosition {0.0, 0.0};

    // Run the window as long as the window is open
    while (window.isOpen())
    {
        // Check all of the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        
            if (event->is<sf::Event::KeyPressed>())
            {
                // Check for escape key
                const auto keyEvent = event->getIf<sf::Event::KeyPressed>();
                
                if (keyEvent && keyEvent->code == sf::Keyboard::Key::Escape)
                    window.close();

                // Check for left key
                if (keyEvent && keyEvent->code == sf::Keyboard::Key::Left)
                {
                    myDirection = Direction::LEFT;
                }

                // Check for right key
                if (keyEvent && keyEvent->code == sf::Keyboard::Key::Right)
                {
                    myDirection = Direction::RIGHT;
                }
            
                // Check for up key
                if (keyEvent && keyEvent->code == sf::Keyboard::Key::Up)
                {
                    myDirection = Direction::UP;
                }

                if (keyEvent && keyEvent->code == sf::Keyboard::Key::Down)
                {
                    myDirection = Direction::DOWN;
                }

            }
                
        }

        switch (myDirection)
        {
            case UP:
                movePosition = {0.0, -0.1};
                break;
            case DOWN:
                movePosition = {0.0, 0.1};
                break;
            case LEFT:
                movePosition = {-0.1, 0.0};
                break;
            case RIGHT:
                movePosition = {0.1, 0.0};
                break;
        };

        // Always move rectangle 
        rectangle.move(movePosition);

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the rectangle from earlier
        window.draw(rectangle);

        // Display what we've drawn
        window.display();
    }
}