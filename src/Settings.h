#include <SFML/Graphics.hpp> 

#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings
{

//sf::Vector2f coordinates where the view will center for each grid value
    static const sf::Vector2f GRID8x8_VIEW_COORDS = {245.0f, 145.0f};
    static const sf::Vector2f GRID16x16_VIEW_COORDS = {290.0f, 190.0f};
    static const sf::Vector2f GRID32x32_VIEW_COORDS = {410.0f, 310.0f};
    static const sf::Vector2f GRID64x64_VIEW_COORDS = {650.0f, 550.0f};

//clickable area for the menu item (width, height)
    static const float WIDTH_OF_MENU_RECT = 145.f;
    static const float HEIGHT_OF_MENU_RECT = 50.f;

//sf::Vector2f coordinates where the view will center for Main Menu
    static const sf::Vector2f MENU_VIEW_COORDS = {79.0f, 123.0f};

//Positions of clickable area (x, y)
    static const float X_POSITION_OF_MENU_RECT = 5.f;
    static const float Y_POSITION_OF_MENU_RECT = 50.f;

// Static view height
    static const float VIEW_HEIGHT = 512.0f;
    
} 
 





#endif