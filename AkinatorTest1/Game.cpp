#include "Game.h"
#include <iostream>

MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/Frighted.ttf")) {
		std::cout << "No font is here";
	}

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	//Exit
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Exit");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);

	MainMenuSelected = -1;
 }

MainMenu::~MainMenu() {

}

//Draw MainMenu
void MainMenu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}

//MoveUp
void MainMenu::MoveUp() {

	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
	
		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Yellow);
	}

}

//Move Down
void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White
		);
		MainMenuSelected++;
		if (MainMenuSelected ==4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Yellow);
	}
}

















