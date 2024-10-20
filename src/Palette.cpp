#include <SFML/Graphics.hpp> 
#include"imgui.h"
#include"imgui-SFML.h"
#include "Palette.h"
#include "Grid.h"
#include <iostream>
#include <vector>

//TODO Improve this and make it cleaner and efficient
Palette::Palette(){

    
}

//TODO make this better or develop a cleaner implementation
void Palette::setEraserOn()
{
    isEraserOn = true;
}

// Fix the Eraser issue so that when a color is chosen the eraser is turned off.
sf::Color  Palette:: setColorPicker(sf::Color& currentColor, float* color){
    
    if (ImGui::ColorPicker4("Choose Drawing Color", color)) {
        isEraserOn = false;
        isEyeDropperOn = false;
        
        currentColor = sf::Color(
            static_cast<sf::Uint8>(color[0] * 255),
            static_cast<sf::Uint8>(color[1] * 255),
            static_cast<sf::Uint8>(color[2] * 255),
            static_cast<sf::Uint8>(color[3] * 255)
        );
        return currentColor;
    }
    return currentColor;
}

bool Palette::getIsEraserOn()
{
    return isEraserOn;
}

// Eye Dropper tool
void Palette::setEyeDropperOn()
{
    isEyeDropperOn = true;
    isEraserOn = false;
}

bool Palette::getIsEyeDropperrOn()
{
    return isEyeDropperOn;
};

// TODO add comment on the importance of this method 
void Palette:: setEyeDropperOff()
{
    isEyeDropperOn = false;
};



