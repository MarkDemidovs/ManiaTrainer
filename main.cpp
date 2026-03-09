#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

    int score {0};
    sf::RenderWindow window(sf::VideoMode(800, 800), "click the circles");
    window.setFramerateLimit(60);

    sf::CircleShape circleQ(40.f);
    circleQ.setPosition(100.f, 600.f);

    sf::CircleShape circleW(40.f);
    circleW.setPosition(200.f, 600.f);

    sf::CircleShape circleO(40.f);
    circleO.setPosition(300.f, 600.f);

    sf::CircleShape circleP(40.f);
    circleP.setPosition(400.f, 600.f);

    sf::CircleShape note(40.f);
    note.setPosition(100.f, 0.f);
    note.setFillColor(sf::Color::Blue);

    sf::Font font;
    font.loadFromFile("regular.ttf");

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("0");
    scoreText.setPosition(10.f, 10.f);
    while (window.isOpen())
    {
        sf::Event event;
        note.move(0.f, 25.f);

        if (note.getPosition().y > 800)
        {
            note.setPosition((rand() % 4 + 1) * 100, 0.f);
        }

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Q)
                    circleQ.setFillColor(sf::Color::Yellow);
                if (event.key.code == sf::Keyboard::Q && note.getPosition().y > 300 && note.getPosition().y < 700 && note.getPosition().x == 100)
                {
                    std::cout << "okay, ill let this one pass.." << '\n';
                    note.setPosition((rand() % 4 + 1) * 100, 0.f);
                    score+=100;
                    scoreText.setString(std::to_string(score));
                }

                if (event.key.code == sf::Keyboard::W)
                    circleW.setFillColor(sf::Color::Yellow);
                if (event.key.code == sf::Keyboard::W && note.getPosition().y > 300 && note.getPosition().y < 700 && note.getPosition().x == 200)
                {
                    std::cout << "okay, ill let this one pass.." << '\n';
                    note.setPosition((rand() % 4 + 1) * 100, 0.f);
                    score+=100;
                    scoreText.setString(std::to_string(score));
                }

                if (event.key.code == sf::Keyboard::O)
                    circleO.setFillColor(sf::Color::Yellow);
                if (event.key.code == sf::Keyboard::O && note.getPosition().y > 300 && note.getPosition().y < 700 && note.getPosition().x == 300)
                {
                    std::cout << "okay, ill let this one pass.." << '\n';
                    note.setPosition((rand() % 4 + 1) * 100, 0.f);
                    score+=100;
                    scoreText.setString(std::to_string(score));
                }
                if (event.key.code == sf::Keyboard::P)
                    circleP.setFillColor(sf::Color::Yellow);
                if (event.key.code == sf::Keyboard::P && note.getPosition().y > 300 && note.getPosition().y < 700 && note.getPosition().x == 400)
                {
                    std::cout << "okay, ill let this one pass.." << '\n';
                    note.setPosition((rand() % 4 + 1) * 100, 0.f);
                    score+=100;
                    scoreText.setString(std::to_string(score));
                }
                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Q)
                    circleQ.setFillColor(sf::Color::White);
                if (event.key.code == sf::Keyboard::W)
                    circleW.setFillColor(sf::Color::White);
                if (event.key.code == sf::Keyboard::O)
                    circleO.setFillColor(sf::Color::White);
                if (event.key.code == sf::Keyboard::P)
                    circleP.setFillColor(sf::Color::White);
                break;

            default:
                break;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(circleQ);
        window.draw(circleW);
        window.draw(circleO);
        window.draw(circleP);
        window.draw(note);
        window.draw(scoreText);

        window.display();
    }
    return 0;
}