#include <SFML/Graphics.hpp> 

#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{

public:
//Constructor
  Settings ();

// Getters
   sf::Vector2f getGridViewSize();
   float getVIEW_HEIGHT();

// Setters
   void setViewHeight(float newViewHeight); 
   
//sf::Vector2f size of the view to accommodate each grid size
    static const sf::Vector2f GRID8x8_VIEW_SIZE;
    static const sf::Vector2f GRID16x16_VIEW_SIZE;
    static const sf::Vector2f GRID32x32_VIEW_SIZE;
    static const sf::Vector2f GRID64x64_VIEW_SIZE;

//sf::Vector2f coordinates where the view will center for each grid value
    static const sf::Vector2f GRID8x8_VIEW_COORDS;
    static const sf::Vector2f GRID16x16_VIEW_COORDS;
    static const sf::Vector2f GRID32x32_VIEW_COORDS; 
    static const sf::Vector2f GRID64x64_VIEW_COORDS;

//clickable area for the menu item (width, height)
    static const float WIDTH_OF_MENU_RECT;
    static const float HEIGHT_OF_MENU_RECT;

//sf::Vector2f coordinates where the view will center for Main Menu
    static const sf::Vector2f MENU_VIEW_COORDS;

//Positions of clickable area (x, y)
    static const float X_POSITION_OF_MENU_RECT;
    static const float Y_POSITION_OF_MENU_RECT;

// Static view height
    static float VIEW_HEIGHT;

};


    






#endif