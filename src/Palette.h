#include <SFML/Graphics.hpp> 
#include <vector>
#include <iostream>

#ifndef PALETTE_H
#define PALETTE_H


class Palette {
    public:
    Palette();
    
    sf::Color setColorPicker(sf::Color& currentColor, float* color);

    // Eraser Getter & Setter
    bool getIsEraserOn();
    void setEraserOn();
    
    // Eye Dropper  Getter & Setter
    bool getIsEyeDropperrOn();
    void setEyeDropperOn();
    void setEyeDropperOff(); // Set EyeDropper oof 
    
    private:
    bool isEraserOn;
    bool isEyeDropperOn;
    int index;
    sf::RectangleShape eraser;
    sf::Texture textureEraser;
};

#endif