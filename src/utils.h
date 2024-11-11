#include <SFML/Graphics.hpp> 

#include <iostream>
#include <string>
#include <vector>



#ifndef UTILS_H
#define UTILS_H

// Compute the row and column based on the cell position
namespace utils 
{
void MouseToCellCoords(sf::Vector2f& cellPosition, int& row, int& column);
}

#endif