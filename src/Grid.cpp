#include <SFML/Graphics.hpp> 
#include "Grid.h"
#include <iostream>
#include <vector>


/* This file will construct and render the grid(canvas). Furtheremore, destruct the objects created */

Grid:: Grid( int column){

    gridSize = column;
    
    cells.resize(column, std::vector<sf::RectangleShape>(column));

    for ( int i = 0 ; i < column ; i++){
        for ( int j = 0; j < column; j++)
        {
            
            cells[i][j].setFillColor(sf::Color::White);  // Set the color of the cell
           if ((i + j) % 2 == 0) {
            cells[i][j].setFillColor(sf::Color::White);  // White color for even  of cells
           } else {
            cells[i][j].setFillColor(sf::Color(192, 192, 192));  // Gray color for odd  of cells
           }
            cells[i][j].setSize(sf::Vector2f(15.0f, 15.0f));  // Set size of the cell
            cells[i][j].setPosition(170.0f + j * 15.0f, 80.0f + i * 15.0f);
            
        }
    }
}

// Renders the grid when called 
void Grid:: Draw (sf::RenderWindow& window)
{
    // To check which cell object is being called i.e (8x8 or 16x16)
    
      for ( int i = 0 ; i < gridSize ; i++)
      {
        for ( int j = 0; j < gridSize; j++)
        {
            window.draw(cells[i][j]);
        }
      }
}

void Grid::setCellColor(sf::Vector2f* cellPosition, sf::Color& currentColor) {
    // Compute the row and column based on the cell position
    int row = (cellPosition->x - 170.0f) / 15.0f;
    int column = (cellPosition->y - 70.0f) / 15.0f;

    // Bounds checking to make sure mouse is within grid limits
    if (row >= 0 && row < gridSize && column >= 0 && column < gridSize) {
        // Set the color of the correct cell without looping through the entire grid
        cells[column][row].setFillColor(currentColor);
    } 
}

void Grid::setEraser(sf::Vector2f& cellPosition){

  int row = (cellPosition.x - 170.0f) / 15.0f;
  int column = (cellPosition.y - 70.0f) / 15.0f;

  // Bounds checking to make sure mouse is within grid limits
    if (row >= 0 && row < gridSize && column >= 0 && column < gridSize) {

        // Set the color of the correct cell without looping through the entire grid

        if ((column + row) % 2 == 0) {
           cells[column][row].setFillColor(sf::Color::White);  // White color for even  of cells
           } else {
            cells[column][row].setFillColor(sf::Color(192, 192, 192));  // Gray color for odd  of cells
           }

    } 
}

sf::Color Grid:: setEyeDropper(sf::Vector2f& cellPosition, sf::Color& currentColor){

   int row = (cellPosition.x - 170.0f) / 15.0f ;
   int column = (cellPosition.y - 70.0f) / 15.0f ;

   if (row >= 0 && row < gridSize && column >= 0 && column < gridSize) 
   {
     currentColor = cells[column][row].getFillColor();

     return currentColor;
   } 

   return sf::Color::White;


};







 
