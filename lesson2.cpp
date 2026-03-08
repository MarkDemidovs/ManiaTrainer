#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lesson 2 - Drawing Shapes");

    std::cout << "Controls:\n";
    std::cout << "  ESC → quit\n";
    std::cout << "  Resize window to see auto-adjust!\n\n";

    // ── Create shapes ONCE (outside loop) ──
    // Circle (positioned at 200,150 with radius 80)
    sf::CircleShape circle(80.f);      // radius = 80 pixels
    circle.setPosition(200.f, 150.f);  // top-left corner of bounding box

    // Rectangle (400×100, positioned near center)
    sf::RectangleShape rect(sf::Vector2f(400.f, 100.f));  // width=400, height=100
    rect.setPosition(200.f, 300.f);

    // Triangle (using ConvexShape for custom polygon)
    sf::ConvexShape triangle(3);  // 3 points = triangle
    triangle.setPoint(0, sf::Vector2f(600.f, 100.f));   // top
    triangle.setPoint(1, sf::Vector2f(500.f, 250.f));   // bottom-left
    triangle.setPoint(2, sf::Vector2f(700.f, 250.f));   // bottom-right

    // ──────────────────────────────── MAIN GAME LOOP ────────────────────────────────
    while (window.isOpen())
    {
        // ── 1. Events (same as Lesson 1) ──
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
                        window.close();
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

        // ── 2. Update (empty for now) ──

        // ── 3. RENDER: clear → draw → display ──
        window.clear(sf::Color(30, 40, 70));  // dark background

        window.draw(circle);    // Draw the circle
        window.draw(rect);      // Draw the rectangle
        window.draw(triangle);  // Draw the triangle

        window.display();
    }

    return 0;
}