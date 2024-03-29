#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h"
#include "stm32f30x_conf.h"
#include "spaceship.h"
#include "draw.h"
#include "ansi.h"
#include "position.h"
#include "lcd.h"
#include "charset.h"
#include "timer.h"
#include "bullet.h"



void drawAsteroid(asteroid_t * asteroid){
	if(!(*asteroid).destroyed){
		gotoxy((*asteroid).x-128,(*asteroid).y-128);
		printf("(");
		gotoxy((*asteroid).x,(*asteroid).y-128);
		printf("@");
		gotoxy((*asteroid).x+128,(*asteroid).y-128);
		printf(")");
		gotoxy((*asteroid).x-256,(*asteroid).y);
		printf("(");
		gotoxy((*asteroid).x+256,(*asteroid).y);
		printf(")");
		gotoxy((*asteroid).x-128,(*asteroid).y+128);
		printf("(");
		gotoxy((*asteroid).x,(*asteroid).y+128);
		printf("@");
		gotoxy((*asteroid).x+128,(*asteroid).y+128);
		printf(")");
	}
}

void clearAsteroid(asteroid_t * asteroid){
		gotoxy((*asteroid).x-128,(*asteroid).y-128);
		printf(" ");
		gotoxy((*asteroid).x,(*asteroid).y-128);
		printf(" ");
		gotoxy((*asteroid).x+128,(*asteroid).y-128);
		printf(" ");
		gotoxy((*asteroid).x-256,(*asteroid).y);
		printf(" ");
		gotoxy((*asteroid).x+256,(*asteroid).y);
		printf(" ");
		gotoxy((*asteroid).x-128,(*asteroid).y+128);
		printf(" ");
		gotoxy((*asteroid).x,(*asteroid).y+128);
		printf(" ");
		gotoxy((*asteroid).x+128,(*asteroid).y+128);
		printf(" ");

}



void drawSpaceship(spaceship_t * spaceship){
	switch((*spaceship).rotation){
	case 0:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+256,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x+384,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x-256,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y); //prints twice but it doesn't work if you dont do this
		printf("\xDB");
		break;
	case 1:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x-256,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y+128);
		printf("\xDB");
		break;
	case 2:

		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x-256,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x-256,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y+128); //prints twice but it doesn't work if you dont do this
		printf("\xDB");
		break;
	case 3:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x-256,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y-128);
		printf("\xDB");
		break;
	case 4:

		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+256,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x+384,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x-256,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x-128,(*spaceship).y-128); //prints twice but it doesn't work if you dont do this
		printf("\xDB");
		break;

	case 5:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+256,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+384,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y-128);
		printf("\xDB");
		break;
	case 6:

		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+256,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x+384,(*spaceship).y-128);
		printf("\xDB");
		gotoxy((*spaceship).x+256,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x+384,(*spaceship).y+128);
		printf("\xDB");
		break;

	case 7:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+256,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x+384,(*spaceship).y);
		printf("\xDB");
		gotoxy((*spaceship).x,(*spaceship).y+128);
		printf("\xDB");
		gotoxy((*spaceship).x+128,(*spaceship).y+128);
		printf("\xDB");
		break;
	}
}

void clearSpaceship(spaceship_t * spaceship){
	switch((*spaceship).rotation){
	case 0:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+256,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x+384,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x-128,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x-256,(*spaceship).y+128);
		printf(" ");
		break;
	case 1:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x-128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x-256,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y+128);
		printf(" ");
		break;
	case 2:

		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x-128,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x-256,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x-128,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x-256,(*spaceship).y+128);
		printf(" ");
		break;
	case 3:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x-128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x-256,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y-128);
		printf(" ");
		break;
	case 4:

		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+256,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x+384,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x-128,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x-256,(*spaceship).y-128);
		printf(" ");
		break;

	case 5:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+256,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+384,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y-128);
		printf(" ");
		break;
	case 6:

		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+256,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x+384,(*spaceship).y-128);
		printf(" ");
		gotoxy((*spaceship).x+256,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x+384,(*spaceship).y+128);
		printf(" ");
		break;

	case 7:
		gotoxy((*spaceship).x,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+256,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x+384,(*spaceship).y);
		printf(" ");
		gotoxy((*spaceship).x,(*spaceship).y+128);
		printf(" ");
		gotoxy((*spaceship).x+128,(*spaceship).y+128);
		printf(" ");
		break;
	}
}
void drawBullet(bullet_t * bullet){
	gotoxy((*bullet).positionX,(*bullet).positionY);
	printf("*");
}
void drawAlien(alien_t * alien){
	if((*alien).active){
		gotoxy((*alien).x, (*alien).y);
		printf("O");
		/*gotoxy((*alien).x+128, (*alien).y);
		printf("°");
		gotoxy((*alien).x-128, (*alien).y);
		printf("°");*/
		gotoxy((*alien).x+128, (*alien).y);
		printf(">");
		gotoxy((*alien).x-128, (*alien).y);
		printf("<");
		gotoxy((*alien).x+128, (*alien).y-128);
		printf("\xBB");
		gotoxy((*alien).x, (*alien).y-128);
		printf("\xCD");
		gotoxy((*alien).x-128, (*alien).y-128);
		printf("\xC9");
		gotoxy((*alien).x+128, (*alien).y+128);
		printf("\xBC");
		gotoxy((*alien).x, (*alien).y+128);
		printf("\xCD");
		gotoxy((*alien).x-128, (*alien).y+128);
		printf("\xC8");
	}
}
void clearAlien(alien_t * alien){

		gotoxy((*alien).x, (*alien).y);
		printf(" ");
		/*gotoxy((*alien).x+128, (*alien).y);
		printf("°");
		gotoxy((*alien).x-128, (*alien).y);
		printf("°");*/
		gotoxy((*alien).x+128, (*alien).y);
		printf(" ");
		gotoxy((*alien).x-128, (*alien).y);
		printf(" ");
		gotoxy((*alien).x+128, (*alien).y-128);
		printf(" ");
		gotoxy((*alien).x, (*alien).y-128);
		printf(" ");
		gotoxy((*alien).x-128, (*alien).y-128);
		printf(" ");
		gotoxy((*alien).x+128, (*alien).y+128);
		printf(" ");
		gotoxy((*alien).x, (*alien).y+128);
		printf(" ");
		gotoxy((*alien).x-128, (*alien).y+128);
		printf(" ");
}
void drawPowerup(powerup_t * powerup){
	if((*powerup).active){
		gotoxy((*powerup).x, (*powerup).y);
		printf("!");
	}
}

