#include <SFML/Graphics.hpp> 
#include"imgui.h"
#include"imgui-SFML.h"
#include <iostream>
#include "Grid.h"
#include "Palette.h"
#include "Shadow.h"
#include "MainMenu.h"

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

// Handles the when the widnow size is changed everthing rendered will remain the same ratio 
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
  float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
  view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
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
  grid.setCellColor(&mousePosition, currentColor);  // Set the cell color
}

// Handle where to Render Shadow body according to the active grid rendered 
void handleShadowDraw(Grid& activeGrid, sf::Vector2f& mousePosition, Shadow& shadow )
{
  shadow.setShadowPosition(&mousePosition, activeGrid.getGridSize(), activeGrid.getCells()); // Sets Shadow body to the cell nearst the mouse 
}

// Gets mouse coordinates relative to the window, converts it to vector float and returns it for later coordinate calculations
sf::Vector2f handleMousePosition(sf::Vector2f& MousePosition, sf::RenderWindow& window)
{
  sf::Vector2i Conversion_Position = sf::Mouse::getPosition(window); 
  MousePosition = window.mapPixelToCoords(Conversion_Position);

  return MousePosition;
}


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), " Pixel Creation & Editing Software ");
  sf::View view (sf::Vector2f(MENU_VIEW_COORDS), sf::Vector2f(0.0f, 0.0f));

  if (!ImGui::SFML::Init(window)) 
  {
    std::cerr << "Failed to initialize ImGui-SFML." << std::endl;
    return -1;  // Exit if initialization failed
  }
  // To track user mouse for inputs
  sf::Vector2f MousePosition;
  
  // To Construct the Grid 
  Grid activeGrid = Grid(Grid::NONE);;

  // Shadow bool to handle rendering
  Shadow shadow(false);

  // MainMenu  
  struct MenuOption 
  {
    sf::FloatRect boundarys;
    sf::Vector2f viewCenter;
    Grid setActiveGrid;
  };

  // Initialize menu options for grid selection.
  // 1. sf::FloatRect clickable area for the menu item (x, y, width, height)
  // 2. sf::Vector2f coordinates where the view will center when the option is selected
  // 3. activeGrid Sets the active grid to the corresponding grid size when the option is chosen
  std::vector<MenuOption> menuOptions = 
  {
    { sf::FloatRect(X_POSITION_OF_MENU_RECT , Y_POSITION_OF_MENU_RECT         , WIDTH_OF_MENU_RECT , HEIGHT_OF_MENU_RECT), GRID8x8_VIEW_COORDS, Grid::grid8x8},
    { sf::FloatRect(X_POSITION_OF_MENU_RECT , Y_POSITION_OF_MENU_RECT + 50.f  , WIDTH_OF_MENU_RECT , HEIGHT_OF_MENU_RECT), GRID16x16_VIEW_COORDS, Grid::grid16x16},
    { sf::FloatRect(X_POSITION_OF_MENU_RECT , Y_POSITION_OF_MENU_RECT + 100.f , WIDTH_OF_MENU_RECT , HEIGHT_OF_MENU_RECT), GRID32x32_VIEW_COORDS, Grid::grid32x32},
    { sf::FloatRect(X_POSITION_OF_MENU_RECT , Y_POSITION_OF_MENU_RECT + 150.f , WIDTH_OF_MENU_RECT , HEIGHT_OF_MENU_RECT), GRID64x64_VIEW_COORDS, Grid::grid64x64}
  };

  //Bool to handle rendering
  bool isMainMenuRendering = true;
  MainMenu MainMenu; 

  //Bool to handle rendering
  bool isPaletteRendering = false;
  Palette palette;

  sf::Color currentColor = sf::Color::Black;
  float color[4] = { currentColor.r / 255.f, currentColor.g / 255.f, currentColor.b / 255.f, currentColor.a / 255.f };

  // For updating imgui 
  sf::Clock deltaClock;

  // main loop
    while (window.isOpen()) {

       sf::Event event;

       while (window.pollEvent(event)) 
       {
        ImGui::SFML::ProcessEvent(window, event);

       if (event.type == sf::Event::Closed)
       {
         window.close();
       }
       if (sf::Event::Resized)
       {
        ResizeView(window, view);
       }
       
       // Mouse Events

       // Mouse Single Click Events 
       if (event.type == sf::Event::MouseButtonPressed)
         {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
              
               //Handles Mouse position  
               handleMousePosition(MousePosition,  window);

               if (isMainMenuRendering == true)
               {
                 for (const auto& option : menuOptions) 
                 {
                  if (option.boundarys.contains(MousePosition)) 
                  {
                    view.setCenter(option.viewCenter); // Center the view on the selected grid
                    activeGrid = option.setActiveGrid;
                    isMainMenuRendering = false;
                    isPaletteRendering = true;
                  break;  // Exit the loop after a selection
                  }
                }
               }

              // For coloring, erasing, or copying the color of a single cell with a click 
                if (palette.getIsEraserOn() == true)
                {
                  handlePaletteAndEraser(activeGrid, MousePosition);
                } 
                if (palette.getIsEyeDropperrOn() == true && palette.getIsEraserOn() == false )
                {
                  eyeDropper( activeGrid ,MousePosition ,currentColor, palette);
                }
                else
                {
                   drawActiveGrid(activeGrid, MousePosition, currentColor);
                }
            }
         }

         // Mouse Continues Movement Updates Events 
         if (event.type == sf::Event::MouseMoved &&  isMainMenuRendering == false)
          {
            //Handles Mouse position 
           handleMousePosition(MousePosition,  window);

           // Handles the position where the shadow body will render
            handleShadowDraw(activeGrid, MousePosition, shadow);
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
              {
                if (palette.getIsEraserOn() == true){
                  handlePaletteAndEraser(activeGrid, MousePosition);
                } 
                else
                {
                   drawActiveGrid(activeGrid, MousePosition, currentColor);
                }
              } 
              
          }    
       } 

       ImGui::SFML::Update(window, deltaClock.restart());

       if (!isMainMenuRendering) {

          // Define window flags for the top panel
          ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar
                                      | ImGuiWindowFlags_NoResize
                                      | ImGuiWindowFlags_NoMove
                                      | ImGuiWindowFlags_NoCollapse
                                      | ImGuiWindowFlags_NoScrollbar
                                      | ImGuiWindowFlags_NoSavedSettings;

          // Set position and size for the top panel
          ImGui::SetNextWindowPos(ImVec2(0, 0));  
          ImGui::SetNextWindowSize(ImVec2(window.getSize().x, 50));  

          // Begin the ImGui panel
          ImGui::Begin("Top Panel", nullptr, window_flags);

          // top panel text
           ImGui::Text("Top Panel - ImGui + SFML");

           if (ImGui::Button("Eraser"))
           {
            palette.setEraserOn();   
           }

           ImGui::SameLine();

           if (ImGui::Button("Eye Dropper"))
           {
            palette.setEyeDropperOn();
           }
           ImGui::End();  
       }

       // ** Future Menu from Imgui will go here ** 

       window.clear(sf::Color(150,150,150));
    
       // Render everything
       MainMenu.drawSelectedOption(window, isMainMenuRendering);
       if (activeGrid.getGridSize() == 32)
       {
         view.setSize(1200.f, 800.f);
         activeGrid.Draw(window); 
       } else if (activeGrid.getGridSize() == 64)
       {
         view.setSize(2400.f, 1600.f);
         activeGrid.Draw(window); 
       } 
       activeGrid.Draw(window); 
       shadow.drawShadow(window);
       window.setView(view);
     
       // Only render the color picker if the main menu is no longer being rendered
        if (!isMainMenuRendering) {
            ImGui::Begin("Color Picker");

            palette.setColorPicker(currentColor, color);
            ImGui::End();
        }

       ImGui::SFML::Render(window);
       window.display();
    }


    ImGui::SFML::Shutdown();
    return 0;
}
