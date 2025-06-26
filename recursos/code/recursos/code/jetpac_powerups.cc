void AppearPowerup() {
	//powerups
	if(rand()%200==0 && !powerup.alive){
		powerup.alive = true;
		powerup.air = true;
		powerup.carry = false;
		powerup.destination = false;
		powerup.appearance = rand()%4;
		powerup.platform = rand()%4;
		powerup.animation = 0;
		switch (powerup.platform) {
			case 0:
				powerup.px = rand()%platform->px  + (24*4);
				powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+powerup.appearance));
				powerup.py = 24*10 - 70;
				powerup.py2 = powerup.py + esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
			break;
			case 1:
				powerup.px = rand()%24*4 + (24*15);
				powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+powerup.appearance));
				powerup.py = 24*13 - 70;
				powerup.py2 = powerup.py + esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
			break;
			case 2:
				powerup.px = rand()%24*6 + (24*24);
				powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+powerup.appearance));
				powerup.py = 24*7 - 70;
				powerup.py2 = powerup.py + esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
			break;
			case 3:
				powerup.px = rand()%576 - esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
				powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+powerup.appearance));
				powerup.py = 500 - 70;
				powerup.py2 = powerup.py + esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
			break;
		}
	}

	//fuel
	if(rand()%75==0 && !powerup.alive && ship.py_disassembled_2 == ship.py && ship.fill < 6) {
		powerup.fuel = true;
		powerup.alive = true;
		powerup.air = true;
		powerup.carry = false;
		powerup.destination = false;
		powerup.appearance = 5;
		powerup.animation = 0;
		powerup.px = rand()%768;
		powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+powerup.appearance));
		powerup.py = 50;
		powerup.py2 = 50 + esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
	}
}

void Animation(){
		//Color animation of diamond
		if(powerup.animation<12){
			powerup.animation++;
		}else{
			powerup.animation=0;
		}

}

void DrawPowerup(){
	float *color = (float*) malloc(10*sizeof(float));

	//Powerups' mask
	*(color+0) = powerup.px;
	*(color+1) = powerup.py;
	*(color+2) = powerup.px2;
	*(color+3) = powerup.py;
	*(color+4) = powerup.px2;
	*(color+5) = powerup.py2;
	*(color+6) = powerup.px;
	*(color+7) = powerup.py2;
	*(color+8) = powerup.px;
	*(color+9) = powerup.py;

	if(powerup.alive){
		switch(powerup.appearance){ //set color mask
			case 0: //Diamond
				if(powerup.animation<3) esat::DrawSetFillColor(86,211,247);
				if(powerup.animation>3 && powerup.animation<6) esat::DrawSetFillColor(189,221,46);
				if(powerup.animation>6 && powerup.animation<9) esat::DrawSetFillColor(57,221,67);
				if(powerup.animation>9 && powerup.animation<12) esat::DrawSetFillColor(216,46,221);
				Animation();
			 break;
			case 1: esat::DrawSetFillColor(57,221,67);break; //bean
			case 2: esat::DrawSetFillColor(189,221,46);break; //gold
			case 3: esat::DrawSetFillColor(86,211,247);break; //triangle
			case 4: esat::DrawSetFillColor(86,211,247);break; //radioactive
			case 5: esat::DrawSetFillColor(216,46,221);break; //fuel

		}
		esat::DrawSolidPath(color,5); //draw mask
		esat::DrawSprite(*(powerup.sprite+powerup.appearance),powerup.px,powerup.py); //draws powerup
	}
}

void UpdateFuel(){
	//Carry fuel
	if(powerup.appearance==5 && powerup.carry){
		powerup.px = (players+g_current_player)->px;
		powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+5));
		powerup.py = (players+g_current_player)->py + 20;
		powerup.py2 = powerup.py  + esat::SpriteHeight(*(powerup.sprite+5));
	}

	//Update condition fuel when arrives to the ship
	if(powerup.appearance==5 && powerup.carry && powerup.px2 > 545 && powerup.px < 550){
		powerup.destination=true;
		powerup.carry=false;
		powerup.px = 528;
		powerup.px2 = powerup.px + esat::SpriteWidth(*(powerup.sprite+5));
	}

	//Drop fuel when arrives ship
	if(powerup.appearance==5 && powerup.destination){
		powerup.py += 3;
		powerup.py2 = powerup.py + esat::SpriteHeight(*(powerup.sprite+5));
	}

	//Reinit powerup and add fuel to ship
	if(powerup.py2>500 && powerup.destination ){
		ship.fill++;
		powerup.alive=false;
		powerup.fuel=false;
		powerup.destination=false;
	}

	//Powerups appear in the air and then fall
	if(powerup.air){
		powerup.py += 5;
		powerup.py2 = powerup.py + esat::SpriteHeight(*(powerup.sprite+powerup.appearance));
	}

	//Collision with platforms
	for(int i=0;i<3;i++){
		if(powerup.py2>=500  || (powerup.py2>=(platform+i)->py && powerup.py2<(platform+i)->py2
			&& powerup.px2>(platform+i)->px && powerup.px<((platform+i)->px2))){
				powerup.air=false;
		}
	}

	//When player dies stop carrying fuel
	if(!(players+g_current_player)->alive && powerup.appearance == 5 && !powerup.destination){
		powerup.alive=false;
		powerup.carry=false;
	}
}

void ColisionPowerUp(){
	if((players+g_current_player)->px < powerup.px2 &&
		 (players+g_current_player)->px2 > powerup.px &&
		 (players+g_current_player)->py < powerup.py2 &&
		 (players+g_current_player)->py2 > powerup.py &&
		 powerup.alive ){

			if(powerup.appearance == 5 && !powerup.carry && !powerup.destination){
				powerup.carry = true;
			}
			if(powerup.appearance<5){
				powerup.alive=false;
				(players+g_current_player)->score += 250;
			}
	}
}
