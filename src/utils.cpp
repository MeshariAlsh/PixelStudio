#include <SFML/Graphics.hpp> 
#include "Grid.h"
#include "Grid.h"
#include "Palette.h"
#include "Shadow.h"
#include "MainMenu.h"
#include <iostream>
#include <vector>
#include "utils.h"
#include "Settings.h"


constexpr float X_OFFSET = 170.0f;
constexpr float Y_OFFSET = 70.0f;
constexpr float CELL_SIZE = 15.0f;

// Compute the row and column based on the cell position
namespace utils 
{
    // Converts the mouse coords to the correspondig grid cell position
    void MouseToCellCoords(sf::Vector2f& cellPosition, int& row, int& column)
    {
        row = (cellPosition.x - X_OFFSET) / CELL_SIZE;
        column = (cellPosition.y - Y_OFFSET) / CELL_SIZE;
    }

    // Handles when the widnow size is changed everthing rendered will remain the same ratio 
    void ResizeView(const sf::RenderWindow& window, sf::View& view)
    {
        float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
        view.setSize(Settings::VIEW_HEIGHT * aspectRatio, Settings::VIEW_HEIGHT);

        std::cout << "\n" <<"View size (X) "<< view.getSize().x << "View size (Y)" << view.getSize().y << std::endl;
    }

    // Erase any previous set colour on appropriate cell 
    void handlePaletteAndEraser(Grid& grid, sf::Vector2f& mousePosition)
    {
        grid.setEraser(mousePosition);
    }

    // Set current colour to a selected cell colour
    sf::Color eyeDropper(Grid& activeGrid, sf::Vector2f& mousePosition, sf::Color& currentColor, Palette& palette)
    {
        activeGrid.setEyeDropper(mousePosition, currentColor);
        palette.setEyeDropperOff();
        return currentColor;
    }

    // Set colour for appropriate cell colour
    void drawActiveGrid(Grid& grid, sf::Vector2f& mousePosition, sf::Color& currentColor) 
    {
        grid.setCellColor(mousePosition, currentColor);  // Set the cell color
    }

    // Handle where to Render Shadow body according to the active grid rendered 
    void handleShadowDraw(Grid& activeGrid, sf::Vector2f& mousePosition, Shadow& shadow )
    {
        shadow.setShadowPosition(mousePosition, activeGrid.getGridSize(), activeGrid.getCells()); // Sets Shadow body to the cell nearst the mouse 
    }

    // Gets mouse coordinates relative to the window, converts it to vector float and returns it for later coordinate calculations
    sf::Vector2f handleMousePosition(sf::Vector2f& MousePosition, sf::RenderWindow& window)
    {
        sf::Vector2i Conversion_Position = sf::Mouse::getPosition(window); 
        MousePosition = window.mapPixelToCoords(Conversion_Position);

        return MousePosition;
    }

}