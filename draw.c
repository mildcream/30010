#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h"
#include "stm32f30x_conf.h"
#include "draw.h"
#include "ansi.h"
#include "position.h"
#include "lcd.h"
#include "charset.h"
#include "timer.h"


void drawAsteroid(asteroid_t * asteroid){
	if(!(*asteroid).destroyed){
		gotoxy((*asteroid).positionX-128,(*asteroid).positionY-128);
		printf("(");
		gotoxy((*asteroid).positionX,(*asteroid).positionY-128);
		printf("@");
		gotoxy((*asteroid).positionX+128,(*asteroid).positionY-128);
		printf(")");
		gotoxy((*asteroid).positionX-256,(*asteroid).positionY);
		printf("(");
		gotoxy((*asteroid).positionX+256,(*asteroid).positionY);
		printf(")");
		gotoxy((*asteroid).positionX-128,(*asteroid).positionY+128);
		printf("(");
		gotoxy((*asteroid).positionX,(*asteroid).positionY+128);
		printf("@");
		gotoxy((*asteroid).positionX+128,(*asteroid).positionY+128);
		printf(")");
	}
}

void clearAsteroid(asteroid_t * asteroid){
		gotoxy((*asteroid).positionX-128,(*asteroid).positionY-128);
		printf(" ");
		gotoxy((*asteroid).positionX,(*asteroid).positionY-128);
		printf(" ");
		gotoxy((*asteroid).positionX+128,(*asteroid).positionY-128);
		printf(" ");
		gotoxy((*asteroid).positionX-256,(*asteroid).positionY);
		printf(" ");
		gotoxy((*asteroid).positionX+256,(*asteroid).positionY);
		printf(" ");
		gotoxy((*asteroid).positionX-128,(*asteroid).positionY+128);
		printf(" ");
		gotoxy((*asteroid).positionX,(*asteroid).positionY+128);
		printf(" ");
		gotoxy((*asteroid).positionX+128,(*asteroid).positionY+128);
		printf(" ");

}



void drawSpaceship(spaceship_t * spaceship){
	switch((*spaceship).orientation){
	case 0:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY); //prints twice but it doesn't work if you dont do this
		printf("\xDB");
		break;
	case 1:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY+128);
		printf("\xDB");
		break;
	case 2:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY+128); //prints twice but it doesn't work if you dont do this
		printf("\xDB");
		break;
	case 3:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY-128);
		printf("\xDB");
		break;
	case 4:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY-128); //prints twice but it doesn't work if you dont do this
		printf("\xDB");
		break;

	case 5:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY-128);
		printf("\xDB");
		break;
	case 6:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY-128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY+128);
		printf("\xDB");
		break;

	case 7:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+128);
		printf("\xDB");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY+128);
		printf("\xDB");
		break;
	}
}

void clearSpaceship(spaceship_t * spaceship){
	switch((*spaceship).orientation){
	case 0:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY+128);
		printf(" ");
		break;
	case 1:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY+128);
		printf(" ");
		break;
	case 2:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY+128);
		printf(" ");
		break;
	case 3:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY-128);
		printf(" ");
		break;
	case 4:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX-128,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX-256,(*spaceship).positionY-128);
		printf(" ");
		break;

	case 5:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY-128);
		printf(" ");
		break;
	case 6:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY-128);
		printf(" ");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY+128);
		printf(" ");
		break;

	case 7:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+256,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+384,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+128);
		printf(" ");
		gotoxy((*spaceship).positionX+128,(*spaceship).positionY+128);
		printf(" ");
		break;
	}
}
void drawBullet(bullet_t * bullet){
	gotoxy((*bullet).positionX,(*bullet).positionY);
	printf("*");
}


