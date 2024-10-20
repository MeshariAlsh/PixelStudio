#include <SFML/Graphics.hpp> 
#include "Shadow.h"
#include "Grid.h"
#include <iostream>

// Constructor 
Shadow::Shadow( bool insideBoundary)  {

    this->insideBoundary = insideBoundary;
    body.setFillColor(sf::Color(0, 0, 0, 128));;
    body.setSize(sf::Vector2f(15.0f, 15.0f));
    
}

// Set the Shadow rect to Mouse position
void Shadow::setShadowPosition(sf::Vector2f* mousePosition, int gridSize, std::vector<std::vector<sf::RectangleShape> > cells){

    int boundary = gridSize;

    int row = (mousePosition->x - 170.0f) / 15.0f ;
    int column = (mousePosition->y - 70.0f) / 15.0f ;

    // Bounds checking to make sure mouse is within grid limits
    if (row >= 0 && row < boundary && column >= 0 && column < boundary) {

        // Set the color of the correct cell without looping through the entire grid
        body.setPosition(cells[column][row].getPosition());
        body.setOutlineThickness(0.f);
        
        insideBoundary = true; // Render shadow 
    } else {
        
        // Outside stop rendering 
        insideBoundary = false;
    }

   

};

void Shadow:: drawShadow(sf::RenderWindow& window){

   // check if insideBoundary is true or false 
    if (insideBoundary == true)
    {
        window.draw(body);
    } 
}