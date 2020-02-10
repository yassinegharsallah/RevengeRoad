#include "player.h"
#define TERRE 0
#define AIR 1
void gravite(Player k,float influence_saut,float influence_gravite,Uint8 *keys)
{
 if (k->statut == AIR && keys[SDLK_SPACE])
   {
     influence_gravite/=influence_saut;
   }
   k->vy+=influence_gravite;
}
void Vitesse(Player *k,Uint8 *keys)
{
 float adherance = 1.5f;
 float vitesseLateral = 0.5f;
 float facteurAirVitesseLateral = 0.5f;
 float vitesseMax = 2.0f;
 float impulsion = 5.0f;
 float influence_gravite = 0.5f;
 float influence_saut = 3.0f;
 if(k->statut == AIR)
  {
   vitesseLateral*=facteurAirVitesseLateral;
  }
 if(keys[SDLK_LEFT])
  {
   k->vx-=vitesseLateral;
  }
 if(keys[SDLK_RIGHT])
  {
   k->vx+=vitesseLateral;
  }
 if((k->statut == TERRE)&&(!keys[SDLK_LEFT])&&(!keys[SDLK_RIGHT]))
  {
   k->vx/=adherance;
  }
 if(k->vx > vitesseMax)
  {
   k->vx = vitesseMax;
  }
 if(k->vx < (-vitesseMax))
  {
   k->vx = -vitesseMax;
  }
 if(keys[SDLK_SPACE]&& k->statut == TERRE)
  {
   saut(k,impulsion);
  }
 gravite(k,influence_saut,influence_gravite,keys);
 initialisationApresSaut(k);
 k->x +=k->vx;
 k->y +=k->vy;
}
