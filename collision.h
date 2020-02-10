#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int collisionAB(SDL_Surface *iA,SDL_Surface *iB,SDL_Rect pA,SDL_Rect pB);
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d);
int collision_trigo(SDL_Surface *perso  ,SDL_Surface *enemie,SDL_Rect posp,SDL_Rect pose );
