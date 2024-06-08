# SDL2 Menu Example

This project is an example of creating a simple graphical menu using SDL2, SDL2_image, and SDL2_ttf libraries. It demonstrates how to create buttons, handle mouse events, and render text in an SDL2 window.

## Features

- **Graphical Menu**: A simple menu with three buttons: Play, Options, and Quit.
- **Button Interactions**: Buttons change appearance when hovered over with the mouse.
- **Text Rendering**: Renders text on the screen using SDL2_ttf.
- **Modular Code**: Functions for loading textures, creating buttons, and managing events.

![Screenshot 2024-06-08 034213](https://github.com/Ahmed-Jedidi/sdl2-menu-example/assets/74512793/6c5b8e5d-7f92-49a2-90f0-ab806c419688)

## Requirements

To compile and run this project, you need the following libraries installed:

- SDL2
- SDL2_image
- SDL2_ttf
- (Optional) SDL2_mixer for sound

## Installation

1. **Install SDL2 Libraries**


   - On Windows using CodeBlocks:
     ![Screenshot 2024-06-08 034721](https://github.com/Ahmed-Jedidi/sdl2-menu-example/assets/74512793/8abc2dab-819b-4719-888e-81f6f000018b)

     ![Screenshot 2024-06-08 035258](https://github.com/Ahmed-Jedidi/sdl2-menu-example/assets/74512793/1620c364-63dc-45b0-841b-7e9a4bd8d321)
     ```linker options
     -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
     ```
     
     ![Screenshot 2024-06-08 035311](https://github.com/Ahmed-Jedidi/sdl2-menu-example/assets/74512793/a55e385d-17a1-42f4-b43d-9b6760ba1334)
     ```Search directories: compiler
     ..\SDL2\i686-w64-mingw32\include
     ..\img\SDL2_image\i686-w64-mingw32\include
     ..\img\SDL2_ttf\i686-w64-mingw32\include
     ```

     ![Screenshot 2024-06-08 035332](https://github.com/Ahmed-Jedidi/sdl2-menu-example/assets/74512793/6484d10a-aba3-46e0-81b9-5c038840262f)
     ```Search directories: linker
     ..\SDL2\i686-w64-mingw32\lib
     ..\img\SDL2_image\i686-w64-mingw32\lib
     ..\img\SDL2_ttf\i686-w64-mingw32\lib
     ```

   - On Ubuntu:
     ```bash
     sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
     ```
   - On macOS using Homebrew:
     ```bash
     brew install sdl2 sdl2_image sdl2_ttf
     ```


3. **Clone the Repository**

   ```bash
   git clone https://github.com/Ahmed-Jedidi/sdl2-menu-example.git
   cd sdl2-menu-example

