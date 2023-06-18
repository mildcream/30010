#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "timer.h"
#include "lcd.h"
#include "charset.h"
#include "spaceship.h"
#include "analogJoystick.h"
#include "draw.h"
#include "position.h"
#include "bullet.h"
void lcdInfo(uint32_t lives, char lifestring[], uint32_t score, char scorestring[]){
	memset(buffer, 0x00, 512);
	sprintf(lifestring, "Lives: %d", lives);
	lcd_write_string(lifestring, 1);
	lcd_push_buffer(buffer);
	sprintf(scorestring, "Score: %d", score);
	lcd_write_string(scorestring, 3);
	lcd_push_buffer(buffer);
}

int main(void)
{
	int dir = 0;
	uint32_t lives = 3;
	char lifestring[8];
	uint32_t score = 0;
	char scorestring[8];
	int count = 0;
	asteroid_t asteroids;

	uart_init(576000);
	configureTimer();
	clrscr();
	lcd_init();
	initPins();
	//window(1440, 640, 11520, 3840);
	spaceship_t spaceship_p = {1984, 1024, 2, 0, 0};
	gotoxy(spaceship_p.x, spaceship_p.y);
	printf("\xDB");
	gotoxy(spaceship_p.x - (1 << 7), spaceship_p.y - (1 << 7));
	printf("\xDB");
	gotoxy(spaceship_p.x - (1 << 7), spaceship_p.y + (1 << 7));
	printf("\xDB");

	int8_t bulletCount = 0;

	asteroids.x = 384;
	asteroids.y = 384;
	asteroids.velX = 1;
	asteroids.velY = 1;
	asteroids.destroyed = 0;
	asteroids.hasPowerup = 1;

	alien_t alien;
	alien.x = 8000;
	alien.y = 2000;
	alien.active = 1;

	powerup_t powerup;
	powerup.x = 0;
	powerup.y = 0;
	powerup.active = 0;
	powerup.type = 3;

	int8_t ppowerup = 1;

	bullet_t bullet[8];
	for(int i = 0; i < 8; i++){
		spawnBullet(&bullet[i]);
	}

	lcdInfo(lives, &lifestring, score, &scorestring);
	drawAlien(&alien);

	while(1){
		/*if (uart_get_count() == 1) {
			dir = string_check(read_uart_data(1));
			centisecond = 0;
		}
		update_spaceship(&spaceship_p, dir);
		if (centisecond > 20) {
			wind_resistance(&spaceship_p);
			centisecond = 0;
		}

		//lav en konstant movement der er høj så længe der er forskel på temp_velocity og celocity. Når movement er lav så kører wind_resistance
		//Sæt timeren til 0 ved input fra tastaturet idiot

		gotoxy(14080, 1024);
		printf("velocity: x = %d, y = %d ", spaceship_p.velX, spaceship_p.velY);
		*dir = 0;*/
		for(int i = 0; i < 100; i++){
			do_the_thing(&spaceship_p, dir);
			calculateNextAst(&asteroids);
			updatePosAst(&asteroids);
			drawAsteroid(&asteroids);
			clearAlien(&alien);
			moveAlien(&alien, &spaceship_p);
			drawAlien(&alien);
			drawPowerup(&powerup);
			for(int j = 0; j < 8; j++){
				moveBullet(&bullet[j]);
			}

			if(shipAsteroidCollision(&spaceship_p, &asteroids)){
				gotoxy(1600,1600);
				printf("Colission!");
				lives = lives - 1;
				score = score +40;
				lcdInfo(lives, &lifestring, score, &scorestring);
			}
			if(shipAlienCollision(&spaceship_p, &alien)){
				gotoxy(3200,3200);
				printf("Rumvæsenet har spist dig!");
				lives = lives - 1;
				score = score +100;
				lcdInfo(lives, &lifestring, score, &scorestring);
			}
			for(int j = 0; j < 8; j++){
				if(asteroidBulletCollision(&asteroids, &bullet[j], &spaceship_p)){
					score += 40;
					if(asteroids.hasPowerup){
						powerup.x = asteroids.x;
						powerup.y = asteroids.y;
						powerup.active = 1;
						gotoxy(powerup.x, asteroids.y);
						printf("!");

					}
					lcdInfo(lives, &lifestring, score, &scorestring);

				}
			}
			for(int j = 0; j < 8; j++){
				if(bulletAlienCollision(&bullet[j], &alien, &spaceship_p)){
					score += 100;
					lcdInfo(lives, &lifestring, score, &scorestring);
				}
			}
			pickupPowerup(&spaceship_p, &powerup, lives);
			if(spaceship_p.infiniteRange){
				for(int j = 0; j < 8; j++ ){
					bullet[j].counter = 20;
				}
			}
			//for(int i = 0; i <1500000; i++){}
			clearAsteroid(&asteroids);

		}
		shoot(&bullet[bulletCount], &spaceship_p);
		bulletCount++;
		if(bulletCount > 7){
			bulletCount = 0;
		}
		lcdInfo(lives, &lifestring, score, &scorestring);
	}
}
