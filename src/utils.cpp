#include <SFML/Graphics.hpp> 
#include "Grid.h"
#include <iostream>
#include <vector>

constexpr float X_OFFSET = 170.0f;
constexpr float Y_OFFSET = 70.0f;
constexpr float CELL_SIZE = 15.0f;

// Compute the row and column based on the cell position
namespace utils 
{
    void MouseToCellCoords(sf::Vector2f& cellPosition, int& row, int& column)
    {
    row = (cellPosition.x - X_OFFSET) / CELL_SIZE;
    column = (cellPosition.y - Y_OFFSET) / CELL_SIZE;
    }
}