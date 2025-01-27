#include <SFML/Graphics.hpp> 
#include "Grid.h"
#include "Grid.h"
#include "Palette.h"
#include "Shadow.h"
#include "MainMenu.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <vector>



#ifndef UTILS_H
#define UTILS_H

// Compute the row and column based on the cell position
namespace utils 
{
 void MouseToCellCoords(sf::Vector2f& cellPosition, int& row, int& column);

 void ResizeView(const sf::RenderWindow& window, sf::View& view);

 void handlePaletteAndEraser(Grid& grid, sf::Vector2f& mousePosition);

 sf::Color eyeDropper(Grid& activeGrid, sf::Vector2f& mousePosition, sf::Color& currentColor, Palette& palette);

 void drawActiveGrid(Grid& grid, sf::Vector2f& mousePosition, sf::Color& currentColor);

 void handleShadowDraw(Grid& activeGrid, sf::Vector2f& mousePosition, Shadow& shadow );

 sf::Vector2f handleMousePosition(sf::Vector2f& MousePosition, sf::RenderWindow& window);
}

#endif