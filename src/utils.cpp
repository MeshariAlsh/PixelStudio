#include <SFML/Graphics.hpp> 
#include "Grid.h"
#include <iostream>
#include <vector>

// Compute the row and column based on the cell position
namespace utils 
{
    void MouseToCellCoords(sf::Vector2f& cellPosition, int& row, int& column)
    {
    row = (cellPosition.x - 170.0f) / 15.0f;
    column = (cellPosition.y - 70.0f) / 15.0f;
    }
}