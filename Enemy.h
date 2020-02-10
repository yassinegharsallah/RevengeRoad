#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int fram;
  int direction;

}Enemy;
Enemy InitEnemy(Enemy Ennemie,SDL_Rect position);
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen,SDL_Rect camera);
Enemy AnimateEnemy(Enemy Ennemie,int stat);
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage);
