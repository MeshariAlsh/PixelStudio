#include <SFML/Graphics.hpp> 
#include"imgui.h"
#include"imgui-SFML.h"
#include <iostream>
#include "Grid.h"
#include "Palette.h"
#include "Shadow.h"
#include "MainMenu.h"
#include "utils.h"
#include "Settings.h"
#include <string>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), " Pixel Creation & Editing Software ");
  sf::View view (sf::Vector2f(Settings::MENU_VIEW_COORDS), sf::Vector2f(0.0f, 0.0f));

  if (!ImGui::SFML::Init(window)) 
  {
    std::cerr << "Failed to initialize ImGui-SFML." << std::endl;
    return -1;  // Exit if initialization failed
  }
  // To track user mouse for inputs
  sf::Vector2f MousePosition;

  // Settings object
  Settings manuel;
  
  // To Construct the Grid 
  Grid activeGrid = Grid(Grid::NONE);;

  // Shadow bool to handle rendering
  Shadow shadow(false);

  // MainMenu  
  
  // Initialize menu options for grid selection.
  // 1. sf::FloatRect clickable area for the menu item (x, y, width, height)
  // 2. sf::Vector2f coordinates where the view will center when the option is selected
  // 3. activeGrid Sets the active grid to the corresponding grid size when the option is chosen
  

  //-----------------------------------------------------

  //NEw menu
  struct MenuGUI
  {
    std::string title;
    sf::Vector2f viewCenter;
    sf::Vector2f sizeView;
    sf::Vector2f buttonPos;
    sf::Vector2f buttonSize;
    Grid setActiveGrid;
  };

  std::vector<MenuGUI> menuOptionsGUI = 
    {
      { "8x8", Settings::GRID8x8_VIEW_COORDS,Settings::GRID8x8_VIEW_SIZE ,  Settings::button_For_GRID8x8  , Settings::WIDTH_AND_HEIGHT_OF_MENU_BUTTON  ,Grid::grid8x8},
      { "16x16", Settings::GRID16x16_VIEW_COORDS, Settings::GRID16x16_VIEW_SIZE ,  Settings::button_For_GRID16x16   ,  Settings::WIDTH_AND_HEIGHT_OF_MENU_BUTTON  ,Grid::grid16x16},
      { "32x32", Settings::GRID32x32_VIEW_COORDS, Settings::GRID32x32_VIEW_SIZE ,  Settings::button_For_GRID32x32   , Settings::WIDTH_AND_HEIGHT_OF_MENU_BUTTON   ,Grid::grid32x32},
      { "64x64", Settings::GRID64x64_VIEW_COORDS, Settings::GRID64x64_VIEW_SIZE , Settings::button_For_GRID64x64   , Settings::WIDTH_AND_HEIGHT_OF_MENU_BUTTON   ,Grid::grid64x64},
      { "Custom", Settings::GRID64x64_VIEW_COORDS, Settings::GRID64x64_VIEW_SIZE ,  Settings::button_For_CustomGRID   , Settings::WIDTH_AND_HEIGHT_OF_MENU_BUTTON   ,Grid::grid64x64}
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
        utils::ResizeView(window, view);
       }
       
       // Mouse Events

       // Mouse Single Click Events 
       if (event.type == sf::Event::MouseButtonPressed)
         {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
              
               //Handles Mouse position  
               // TODO come back to check if this servers a purpose
               utils::handleMousePosition(MousePosition,  window);

               
              // For coloring, erasing, or copying the color of a single cell with a click 
                if (palette.getIsEraserOn() == true)
                {
                  utils::handlePaletteAndEraser(activeGrid, MousePosition);
                } 
                if (palette.getIsEyeDropperrOn() == true && palette.getIsEraserOn() == false )
                {
                  utils::eyeDropper( activeGrid ,MousePosition ,currentColor, palette);
                }
                else
                {
                   utils::drawActiveGrid(activeGrid, MousePosition, currentColor);
                }
            }
         }

         // Mouse Continues Movement Updates Events 
         if (event.type == sf::Event::MouseMoved &&  isMainMenuRendering == false)
          {
            //Handles Mouse position 
           utils::handleMousePosition(MousePosition,  window);

           // Handles the position where the shadow body will render
            utils::handleShadowDraw(activeGrid, MousePosition, shadow);
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
              {
                if (palette.getIsEraserOn() == true){
                  utils::handlePaletteAndEraser(activeGrid, MousePosition);
                } 
                else
                {
                   utils::drawActiveGrid(activeGrid, MousePosition, currentColor);
                }
              } 
              
          }    
       } 

       ImGui::SFML::Update(window, deltaClock.restart());

       //TODO remove magic numbers
       ImGui::SetNextWindowPos(ImVec2(Settings::X_POSITION_OF_MENU_RECT, Settings::Y_POSITION_OF_MENU_RECT));  
       ImGui::SetNextWindowSize(ImVec2(310, 310));    

       ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar
                                      | ImGuiWindowFlags_NoResize
                                      | ImGuiWindowFlags_NoMove
                                      | ImGuiWindowFlags_NoCollapse
                                      | ImGuiWindowFlags_NoScrollbar
                                      | ImGuiWindowFlags_NoSavedSettings;

       if (isMainMenuRendering){

        ImGui::Begin("Main Menu", nullptr, window_flags);
          for (const auto& option : menuOptionsGUI) 
                 {
                  ImGui::SetCursorPos(ImVec2(option.buttonPos));
                  if (ImGui::Button(option.title.c_str(), ImVec2(option.buttonSize))) 
                  {
                    view.setCenter(option.viewCenter); // Center the view on the selected grid
                    view.setSize(option.sizeView);
                    manuel.setViewHeight(option.sizeView.x);
                    activeGrid = option.setActiveGrid;
                    isMainMenuRendering = false;
                    isPaletteRendering = true;
                    
                  break;  // Exit the loop after a selection
                  }
                 }
        ImGui::End(); 
       }


       if (!isMainMenuRendering){

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
          ImGui::Begin("Grid Canvas", nullptr, window_flags);

          // top panel text
           ImGui::Text("Pixel House");

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
