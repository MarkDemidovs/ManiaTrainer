#include <SFML/Graphics.hpp>
#include <iostream>

void checkPressed(sf::Keyboard::Key key, float position, sf::CircleShape &note, int &score, int &combo, sf::Text &scoreText, sf::Text &comboText, sf::CircleShape &circle, sf::Event &event, float &speed, sf::Text &speedText)
{
    if (event.key.code == key && note.getPosition().y > 300 && note.getPosition().y < 700 && note.getPosition().x == position)
    {
        note.setPosition((rand() % 4 + 1) * 100, 0.f);

        combo++;
        score += 100 * combo;
        scoreText.setString(std::to_string(score));
        comboText.setString(std::to_string(combo));
        speedText.setString(std::to_string(speed));
        if (combo % 5 == 0) {
            speed++;
        } 
    }
}

int main()
{

    int score{0};
    int combo{0};
    float speed{5.f};

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
    scoreText.setPosition(600.f, 10.f);

    sf::Text comboText;
    comboText.setFont(font);
    comboText.setString("0");
    comboText.setPosition(600.f, 80.f);

    sf::Text speedText;
    speedText.setFont(font);
    speedText.setString("5");
    speedText.setPosition(600.f, 160);

    while (window.isOpen())
    {
        sf::Event event;
        note.move(0.f, speed);

        if (note.getPosition().y > 800)
        {
            note.setPosition((rand() % 4 + 1) * 100, 0.f);
            score -= 100;
            speed--;
            combo = 0;
            scoreText.setString(std::to_string(score));
            comboText.setString(std::to_string(combo));
        }
        if (score <= 0)
        {
            score = 0;
            scoreText.setString(std::to_string(score));
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
                checkPressed(sf::Keyboard::Q, 100.f, note, score, combo, scoreText, comboText, circleQ, event, speed, speedText);

                if (event.key.code == sf::Keyboard::W)
                    circleW.setFillColor(sf::Color::Yellow);
                checkPressed(sf::Keyboard::W, 200.f, note, score, combo, scoreText, comboText, circleW, event, speed, speedText);

                if (event.key.code == sf::Keyboard::O)
                    circleO.setFillColor(sf::Color::Yellow);
                checkPressed(sf::Keyboard::O, 300.f, note, score, combo, scoreText, comboText, circleO, event, speed, speedText);
                if (event.key.code == sf::Keyboard::P)
                    circleP.setFillColor(sf::Color::Yellow);
                checkPressed(sf::Keyboard::P, 400.f, note, score, combo, scoreText, comboText, circleP, event, speed, speedText);
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
        window.draw(comboText);
        window.draw(speedText);

        window.display();
    }
    return 0;
}