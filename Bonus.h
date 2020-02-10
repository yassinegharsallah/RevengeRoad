#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
  int num;
  SDL_Surface *image;
  SDL_Rect position;
}Bonus;
Bonus InitBonus(Bonus B,SDL_Rect position,int num);
void  AfficherBonus(Bonus B,SDL_Surface *screen);
void updateBonus(Bonus Bonus[],int num,int nbr);
