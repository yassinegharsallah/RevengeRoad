#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct BackGround
{
  SDL_Surface *image;
  SDL_Surface *calque;
  SDL_Rect position;
  SDL_Rect camera;
}BackGround;
BackGround InitBackGround(BackGround map,char lvl[50],char calque[50]);
BackGround ScorllingBackGround(BackGround map,int direction,SDL_Rect *pos1,SDL_Rect *pos2,SDL_Rect *Bonus);
void AfficherBackGround(BackGround map,SDL_Surface *screen);
