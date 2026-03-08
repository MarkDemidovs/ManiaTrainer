#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "Pressed escape!!!" << '\n';
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Space)
                {
                    std::cout << "SPACE Pressed!'\n";
                }
                break;
            case sf::Event::Resized:
            {
                sf::FloatRect visibleArea(0.f, 0.f,
                                          static_cast<float>(event.size.width),
                                          static_cast<float>(event.size.height));
                window.setView(sf::View(visibleArea));
            }
            break;
            
            default:
                break;
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}