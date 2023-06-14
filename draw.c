#include "stm32f30x_conf.h"
#include "stm32f30x_conf.h"
#include "draw.h"
#include "ansi.h"


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

void clearAsteroid(asteroid_t * asteroid){
	gotoxy((*asteroid).positionX-8,(*asteroid).positionY-8);
	printf(" ");
	gotoxy((*asteroid).positionX,(*asteroid).positionY-8);
	printf(" ");
	gotoxy((*asteroid).positionX+8,(*asteroid).positionY-8);
	printf(" ");
	gotoxy((*asteroid).positionX-16,(*asteroid).positionY);
	printf(" ");
	gotoxy((*asteroid).positionX+16,(*asteroid).positionY);
	printf(" ");
	gotoxy((*asteroid).positionX-8,(*asteroid).positionY+8);
	printf(" ");
	gotoxy((*asteroid).positionX,(*asteroid).positionY+8);
	printf(" ");
	gotoxy((*asteroid).positionX+8,(*asteroid).positionY+8);
	printf(" ");
}



void drawSpaceship(spaceship_t * spaceship){
	switch((*spaceship).orientation){
	case 0:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY+8);
		printf("\xDB");
		break;
	case 1:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY+8);
		printf("\xDB");
		break;
	case 2:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY+8);
		printf("\xDB");
		break;
	case 3:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY-8);
		printf("\xDB");
		break;
	case 4:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY-8);
		printf("\xDB");
		break;

	case 5:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY-8);
		printf("\xDB");
		break;
	case 6:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY-8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY+8);
		printf("\xDB");
		break;

	case 7:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY);
		printf("\xDB");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+8);
		printf("\xDB");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY+8);
		printf("\xDB");
		break;
	}
}

void clearSpaceship(spaceship_t * spaceship){
	switch((*spaceship).orientation){
	case 0:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY+8);
		printf(" ");
		break;
	case 1:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY+8);
		printf(" ");
		break;
	case 2:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY+8);
		printf(" ");
		break;
	case 3:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY-8);
		printf(" ");
		break;
	case 4:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX-8,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX-16,(*spaceship).positionY-8);
		printf(" ");
		break;

	case 5:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY-8);
		printf(" ");
		break;
	case 6:

		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY-8);
		printf(" ");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY+8);
		printf(" ");
		break;

	case 7:
		gotoxy((*spaceship).positionX,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+16,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX+24,(*spaceship).positionY);
		printf(" ");
		gotoxy((*spaceship).positionX,(*spaceship).positionY+8);
		printf(" ");
		gotoxy((*spaceship).positionX+8,(*spaceship).positionY+8);
		printf(" ");
		break;
	}
}
void drawBullet(bullet_t * bullet){
	gotoxy((*bullet).positionX,(*bullet).positionY);
	printf("*");
}


