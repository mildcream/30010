#include "stdio.h"
#include "stm32f30x_conf.h"
#include "ansi.h"
#include "30010_io.h"
#include "stdint.h"
#include "draw.h"
#include "position.h"
#include "lcd.h"
#include "charset.h"
#include "timer.h"

void lcdInfo(uint8_t lives, char lifestring[], uint8_t score, char scorestring[]){
	memset(buffer, 0x00, 512);
	sprintf(lifestring, "Lives: %d", lives);
	lcd_write_string(lifestring, 1);
	lcd_push_buffer(buffer);
	sprintf(scorestring, "Score: %d", score);
	lcd_write_string(scorestring, 3);
	lcd_push_buffer(buffer);

}




int main() {
	uart_init(576000);
	clrscr();
	uint8_t lives = 3;
	char lifestring[8];
	uint8_t score = 0;
	char scorestring[8];
	int count = 0;
	asteroid_t asteroids;

	asteroids.positionX = 24;
	asteroids.positionY = 24;
	asteroids.vectorX = 4;
	asteroids.vectorY = 4;
	asteroids.destroyed = 0;

	spaceship_t spaceship;

	spaceship.positionX = 96;
	spaceship.positionY = 96;
	spaceship.vectorX = -8;
	spaceship.vectorY = -8;
	spaceship.orientation = 0;
	gotoxy(0,0);
	clrscr();
	lcd_init();
	lcdInfo(lives, &lifestring, score, &scorestring);
	while(1){
		// Ting til test af positionsopdatering
		for(int j = 0; j < 20; j++){
		calculateNextAst(&asteroids);
		calculateNextShip(&spaceship);
		updatePosAst(&asteroids);
		updatePosShip(&spaceship);
		drawAsteroid(&asteroids);
		drawSpaceship(&spaceship);
		if(shipAsteroidCollision(&spaceship, &asteroids)){
			gotoxy(100,100);
			printf("Colission!");
			lives = lives - 1;
			score = score +40;
			lcdInfo(lives, &lifestring, score, &scorestring);
		}
		for(int i = 0; i <1500000; i++){}
		clearAsteroid(&asteroids);
		clearSpaceship(&spaceship);
		count++;
		if(count == 25){
			clrscr();
			count = 0;
		}
		}
		spaceship.orientation++;
		if(spaceship.orientation == 8){
			spaceship.orientation = 0;
		}




	}


}
