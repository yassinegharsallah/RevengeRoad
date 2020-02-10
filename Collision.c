#include "collision.h"
#include <math.h>

int collision_trigo(SDL_Surface *perso  ,SDL_Surface *enemie,SDL_Rect posp,SDL_Rect pose )
{

int ra,rb,xb,xa,ya,yb,distance;
ra=(perso->w)/2;
xa=(posp.x+(perso->w/2));
ya=(posp.y+(perso->h/2));
rb=(enemie->w)/2;
xb=(pose.x+(enemie->w/2));
yb=(pose.y+(enemie->h/2));
distance=sqrt((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));
if(distance<=ra+rb)
{
return 1 ;
}
else
{
return 0;
}
}
int collisionAB(SDL_Surface *iA,SDL_Surface *iB,SDL_Rect pA,SDL_Rect pB)
{

    if  ((pA.y + iA->h) < pB.y )
      return 0;
    else if ( pA.y > (pB.y + iB->h))
      return 0;
    else if ( (pA.x + iA->w) < pB.x )
      return 0;
    else if ( pA.x > (pB.x +  iB->w))
      return 0;
return 1;

}
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) surface->pixels ;

	//offset by y
	pPosition += ( surface->pitch * y ) ;

	//offset by x
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d)
{

  SDL_Color col;
  if(d==0)//imin
  {
    col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));
  }
else  if(d==1)//issarr
  {
    col=GetPixel(calque,posperso.x +decalage,posperso.y+(perso->h/2));
  }
else  if(d==2)//lfou9
  {
    col=GetPixel(calque,posperso.x+(perso->w/2)+decalage ,posperso.y);
  }
else  if(d==3)//louta
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) +decalage,posperso.y+perso->h);
  }
  //printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==255)&&(col.b==255)&&(col.g==255))
{
  return 1;
}
else return 0;
}
