#include <SFML/Graphics.hpp> 
#include <vector>
#include <iostream>

#ifndef GRID_H
#define GRID_H


/* This class will construct the objects the users will draw on. 
The user will choose between a 8x8, 16x16, or a 32x32 grid(canvas) */

class Grid {
    public:
 
    static constexpr int grid8x8 = 8;
    static constexpr int grid16x16 = 16;
    static constexpr int grid32x32 = 32;
    static constexpr int grid64x64 = 64;
    static constexpr int NONE = 0;

    // Constructor
    Grid( int gridSize);
    
    // Render Grid
    void Draw (sf::RenderWindow& window);

    // Method for removing colours 
    void setEraser(sf::Vector2f& cellPosition);
    
    //Method for copying the same colour 
    sf::Color setEyeDropper(sf::Vector2f& cellPosition, sf::Color& currentColor);

    // To set the colour of chosen cell 
    void setCellColor(sf::Vector2f* cellPosition, sf::Color& currentColor);
    
    // Old useless function 
    void transferCellColor (sf::Vector2f* cellPosition, sf::Color currentColor);

    // Getter for size of grid 
    int getGridSize(){ return gridSize;};
    
    // Get the 2d vector array of grid object 
    std::vector<std::vector<sf::RectangleShape> > getCells(){ return cells;};

    // Grid cells stored as vector array indexes 
    private:
     std::vector<std::vector<sf::RectangleShape> > cells;
     int gridSize; 
     
};


#endif