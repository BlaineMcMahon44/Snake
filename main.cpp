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

    float xPos = random(800);
    float yPos = random(600);

    sf::RenderWindow window(sf::VideoMode({xAxis,yAxis}), "Snake");

    // Create rectangle and position it randomly within the grid
    sf::RectangleShape rectangle({10.0f, 10.0f});
    rectangle.setPosition({xPos, yPos});

    // Set the frame rate to 60 which is good enough for snake
    window.setFramerateLimit(60);
    
    // Run the window as long as the window is open
    while (window.isOpen())
    {
        // Check all of the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the rectangle from earlier
        window.draw(rectangle);

        // Display what we've drawn
        window.display();
    }
}