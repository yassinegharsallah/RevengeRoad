#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
  SDL_Surface *image;
  SDL_Rect pos;

}bouton;
typedef struct
{
  SDL_Surface *barre[7];
  SDL_Surface *life[8];
  SDL_Surface *bonus[2];
  SDL_Rect pos_barre;
  SDL_Rect pos_life;
  SDL_Rect pos_bonus;
  SDL_Surface *Img_barre;
  SDL_Surface *Img_life;
  SDL_Surface *Img_bonus;

}Extras;
int jeux(SDL_Surface *ecran);
int menuson(int *volume);
int help();
