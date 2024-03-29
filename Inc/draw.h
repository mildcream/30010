/*
 * draw.h
 *
 *  Created on: 14 Jun 2023
 *      Author: moebe
 */

#ifndef DRAW_H_
#define DRAW_H_

typedef struct {
	int32_t x;
	int32_t y;
	int32_t velX;
	int32_t velY;
	int32_t nextPosX;
	int32_t nextPosY;
	int8_t destroyed;
	int8_t hasPowerup;

} asteroid_t ;

/*typedef struct {
	int32_t x;
	int32_t y;
	int32_t velX;
	int32_t velY;
	int32_t nextPosX;
	int32_t nextPosY;
	int32_t orientation;


} spaceship_t ;*/

typedef struct {
	uint16_t x;
	uint16_t y;
	int8_t active;
} alien_t;

typedef struct {
	uint16_t x;
	uint16_t y;
	uint8_t active;
	uint8_t type; // 1 = stopping power, 2 = infinite range, 3 = +1 lives
}powerup_t;

typedef struct {
	int32_t positionX;
	int32_t positionY;
	int32_t vectorX;
	int32_t vectorY;
	int32_t nextPosX;
	int32_t nextPosY;
	int8_t active;
	int8_t counter;
} bullet_t;

void drawAsteroid(asteroid_t * asteroid);
void clearAsteroid(asteroid_t * asteroid);
void drawSpaceship(spaceship_t * spaceship);
void drawSpaceship(spaceship_t * spaceship);
void drawAlien(alien_t * alien);


#endif /* DRAW_H_ */
