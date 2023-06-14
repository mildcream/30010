#include "stm32f30x_conf.h"
#include "stm32f30x_conf.h"
#include "draw.h"
#include "ansi.h"

typedef struct {
	int32_t positionX;
	int32_t positionY;
	int32_t vectorX;
	int32_t vectorY;
	int32_t nextPosX;
	int32_t nextPosY;
	int8_t destroyed;

} asteroid_t ;
typedef struct {
	int32_t positionX;
	int32_t positionY;
	int32_t vectorX;
	int32_t vectorY;
	int32_t nextPosX;
	int32_t nextPosY;
	int32_t orientation;


} spaceship_t ;
typedef struct {
	int32_t positionX;
	int32_t positionY;
	int32_t vectorX;
	int32_t vectorY;
	int32_t nextPosX;
	int32_t nextPosY;

} bullet_t ;

void drawAsteroid(asteroid_t * asteroid){
	if(!(*asteroid).destroyed){
		gotoxy((*asteroid).positionX-8,(*asteroid).positionY-8);
		printf("(");
		gotoxy((*asteroid).positionX,(*asteroid).positionY-8);
		printf("@");
		gotoxy((*asteroid).positionX+8,(*asteroid).positionY-8);
		printf(")");
		gotoxy((*asteroid).positionX-16,(*asteroid).positionY);
		printf("(");
		gotoxy((*asteroid).positionX+16,(*asteroid).positionY);
		printf(")");
		gotoxy((*asteroid).positionX-8,(*asteroid).positionY+8);
		printf("(");
		gotoxy((*asteroid).positionX,(*asteroid).positionY+8);
		printf("@");
		gotoxy((*asteroid).positionX+8,(*asteroid).positionY+8);
		printf(")");
	}
}

void clearAsteroid(int32_t x, int32_t y){
	gotoxy(x-8,y-8);
	printf(" ");
	gotoxy(x,y-8);
	printf(" ");
	gotoxy(x+8,y-8);
	printf(" ");
	gotoxy(x-16,y);
	printf(" ");
	gotoxy(x+16,y);
	printf(" ");
	gotoxy(x-8,y+8);
	printf(" ");
	gotoxy(x,y+8);
	printf(" ");
	gotoxy(x+8,y+8);
	printf(" ");
}

void drawSpaceship(int32_t x, int32_t y, int32_t orient){
	switch(orient){
	case 0:
		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x+16,y+8);
		printf("\xDB");
		gotoxy(x+24,y+8);
		printf("\xDB");
		gotoxy(x-8,y+8);
		printf("\xDB");
		gotoxy(x-16,y+8);
		printf("\xDB");
		break;
	case 1:
		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x-8,y);
		printf("\xDB");
		gotoxy(x-16,y);
		printf("\xDB");
		gotoxy(x,y+8);
		printf("\xDB");
		gotoxy(x+8,y+8);
		printf("\xDB");
		break;
	case 2:

		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x-8,y-8);
		printf("\xDB");
		gotoxy(x-16,y-8);
		printf("\xDB");
		gotoxy(x-8,y+8);
		printf("\xDB");
		gotoxy(x-16,y+8);
		printf("\xDB");
		break;
	case 3:
		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x-8,y);
		printf("\xDB");
		gotoxy(x-16,y);
		printf("\xDB");
		gotoxy(x,y-8);
		printf("\xDB");
		gotoxy(x+8,y-8);
		printf("\xDB");
		break;
	case 4:

		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x+16,y-8);
		printf("\xDB");
		gotoxy(x+24,y-8);
		printf("\xDB");
		gotoxy(x-8,y-8);
		printf("\xDB");
		gotoxy(x-16,y-8);
		printf("\xDB");
		break;

	case 5:
		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x+16,y);
		printf("\xDB");
		gotoxy(x+24,y);
		printf("\xDB");
		gotoxy(x,y-8);
		printf("\xDB");
		gotoxy(x+8,y-8);
		printf("\xDB");
		break;
	case 6:

		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x+16,y-8);
		printf("\xDB");
		gotoxy(x+24,y-8);
		printf("\xDB");
		gotoxy(x+16,y+8);
		printf("\xDB");
		gotoxy(x+24,y+8);
		printf("\xDB");
		break;

	case 7:
		gotoxy(x,y);
		printf("\xDB");
		gotoxy(x+8,y);
		printf("\xDB");
		gotoxy(x+16,y);
		printf("\xDB");
		gotoxy(x+24,y);
		printf("\xDB");
		gotoxy(x,y+8);
		printf("\xDB");
		gotoxy(x+8,y+8);
		printf("\xDB");
		break;
	}
}

void drawBullet(int32_t x, int32_t y){
	gotoxy(x,y);
	printf("*");
}


