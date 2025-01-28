#include "Settings.h"

//sf::Vector2f size of the view to accommodate each grid size
  const sf::Vector2f Settings:: GRID8x8_VIEW_SIZE =   {600.0f, 800.0f};
  const sf::Vector2f Settings:: GRID16x16_VIEW_SIZE =   {600.0f, 800.0f};
  const sf::Vector2f Settings:: GRID32x32_VIEW_SIZE = { 1200.f, 800.f}; 
  const sf::Vector2f Settings:: GRID64x64_VIEW_SIZE = { 2400.f, 1600.f};
  
//sf::Vector2f coordinates where the view will center for each grid value
  const sf::Vector2f Settings:: GRID8x8_VIEW_COORDS = {245.0f, 145.0f};
  const sf::Vector2f Settings:: GRID16x16_VIEW_COORDS = {290.0f, 190.0f};
  const sf::Vector2f Settings:: GRID32x32_VIEW_COORDS = {410.0f, 310.0f};
  const sf::Vector2f Settings:: GRID64x64_VIEW_COORDS = {650.0f, 550.0f};

//clickable area for the menu item (width, height)
 
  const sf::Vector2f Settings::WIDTH_AND_HEIGHT_OF_MENU_BUTTON = {200.f, 50.f};

//sf::Vector2f coordinates where the view will center for Main Menu
  const sf::Vector2f Settings:: MENU_VIEW_COORDS = {79.0f, 123.0f};

//Positions of clickable area (x, y)
  const float Settings::X_POSITION_OF_MENU_RECT = 260.f;
  const float Settings::Y_POSITION_OF_MENU_RECT = 185.f;

//Positions of the button on the Imgui window

const sf::Vector2f  Settings::button_For_GRID8x8 = {50,25};
const sf::Vector2f  Settings::button_For_GRID16x16 = {50,80};
const sf::Vector2f  Settings::button_For_GRID32x32 = {50,135};
const sf::Vector2f  Settings::button_For_GRID64x64 = {50,190};
const sf::Vector2f  Settings::button_For_CustomGRID = {50,245};


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
