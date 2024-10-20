# Pixel House - Pixel Art Creation and Editing Software

Pixel House is an advanced pixel art creation and editing tool built using C++ with SFML (Simple and Fast Multimedia Library) for real-time graphics rendering and ImGui for a user-friendly interface. This software enables users to create pixel art on customizable grids and offers essential tools such as a color palette, eraser, and shadow rendering for precise pixel manipulation. The project is currently under development with ongoing improvements and feature additions.

## Key Features
- Customizable Grid Sizes: Users can select between different grid sizes (8x8, 16x16, 32x32, 64x64) to create pixel art projects of varying complexity.
- Color Palette: A fully interactive color picker that allows users to choose and apply colors to individual pixels within the grid.
- Eraser Tool: Provides functionality to remove colors from selected pixels to restore the original grid background.
- Eye Dropper Tool: Lets users select and apply a color from any pixel already placed in the grid.
- Shadow Rendering: Dynamic shadow rendering on the grid gives visual feedback of the mouse position and helps with accurate pixel selection.
- Real-time Interface: Powered by ImGui, the software offers a responsive and intuitive top panel for easy access to tools like the eraser and color picker.
- Responsive Grid and View Resizing: The grid and view dynamically adjust to window resizing while maintaining aspect ratios.

## Demo 
Here's a screenshot of the application in action:

![Demo of Pixel House](/src/DemoOne.png)

![Demo of Pixel House](/src/DemoTwo.png)

## Technologies Used
- C++: The core language used for implementing object-oriented design and efficient real-time processing.
SFML: Used for graphics rendering and handling real-time events like mouse clicks and window resizing.
ImGui: A powerful immediate-mode GUI framework that provides the intuitive interface for user interaction, such as color picking and tool selection.
CMake: Used for managing the build process, ensuring cross-platform compatibility and easy project setup.
Object-Oriented Programming (OOP): The project is structured around OOP principles, making it modular, maintainable, and scalable.
How It Works

- Main Menu: When the software starts, users are presented with a grid selection menu. They can choose from 8x8, 16x16, 32x32, or 64x64 grids, which determines the canvas size for pixel art.
- Color and Tools: After selecting a grid, users can pick colors using the Color Picker and apply them to the grid. Tools such as the Eraser and Eye Dropper are accessible from the top panel.
- Drawing and Editing: Users can click or drag the mouse to apply or erase colors on individual grid cells. Real-time shadow feedback helps with accurate pixel placement.
- View Resizing: The canvas adjusts based on window size changes, ensuring a consistent user experience.

## Installation
Follow these steps to set up and run Pixel House on your local machine:

### Prerequisites
- C++ Compiler: Ensure you have a C++17 compatible compiler installed (e.g., GCC, Clang, MSVC).
- SFML: Install the latest version of SFML (SFML Download).
- ImGui: The project uses ImGui-SFML integration. Make sure to install ImGui and link it with SFML.

### Steps
- Clone the repository:

```bash
git clone https://github.com/yourusername/PixelHouse.git
cd PixelHouse
cmake ..
make
./PixelHouse
```

- Install dependencies
(e.g., SFML, ImGui): Follow the instructions for setting up SFML and ImGui-SFML.
Build the project using CMake:

mkdir build
cd build
cmake ..
make
Run the application: After successful compilation, run the application using:
./PixelHouse

## Usage
- Launch the application to open the main menu and choose the desired grid size.
- Start creating your pixel art by selecting a color from the Color Picker and clicking on the grid cells.
- Use the Eraser to remove colors and the Eye Dropper to pick colors from existing pixels.
- Save and Export Features (Coming Soon): Planned for future development is the ability to save pixel art and export it as an image file

## Roadmap and Future Features
- Save and Load Functionality: Users will be able to save their work and continue editing later.
- Export Art as Image: A feature to export the pixel art in formats like PNG or BMP.
- More Tools: Additional drawing tools like line, rectangle, and fill will be implemented.
- Customizable Color Palette: Enhance the palette with more options and saved color schemes.
- Grid Customization: Allow users to set custom grid sizes and resolutions.

## Contributions
- Contributions are welcome!
If you'd like to help improve Pixel House, please fork the repository and submit a pull request.

- Fork the project.
- Create your feature branch:
git checkout -b feature/AmazingFeature

- Commit your changes:
git commit -m 'Add some AmazingFeature'

-Push to the branch:
git push origin feature/AmazingFeature

-Open a pull request.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments
- SFML for providing a powerful and simple multimedia library.
- ImGui-SFML for making the integration of GUI elements seamless.
- C++ for its performance and flexibility in creating real-time applications.
- CMake for simplifying the build process and ensuring cross-platform compatibility.
