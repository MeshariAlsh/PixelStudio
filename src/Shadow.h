#include <SFML/Graphics.hpp> 

#include <iostream>
#include <vector>


#ifndef SHADOW_H
#define SHADOW_H

class Shadow{
    public:
    Shadow( bool insideBoundary);

    void drawShadow(sf::RenderWindow& window);

    void setShadowPosition(sf::Vector2f& mousePosition, int gridSize, std::vector<std::vector<sf::RectangleShape> > cells);

    void setInsideBoundary();

    private:
    sf::RectangleShape body;
    bool insideBoundary;

};


#endif