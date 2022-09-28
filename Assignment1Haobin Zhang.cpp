#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    sf::CircleShape shape(20.f);
   
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color(200, 150, 10));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Space key creates a screenshot
            if (event.key.code == sf::Keyboard::Space) {
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
                {
                    std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
                }
            }
        }

        // Change circle's color when mouse buttons are pressed
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                shape.setFillColor(sf::Color::Red);
            }
            else if (event.mouseButton.button == sf::Mouse::Left)
            {
                shape.setFillColor(sf::Color::Blue);
            }
            else if (event.mouseButton.button == sf::Mouse::Middle)
            {
                shape.setFillColor(sf::Color::Green);
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) 
        {
            shape.setFillColor(sf::Color::White);
        }
        
   
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                shape.setScale(shape.getScale().x + 0.005, shape.getScale().y + 0.005);
            }
            if (shape.getScale().x > 0 && shape.getScale().y > 0)
            {
                if (event.key.code == sf::Keyboard::Down)
                {
                    shape.setScale(shape.getScale().x - 0.005, shape.getScale().y - 0.005);
                }
            }
        }
      
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::PageUp)
            {
                shape.setOutlineThickness(0);
            }
            if (event.key.code == sf::Keyboard::PageDown)
            {
                shape.setOutlineThickness(1);
                shape.setOutlineColor(sf::Color(200, 150, 10));
            }
        }
     
        if (event.type == sf::Event::MouseLeft)
            window.clear();

        shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        window.draw(shape);
        window.display();

       
    }

    return 0;
}