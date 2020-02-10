#include "Enemy.h"
Enemy InitEnemy(Enemy Ennemie,SDL_Rect position)
{
  Ennemie.image[0]=IMG_Load("graphique/Enemy/rpg1.png");
  Ennemie.image[1]=IMG_Load("graphique/Enemy/rpg2.png");
  Ennemie.image[2]=IMG_Load("graphique/Enemy/rpg3.png");
  Ennemie.Hit=IMG_Load("graphique/Enemy/rpg4.png");
  Ennemie.imageActuel=Ennemie.image[0];
  Ennemie.position=position;
  Ennemie.positionO=position;
  Ennemie.fram=0;
  Ennemie.direction=0;
  return Ennemie;
}
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen,SDL_Rect camera)
{
  SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
}
Enemy AnimateEnemy(Enemy Ennemie,int stat)
{
  if (Ennemie.fram==2) {
    Ennemie.fram=0;
  }
  else
  Ennemie.fram++;
  Ennemie.imageActuel=Ennemie.image[Ennemie.fram];
  if(stat==1)
    Ennemie.imageActuel=Ennemie.Hit;
  return Ennemie;

}
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage)
{

int distance;

  if(Ennemie.position.x>=personnage.x)
    distance=Ennemie.position.x-personnage.x;
  else
    distance=personnage.x-Ennemie.position.x;

    if(distance<200)
      {
        if(Ennemie.position.x>=personnage.x)
          Ennemie.direction=0;
        else
          Ennemie.direction=1;
      }
      else
    {  if(Ennemie.positionO.x+100==Ennemie.position.x)
          Ennemie.direction=0;

      if(Ennemie.positionO.x-100==Ennemie.position.x)

        Ennemie.direction=1;}


      if(Ennemie.direction==1)
      {
        Ennemie.position.x+=5;
      }
      if(Ennemie.direction==0)
      {
        Ennemie.position.x-=5;
      }


  return Ennemie;
}
