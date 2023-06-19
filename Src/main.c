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
void lcdInfo(uint32_t lives, char lifestring[], uint32_t score, char scorestring[], uint32_t highscore, char highscorestring[]){
	memset(buffer, 0x00, 512);
	sprintf(lifestring, "Lives: %d", lives);
	lcd_write_string(lifestring, 1);
	lcd_push_buffer(buffer);
	sprintf(scorestring, "Score: %d", score);
	lcd_write_string(scorestring, 3);
	sprintf(highscorestring, "High score: %d", highscore);
	lcd_write_string(highscorestring, 4);
	lcd_push_buffer(buffer);
}



int main(void)
{


	uart_init(576000);
	configureTimer();
	clrscr();
	lcd_init();
	initPins();
	//window(1440, 640, 11520, 3840);

	int32_t highscore = 0;
	char highscorestring[12];

	/*asteroids.x = 384;
	asteroids.y = 384;
	asteroids.velX = 1;
	asteroids.velY = 1;
	asteroids.destroyed = 0;
	asteroids.hasPowerup = 1;*/





	while(1){
		clrscr();
		int dir = 0;
		uint32_t lives = 3;
		char lifestring[8];
		uint32_t score = 0;
		char scorestring[8];
		asteroid_t asteroids[8];
		int8_t bulletCount = 0;

		spaceship_t spaceship_p = {1984, 1024, 2, 0, 0};
		gotoxy(spaceship_p.x, spaceship_p.y);
		printf("\xDB");
		gotoxy(spaceship_p.x - (1 << 7), spaceship_p.y - (1 << 7));
		printf("\xDB");
		gotoxy(spaceship_p.x - (1 << 7), spaceship_p.y + (1 << 7));
		printf("\xDB");

		for(int i = 0; i < 8; i++){
			asteroids[i].x = 384*2*i;
			asteroids[i].y = 384*2*i;
			asteroids[i].velX = 4*i;
			asteroids[i].velY = 4*-i;
			asteroids[i].destroyed = 0;
			if(i == 5){
				asteroids[i].hasPowerup = 1;
			}
		}

		alien_t alien;
		alien.x = 16000;
		alien.y = 8000;
		alien.active = 1;

		powerup_t powerup;
		powerup.x = 0;
		powerup.y = 0;
		powerup.active = 0;
		powerup.type = 2;

		bullet_t bullet[8];
		for(int i = 0; i < 8; i++){
			spawnBullet(&bullet[i]);
		}

		lcdInfo(lives, &lifestring, score, &scorestring, highscore, &highscorestring);
		drawAlien(&alien);

		while(1){


			for(int i = 0; i < 80; i++){
				do_the_thing(&spaceship_p, dir);
				for(int l = 0; l < 8; l++)	{
					clearAsteroid(&asteroids[l]);
					calculateNextAst(&asteroids[l]);
					updatePosAst(&asteroids[l]);
					drawAsteroid(&asteroids[l]);
				}
				clearAlien(&alien);
				moveAlien(&alien, &spaceship_p);
				drawAlien(&alien);
				drawPowerup(&powerup);
				for(int j = 0; j < 8; j++){
					moveBullet(&bullet[j]);
				}
				for(int k = 0; k < 8; k++){
					if(shipAsteroidCollision(&spaceship_p, &asteroids[k])){
						gotoxy(1600,1600);
						printf("Colission!");
						lives = lives - 1;
						if(lives == 0){
							break;
						}
						score = score +40;
						if(score > highscore){
							highscore = score;
						}
						lcdInfo(lives, &lifestring, score, &scorestring, highscore, &highscorestring);
					}
				}
				if(shipAlienCollision(&spaceship_p, &alien)){
					gotoxy(3200,3200);
					printf("Rumvæsenet har spist dig!");
					lives = lives - 1;
					if(lives == 0){
						break;
					}
					score = score +100;
					if(score > highscore){
						highscore = score;
					}
					lcdInfo(lives, &lifestring, score, &scorestring, highscore, &highscorestring);
				}

				for(int j = 0; j < 8; j++){
					for(int a = 0; a < 8; a++){
						if(asteroidBulletCollision(&asteroids[a], &bullet[j], &spaceship_p)){
							score += 40;
							if(asteroids[a].hasPowerup){
								powerup.x = asteroids[a].x;
								powerup.y = asteroids[a].y;
								powerup.active = 1;
								gotoxy(powerup.x, asteroids[a].y);
								printf("!");

							}
							lcdInfo(lives, &lifestring, score, &scorestring, highscore, &highscorestring);

						}
					}
				}
				for(int j = 0; j < 8; j++){
					if(bulletAlienCollision(&bullet[j], &alien, &spaceship_p)){
						score += 100;
						lcdInfo(lives, &lifestring, score, &scorestring, highscore, &highscorestring);
					}
				}
				pickupPowerup(&spaceship_p, &powerup, lives);
				if(spaceship_p.infiniteRange){
					for(int j = 0; j < 8; j++ ){
						bullet[j].counter = 20;
					}
				}
				//for(int b = 0; b < 8; b++){
				//clearAsteroid(&asteroids[b]);
				//}

			}
			shoot(&bullet[bulletCount], &spaceship_p);
			bulletCount++;
			if(bulletCount > 7){
				bulletCount = 0;
			}
			if(score > highscore){
				highscore = score;
			}
			lcdInfo(lives, &lifestring, score, &scorestring, highscore, &highscorestring);
			if(lives == 0){
				break;
			}
		}
	}
}
