#include "map.h"
BackGround InitBackGround(BackGround map,char lvl[50],char calque[50])
{
  map.image=IMG_Load(lvl);
  map.position.x=0;
  map.position.y=0;
  map.camera.x=0;
  map.camera.y=10;
  map.camera.h=600;
  map.camera.w=1000;
  map.calque=IMG_Load(calque);
  return map;
}
BackGround ScorllingBackGround(BackGround map,int direction,SDL_Rect *pos1,SDL_Rect *pos2,SDL_Rect *Bonus)
{
  if(direction==0)
  {
    if(map.camera.x<6119)
    {
      map.camera.x+=20;
      pos1->x-=20;
      pos2->x-=20;
      Bonus->x-=20;
    }
  }
  else if(direction==1)
  {
    if(map.camera.x>0)
    {
      map.camera.x-=20;
      pos1->x+=20;
      pos2->x+=20;
      Bonus->x+=20;
    }

  }

  return map;
}
void AfficherBackGround(BackGround map,SDL_Surface *screen)
{
  SDL_BlitSurface(map.image,&map.camera,screen,&map.position);
}
