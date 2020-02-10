#include "Bonus.h"
Bonus InitBonus(Bonus B,SDL_Rect position,int num)
{
  B.num=num;
  B.image=IMG_Load("graphique/18052940_604695163054721_2069682593_n.png");
  B.position=position;
  return B;
}
void  AfficherBonus(Bonus B,SDL_Surface *screen)
{
   SDL_BlitSurface(B.image,NULL,screen,&B.position);
}
void updateBonus(Bonus B[],int num,int nbr)
{

}
