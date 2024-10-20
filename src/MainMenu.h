#include <SFML/Graphics.hpp> 
#include <vector>
#include <iostream>

#ifndef MAINMENU_H
#define MAINMENU_H

class MainMenu { 
    public:
    MainMenu();
    
    void drawSelectedOption(sf::RenderWindow& window, bool check);

    private:
    std::vector<sf::RectangleShape> GridOption; 
    sf::Text textOne;
    sf::Text textTwo;
    sf::Text textThree;
    sf::Text textFour;
    sf::Text textHeader;
    sf::Font myfont;

};

#endif
