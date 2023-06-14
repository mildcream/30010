/*
 * draw.h
 *
 *  Created on: 14 Jun 2023
 *      Author: moebe
 */

#ifndef DRAW_H_
#define DRAW_H_

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

void drawAsteroid(asteroid_t * asteroid);
void clearAsteroid(asteroid_t * asteroid);
void drawSpaceship(spaceship_t * spaceship);
void drawSpaceship(spaceship_t * spaceship);
void drawBullet(bullet_t * bullet);


#endif /* DRAW_H_ */
