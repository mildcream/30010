#include "stdio.h"
#include "stm32f30x_conf.h"
#include "ansi.h"
#include "30010_io.h"
#include "stdint.h"
#include "draw.h"
#include "lcd.h"
#include "charset.h"
#include "timer.h"


void calculateNextAst( asteroid_t * asteroid){
	(*asteroid).nextPosX = (*asteroid).positionX + (*asteroid).vectorX;
	(*asteroid).nextPosY = (*asteroid).positionY + (*asteroid).vectorY;
	if((*asteroid).nextPosX > 128*190){
		(*asteroid).nextPosX = 0;
	} else if((*asteroid).nextPosX < 0) {
		(*asteroid).nextPosX = 128*190;
	}
	if((*asteroid).nextPosY > 128*55){
		(*asteroid).nextPosY = 0;
	} else if((*asteroid).nextPosY < 0) {
		(*asteroid).nextPosY = 128*55;
	}
}

void calculateNextShip( spaceship_t * spaceship){
	(*spaceship).nextPosX = (*spaceship).positionX + (*spaceship).vectorX;
	(*spaceship).nextPosY = (*spaceship).positionY + (*spaceship).vectorY;
	if((*spaceship).nextPosX > 128*190){
		(*spaceship).nextPosX = 0;
	} else if((*spaceship).nextPosX < 0) {
		(*spaceship).nextPosX = 128*190;
	}
	if((*spaceship).nextPosY > 128*55){
		(*spaceship).nextPosY = 0;
	} else if((*spaceship).nextPosY < 0) {
		(*spaceship).nextPosY = 128*55;
	}
}

void updatePosAst( asteroid_t * asteroid){

	(*asteroid).positionX = (*asteroid).nextPosX;
	(*asteroid).positionY = (*asteroid).nextPosY;
}

void updatePosShip( spaceship_t * spaceship){

	(*spaceship).positionX = (*spaceship).nextPosX;
	(*spaceship).positionY = (*spaceship).nextPosY;
}

int32_t shipAsteroidCollision(spaceship_t * spaceship, asteroid_t * asteroid ){
	 	int32_t astXMax = (*asteroid).positionX+128;
		int32_t astXMin = (*asteroid).positionX-128;
		int32_t astYMax = (*asteroid).positionY+128;
		int32_t astYMin = (*asteroid).positionY-128;
		int32_t withinX = (((*spaceship).positionX <  astXMax) && ((*spaceship).positionX >  astXMin)) || (((*spaceship).positionX+16 <  astXMax) && ((*spaceship).positionX+16 >  astXMin));
		int32_t withinY = ((*spaceship).positionY <  astYMax) && ((*spaceship).positionY >  astYMin);

	if(withinX && withinY && !((*asteroid).destroyed)){
		(*asteroid).destroyed = 1;
		return 1;
	} else {
		return 0;
	}
}

int32_t asteroidBulletCollision(asteroid_t * asteroid, bullet_t * bullet){
 	int32_t astXMax = (*asteroid).positionX+256;
	int32_t astXMin = (*asteroid).positionX-256;
	int32_t astYMax = (*asteroid).positionY+256;
	int32_t astYMin = (*asteroid).positionY-256;
	int32_t withinX = ((*bullet).positionX <  astXMax) && ((*bullet).positionX >  astXMin);
	int32_t withinY = ((*bullet).positionY <  astYMax) && ((*bullet).positionY >  astYMin);
	if(withinX && withinY && !((*asteroid).destroyed)){
		(*asteroid).destroyed = 1;
		return 1;
	} else {
		return 0;
	}
}
