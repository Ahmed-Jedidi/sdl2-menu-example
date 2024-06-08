#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//Font
#include <SDL2/SDL_ttf.h>
//Sound
//#include <SDL2/SDL_mixer.h>

//Extra
#include <stdio.h>
#include <stdlib.h>

//Windows' Dimension
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define position_x 200
#define position_y 200

// Structure représentant un bouton
typedef struct {
    SDL_Rect rect;
    SDL_Texture *normalTexture;
    SDL_Texture *selectedTexture;
    SDL_bool isSelected;
} Button;

// Fonction pour charger une texture depuis un fichier image
SDL_Texture* loadTexture(SDL_Renderer *renderer, const char *path) {
    SDL_Surface *surface = IMG_Load(path);
    if (!surface) {
        printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Fonction pour créer un bouton
Button createButton(SDL_Renderer *renderer, const char *normalPath, const char *selectedPath, int x, int y) {
    Button button;
    button.rect.x = x;
    button.rect.y = y;
    button.rect.w = 200;
    button.rect.h = 50;
    button.normalTexture = loadTexture(renderer, normalPath);
    button.selectedTexture = loadTexture(renderer, selectedPath);
    button.isSelected = SDL_FALSE;
    return button;
}

// Fonction pour libérer les ressources d'un bouton
void destroyButton(Button *button) {
    SDL_DestroyTexture(button->normalTexture);
    SDL_DestroyTexture(button->selectedTexture);
}
////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *background = NULL;
    Button playButton, optionsButton, quitButton;
    SDL_bool isRunning = SDL_TRUE;

    // Initialisation de SDL (Sound...)
    if (SDL_Init(SDL_INIT_VIDEO  | SDL_INIT_AUDIO) != 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }



    //Sound Begin

    // Initialisation de SDL_mixer
    //if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    //    printf("Erreur lors de l'initialisation de SDL_mixer: %s\n", Mix_GetError());
    //    SDL_Quit();
    //    return 1;
    //}

    // Chargement du son
    /*Mix_Chunk *continuousSound = Mix_LoadWAV("example.wav");
    if (!continuousSound) {
        printf("Erreur lors du chargement du son: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }*/

    // Jouer le son en continu
    //Mix_PlayChannel(-1, continuousSound, -1);

    // Pause pour laisser le son jouer
    //SDL_Delay(5000);

    //Sound End

    // Création de la fenêtre
    window = SDL_CreateWindow("Menu!", /*SDL_WINDOWPOS_UNDEFINED*/position_x, /*SDL_WINDOWPOS_UNDEFINED*/position_y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Chargement des ressources
    background = loadTexture(renderer, "menu_background.png");
    if (!background) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    playButton = createButton(renderer, "play_normal.png", "play_selected.png", 300, 200);
    optionsButton = createButton(renderer, "options_normal.png", "options_selected.png", 300, 300);
    quitButton = createButton(renderer, "quit_normal.png", "quit_selected.png", 300, 400);



    //Extra
    // Fonction pour vérifier si les coordonnées (x, y) se trouvent à l'intérieur du rectangle rect
    /*SDL_bool isMouseOver(SDL_Rect *rect, int x, int y) {
    return (x >= rect->x && x < rect->x + rect->w && y >= rect->y && y < rect->y + rect->h);
    }*/
    // Fonction pour vérifier si les coordonnées (x, y) se trouvent à l'intérieur du bouton
    SDL_bool isMouseOver(Button *button, int x, int y) {
        return (x >= button->rect.x && x < button->rect.x + button->rect.w && y >= button->rect.y && y < button->rect.y + button->rect.h);
    }
    //Extra

    // Boucle principale
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = SDL_FALSE;
                    break;
                case SDL_MOUSEMOTION:
                    // Gérer le survol des boutons par la souris
                    // ...
                    // Vérifier si la souris survole les boutons et les marquer comme sélectionnés en conséquence
                if (isMouseOver(&playButton, event.motion.x, event.motion.y)) {
                    playButton.isSelected = SDL_TRUE;
                } else {
                    playButton.isSelected = SDL_FALSE;
                }
                if (isMouseOver(&optionsButton, event.motion.x, event.motion.y)) {
                    optionsButton.isSelected = SDL_TRUE;
                } else {
                    optionsButton.isSelected = SDL_FALSE;
                }
                if (isMouseOver(&quitButton, event.motion.x, event.motion.y)) {
                    quitButton.isSelected = SDL_TRUE;
                } else {
                    quitButton.isSelected = SDL_FALSE;
                }
                    // ...
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Gérer le clic sur un bouton
                    // ...
                    if (event.button.button == SDL_BUTTON_LEFT) {
                    if (isMouseOver(&playButton, event.button.x, event.button.y)) {
                        // Action lorsque le bouton "Jouer" est cliqué
                        // Par exemple, changer le fond d'écran
                        // displayGameBackground(renderer);
                    } else if (isMouseOver(&optionsButton, event.button.x, event.button.y)) {
                        // Action lorsque le bouton "Options" est cliqué
                        // Par exemple, afficher le menu des options
                        // displayOptions(renderer);
                    } else if (isMouseOver(&quitButton, event.button.x, event.button.y)) {
                        isRunning = SDL_FALSE;
                    }
                }
                    // ...
                    break;
                case SDL_KEYDOWN:
                    // Gérer les touches du clavier
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        isRunning = SDL_FALSE;
                    }
                    break;
            }
        }

        // Affichage du fond d'écran
        SDL_RenderCopy(renderer, background, NULL, NULL);

        // Affichage des boutons
        SDL_RenderCopy(renderer, playButton.isSelected ? playButton.selectedTexture : playButton.normalTexture, NULL, &playButton.rect);
        SDL_RenderCopy(renderer, optionsButton.isSelected ? optionsButton.selectedTexture : optionsButton.normalTexture, NULL, &optionsButton.rect);
        SDL_RenderCopy(renderer, quitButton.isSelected ? quitButton.selectedTexture : quitButton.normalTexture, NULL, &quitButton.rect);

        // Chargement de la police de caractères
        if (TTF_Init() != 0) {
    printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}
TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
if (!font) {
    printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
    return 1;
}

// Création de la surface de texte
SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Menu Principale : Super Game", (SDL_Color){255, 255, 255, 255});
if (!textSurface) {
    printf("Erreur lors de la création de la surface de texte : %s\n", TTF_GetError());
    TTF_CloseFont(font);
    return 1;
}

// Création de la texture de texte
SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
if (!textTexture) {
    printf("Erreur lors de la création de la texture de texte : %s\n", SDL_GetError());
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    return 1;
}
        // Affichage du texte
        SDL_Rect textRect = {100, 100, textSurface->w, textSurface->h};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        // ...

        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    // Liberate sound
    //Mix_FreeChunk(continuousSound);
    //Mix_CloseAudio();
    // Liberer font
    //SDL_DestroyTexture(textTexture);
    //SDL_FreeSurface(textSurface);
    //TTF_CloseFont(font);
    TTF_Quit();
    //...
    SDL_DestroyTexture(background);
    destroyButton(&playButton);
    destroyButton(&optionsButton);
    destroyButton(&quitButton);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
