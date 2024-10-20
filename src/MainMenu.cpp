#include <SFML/Graphics.hpp> 
#include "MainMenu.h"

// Constructor 
MainMenu::MainMenu(){

    if (!myfont.loadFromFile("src/Arial.ttf"))
    {
      std::cout<< " Arial font error loading" << "\n";
    }
   
   // Number of grid options
   GridOption.resize(4);

    //TODO make this clean and readable 
    textOne.setFont(myfont);
    textTwo.setFont(myfont);
    textThree.setFont(myfont);
    textFour.setFont(myfont);
    textHeader.setFont(myfont);

    textOne.setString("8x8 ");
    textTwo.setString("16x16");
    textThree.setString("32x32");
    textFour.setString("64x64");
    textHeader.setString("Canvas");

    textOne.setCharacterSize(24); 
    textTwo.setCharacterSize(24); 
    textThree.setCharacterSize(24); 
    textFour.setCharacterSize(24); 
    textHeader.setCharacterSize(30);
    
    textOne.setFillColor(sf::Color::Red);
    textTwo.setFillColor(sf::Color::Red);
    textThree.setFillColor(sf::Color::Red);
    textFour.setFillColor(sf::Color::Red);
    textHeader.setFillColor(sf::Color::Black);
    textHeader.setOutlineThickness(1.0f);
    textHeader.setOutlineColor(sf::Color::White);

    textOne.setPosition(55.0f, 65.0f);
    textTwo.setPosition(45.0f, 110.0f);
    textThree.setPosition(50.0f, 165.0f);
    textFour.setPosition(50.0f, 215.0f);
    textHeader.setPosition(14.0f, 9.0f);



    // fix the index size of the arrys to match exatly the amount you have in the array it will look bad on github
    for ( int i = 0; i < GridOption.size(); i++)
        {
            
            GridOption[i].setFillColor(sf::Color::White);  // Set the color of the cell
            GridOption[i].setOutlineThickness(1.f);
            GridOption[i].setOutlineColor(sf::Color::Black);
            GridOption[i].setSize(sf::Vector2f(150.0f, 50.0f));  // Set size of the cell
            GridOption[i].setPosition(5.0f, 50.0f + i * 50);;
            
        }
};

void MainMenu::drawSelectedOption(sf::RenderWindow& window, bool rendering){

    if (rendering == true)
    { 

        for ( int i = 0; i < GridOption.size(); i++)
        {
            window.draw(GridOption[i]);
        }
       
        window.draw(textOne);
        window.draw(textTwo);
        window.draw(textThree);
        window.draw(textFour);
        window.draw(textHeader);
      
    } 

}