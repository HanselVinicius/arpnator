#include <SFML/Graphics.hpp>
#include "../headers/ArpService.hpp"
#include <iostream>
using namespace sf;

void prepareUi(RenderWindow& window);

void drawUi(){
    RenderWindow window(VideoMode(800, 600), "Minha Janela SFML");
    prepareUi(window);
}

void prepareUi(RenderWindow& window){
    while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
            }
            window.clear(Color::White);
            window.display();
    }
}

