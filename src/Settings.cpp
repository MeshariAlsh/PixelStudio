#include "Settings.h"

//sf::Vector2fq size of the view to accommodate each grid size
  const sf::Vector2f Settings:: GRID8x8_VIEW_SIZE =   {0.0f, 0.0f};
  const sf::Vector2f Settings:: GRID16x16_VIEW_SIZE =   {0.0f, 0.0f};
  const sf::Vector2f Settings:: GRID32x32_VIEW_SIZE = { 1200.f, 800.f}; 
  const sf::Vector2f Settings:: GRID64x64_VIEW_SIZE = { 2400.f, 1600.f};
  
//sf::Vector2fq coordinates where the view will center for each grid value
  const sf::Vector2f Settings:: GRID8x8_VIEW_COORDS = {245.0f, 145.0f};
  const sf::Vector2f Settings:: GRID16x16_VIEW_COORDS = {290.0f, 190.0f};
  const sf::Vector2f Settings:: GRID32x32_VIEW_COORDS = {410.0f, 310.0f};
  const sf::Vector2f Settings:: GRID64x64_VIEW_COORDS = {650.0f, 550.0f};

//clickable area for the menu item (width, height)
  const float Settings::WIDTH_OF_MENU_RECT = 145.f;
  const float Settings::HEIGHT_OF_MENU_RECT = 50.f;

//sf::Vector2fq coordinates where the view will center for Main Menu
  const sf::Vector2f Settings:: MENU_VIEW_COORDS = {79.0f, 123.0f};

//Positions of clickable area (x, y)
  const float Settings::X_POSITION_OF_MENU_RECT = 5.f;
  const float Settings::Y_POSITION_OF_MENU_RECT = 50.f;

// Static view height
    float Settings::VIEW_HEIGHT = 512.0f;

Settings:: Settings(){

};

void Settings:: setViewHeight(float newViewHeight){

    VIEW_HEIGHT = newViewHeight;
}; 

sf::Vector2f Settings:: getGridViewSize() {

    return GRID8x8_VIEW_SIZE;

};


float Settings:: getVIEW_HEIGHT(){

    return VIEW_HEIGHT;

};
