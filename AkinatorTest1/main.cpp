#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game.h"

void main() {

	//Make a Main Window

	sf::RenderWindow MENU(sf::VideoMode(960, 720), "Main MEnu", sf::Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//SEt backgraund
	sf::RectangleShape Pbackgraund;
	Pbackgraund.setSize(sf::Vector2f(960, 720));
	sf::Texture MainTexture;
	MainTexture.loadFromFile("Textures/1.jpg");
	Pbackgraund.setTexture(&MainTexture);
	
	while (MENU.isOpen())
	{
		sf::Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				MENU.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					sf::RenderWindow Play(sf::VideoMode(960, 720), "Akinator");
				
					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (Play.isOpen()) {
							sf::Event aevent;
							
							while (Play.pollEvent(aevent)) {
								if (aevent.type == sf::Event::Closed) {

									Play.close();
								}
								if (aevent.type == sf::Event::KeyPressed)
								{
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										Play.close();
									}
								}
							}
							Play.clear();
							Play.draw(Pbackgraund);
							Play.display();
						}
					}
					if (x == 2)
					{
						MENU.close();
						break;
					}
				}
		
			}
			MENU.clear();
			mainMenu.draw(MENU);
			MENU.display();
		}

	}
	
}








