#include "map.h"
#include "player.h"
#include "Enemy.h"
#include "collision.h"
#include "Bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "jeux.h"



int jeux(SDL_Surface *ecran)
{
  int gameover=1000;
  char str[50];
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *gameoveri=NULL;
  gameoveri=IMG_Load("gameover_zpse663rlsp.png");
  SDL_Rect score;
  score.x=800;
  score.y=10;
  TTF_Init();
  TTF_Font *police = NULL;
  police = TTF_OpenFont("beela.ttf", 25);
  SDL_Color couleurNoire = {0, 0, 0};
  SDL_Surface *texte;
  texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleurNoire);
  //Les BackGround
    BackGround bg;
    bg=InitBackGround(bg,"graphique/stage 4/yass.png","graphique/stage 4/calque.png");
  //Les personnage
    Player Joueur;
    Joueur=InitPlayer(Joueur);
  //Les enemie
    int i,isalive=0;
    int ref=0;
    Enemy Ennemie;
    SDL_Rect spawn;
    spawn.x=800;
    spawn.y=570-96;
    int Ennemiedeth=100;
    Ennemie=InitEnemy(Ennemie,spawn);
  //Les Bonus
    spawn.x=120;
    spawn.y=470;
    Bonus B;
    B=InitBonus(B,spawn,1);
    int jump=100;
    int prot=0;
    int collisionWithEnnemi=0;
  /*SDL_Surface *ecran;
  ecran = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);*/
  int direction=0;
  int continuer=1;
  int Hit=1;
  int time=15;
  int collision;
  SDL_Event event;
  spawn.x=500-( gameoveri->w/2);
  spawn.y=300-( gameoveri->h/2);;

  while (continuer) {
    gameover++;
    direction=3;
    prot=0;
    SDL_PollEvent(&event);
        if(event.type==SDL_QUIT)
          continuer=0;
        else if(event.type==SDL_KEYDOWN)
        {
            if(event.key.keysym.sym==SDLK_RIGHT) direction=0;
            if(event.key.keysym.sym==SDLK_LEFT)  direction=1;
            if(event.key.keysym.sym==SDLK_UP)    {direction=2;}
            if(event.key.keysym.sym==SDLK_DOWN)  {direction=3;}
        }
        collision=collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,direction);
        if(collision==0)
        {bg=ScorllingBackGround(bg,direction,&Ennemie.position,&Ennemie.positionO,&B.position);
          if (direction!=2)
          Joueur=MovePlayer(Joueur,direction,bg.camera.x);
        if  (collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,2)==1)
          jump=120;
          if((direction==2)&&(jump>13))
            jump=0;


        }
  if ((jump<7)&&(Joueur.position.y>=0)) {
              Joueur.position.y-=20;
            }
            jump++;
        collisionWithEnnemi=collisionAB(Joueur.imageActuel,Ennemie.imageActuel,Joueur.position,Ennemie.position);
        if(collisionWithEnnemi==1)
        {
          time=0;
        }
        if((time<15)&&(time>0))
        {
          Hit=1;
        }
        else
        Hit=0;
      //  printf("%d  \n",Ennemiedeth);
        if ((collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,3)==0)&&(Joueur.position.y<=600)&&(jump>7)) {
          Joueur.position.y+=17;
          prot=1;

        }
        printf("%d\n",gameover);
        if(Joueur.position.x+Joueur.imageActuel->w+10>=1000)
        {
            bg=InitBackGround(bg,"graphique/stage 2/lvl1.png","graphique/stage 2/calque1.png");
            Joueur=InitPlayer(Joueur);

        }
        if(collisionAB(Joueur.imageActuel,B.image,Joueur.position,B.position)==1)
        {
          Joueur.score++;
        }
              time++;
          Ennemie=AnimateEnemy(Ennemie,isalive);
        i=collisionWithEnnemi;
        if(i==0)
                            {
                             ref=0;
                            }
                       if(ref==0)
                       {
                         if(i==1)
                         ref=1;
                         gestion_vie(&Joueur.vie,i);

                       }
                       if((collisionWithEnnemi==1)&&(prot==1))
                       {
                         Ennemiedeth=0;
                       }
                       if(Ennemiedeth<15)
                        Ennemie=AnimateEnemy(Ennemie,1);

                       Ennemiedeth++;


          Ennemie=MoveEnemy(Ennemie,Joueur.position);
        sprintf(str, "%d", Joueur.score);
        texte = TTF_RenderText_Blended(police, str, couleurNoire);
        Joueur=AnimatePlayer(Joueur,direction,Hit);

        AfficherBackGround(bg,ecran);

        SDL_Delay(15);
      if(gameover>1000)
        {AfficherEnemy(Ennemie,ecran,bg.camera);
        AfficherBonus(B,ecran);
        afficher_vie(Joueur.vie,ecran);
        AfficherPlayer(Joueur,ecran);
        SDL_BlitSurface(texte,NULL,ecran,&score);}
      else
      {  SDL_BlitSurface(gameoveri,NULL,ecran,&spawn);}
        SDL_Flip(ecran);
        if(Joueur.vie.nbr==0)
          {gameover=0;}
          if(gameover==50)
            continuer=0;



 }
}
