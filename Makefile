prog:main.o main.o bgmenu.o Bonus.o Collision.o Enemy.o map.o player.o menuson.o 
	gcc main.o bgmenu.o Bonus.o Collision.o Enemy.o map.o player.o menuson.o  -lm -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o prog
main.o:main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c main.c
bgmenu.o:bgmenu.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c bgmenu.c
Bonus.o:Bonus.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Bonus.c
Collision.o:Collision.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Collision.c
Enemy.o:Enemy.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c Enemy.c
map.o:map.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c map.c
player.o:player.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c player.c
menuson.o:menuson.c
		gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c menuson.c
MathPhys.o:MathPhys.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c MathPhys.c
