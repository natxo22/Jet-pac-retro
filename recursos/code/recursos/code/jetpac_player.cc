void InitializePlayer() {
	for(int i=0;i<2;i++){
		(players+i)->px = 400;
		(players+i)->py = 400;
		(players+i)->px2 = (players+i)->px + 42;
		(players+i)->py2 = (players+i)->py + 66;
		(players+i)->vel_x = 10;
		(players+i)->vel_y = 10;
		(players+i)->direction = 1;
		(players+i)->in_ground = true;
		(players+i)->in_air = false;
		(players+i)->animation = 0;
		(players+i)->count_shoots = 0;
		(players+i)->exploding = false;
		(players+i)->explosion_timer = 0;
		(players+i)->score = 0;

		switch(i){
			case 0:	(players+i)->alive=true;
			case 1:	(players+i)->alive=false;
		}

		(players+i)->lives=4;
	}
}

void RestartPlayerPosition(Player *player) {
	player->px = 400;
	player->py = 400;
	player->px2 = player->px + 42;
	player->py2 = player->py + 66;
	player->direction = 1;
	player->in_ground = true;
	player->in_air = false;
	player->animation = 0;
	player->count_shoots = 0;
	player->exploding = false;
	player->explosion_timer = 0;
	player->alive=true;
}

void PlayerAnimation(Player *player) {
		if((player)->animation < 3){
			(player)->animation++;
		}else{
			(player)->animation=0;
		}
}

void PlayerGravity(Player *player) {
    if(player->py2<500){
     player->in_air = true;
     player->in_ground = false;
    }

    for(int i=0;i<3;i++){
        if(player->py2>=500  || (player->py2>=(platform+i)->py && player->py2<(platform+i)->py2
            && player->px2>(platform+i)->px && player->px<((platform+i)->px2))){
         player->in_ground = true;
         player->in_air = false;
        }
    }

    if(player->in_air){
     player->py+=player->vel_y;
     player->py2=player->py+esat::SpriteHeight(*(air_left+0));
    }
}

void PlayerColisionWithPlatforms(Player *player){
	for(int i=0;i<3;i++){
			//Down
			if(player->px2 > (platform+i)->px &&
			   player->px < (platform+i)->px2 &&
			 	 player->py < (platform+i)->py2 + 10 &&
				 player->py > (platform+i)->py2) {
					 player->py = (platform+i)->py2 + 10;
					 player->py2 = player->py + esat::SpriteHeight(*(air_left+player->animation));
			 }

			 //Left
			 if(player->px2 + 10 > (platform+i)->px &&
			 		player->px2 < (platform+i)->px &&
		 			player->py < (platform+i)->py2 &&
					player->py2 > (platform+i)->py) {
		 				player->px = (platform+i)->px-10 - esat::SpriteWidth(*(air_left+player->animation));
		 				player->px2 = player->px + esat::SpriteWidth(*(air_left+player->animation));
 			 }

			 //Right
			 if(player->px-15 < (platform+i)->px2 &&
			 		player->px > (platform+i)->px2 &&
		 			player->py < (platform+i)->py2 &&
					player->py2 > (platform+i)->py) {
			 			player->px = (platform+i)->px2 + 15;
			 			player->px2 = player->px + esat::SpriteWidth(*(air_left+player->animation));
 			 }
		 }
}

void MovePlayer(Player *player) {
	if(player->alive){
		//Left Movement
		if(IsSpecialKeyPressed(esat::kSpecialKey_Right) ){
			player->px+=player->vel_x;
			player->px2=player->px + esat::SpriteWidth(*(ground_left+0));
			player->direction=1;
			PlayerAnimation(player);
		}

		//Right Movement
		if(IsSpecialKeyPressed(esat::kSpecialKey_Left) ){
			player->px-=player->vel_x;
			player->px2 = player->px + esat::SpriteWidth(*(ground_right+0));
			player->direction=0;
			PlayerAnimation(player);
		}

		//Fly
		if(IsSpecialKeyPressed(esat::kSpecialKey_Up) ){
			player->py-=player->vel_y + 7;
	  	player->py2 = player->py + esat::SpriteHeight(*(air_left+0));
			if(player->in_ground){
				player->exploding=true;
			}
			PlayerAnimation(player);
		}


	//Check if it's on the ground and apply gravity
	PlayerGravity(player);
	}
}

void BorderPlayer(Player *player) {
	//Right
	if(player->px>KWindowWidth){
		if(player->in_ground){
			player->px = -1 * esat::SpriteWidth(*(ground_right+0));
		}
		if(player->in_air){
			player->px = -1 * esat::SpriteWidth(*(ground_right+0));
		}
	}
	//Left
	if(player->px2<0){
		player->px = KWindowWidth;
	}

	if(player->py<bitsize*2 + 5){
		player->py = bitsize*2 + 5;
	}
}

void DrawPlayer(Player *player) {
	if((player)->alive) {
		// En el suelo
		if((player)->in_ground){
			switch((player)->direction){
				case 0:	esat::DrawSprite(*(ground_left+((player)->animation)), (player)->px, (player)->py); break; //Izq
				case 1: esat::DrawSprite(*(ground_right+((player)->animation)), (player)->px, (player)->py); break; //Dxa
			}
			// En el aire
		}else{
			switch((player)->direction){
				case 0:	esat::DrawSprite(*(air_left+((player)->animation)), (player)->px, (player)->py);break; //Izq
				case 1: esat::DrawSprite(*(air_right+((player)->animation)), (player)->px, (player)->py);break; //Dxa
			}
		}
		// Smoke animation
		if((player)->exploding){
			esat::DrawSprite(*(explosion+((player)->explosion_timer)), (player)->px, (player)->py + 60);
			if((player)->explosion_timer<2){
				(player)->explosion_timer++;
			}else{
				(player)->explosion_timer=0;
				(player)->exploding=false;
			}
		}
	}
}

void DeathPlayer(Player *player) {
	if(!player->alive) {
		if(player->death_timer < fps) {
			player->death_timer++;
		}
		if(player->death_timer>=fps) {
			player->death_timer=0;
			player->alive=true;
			RestartPlayerPosition(player);
		}
	}
}
