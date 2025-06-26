
void InitializeShoot(){
	for(int i=0;i<g_maxshoots;i++){ //10->max disp
		(player_shoots+i)->shooting = false;
		(player_shoots+i)->border = false;
		(player_shoots+i)->speed = 30;
		(player_shoots+i)->max_width = 400;
	}
}

void DetectPlayerShoot(Player *player){
	int margin=15, aux=0, random=0;


	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Space) && player->count_shoots < g_maxshoots){ //no se cuantos puede disparar como max pongo 5 de ejemplo
		player->count_shoots++;


		for(int i=0;i<player->count_shoots;i++){
			if((player_shoots+i)->shooting == false){
				if(player->direction==0){
					(player_shoots+i)->px = player->px - margin;
					(player_shoots+i)->second_px = (player_shoots+i)->px + KWindowWidth;
					(player_shoots+i)->px2 = (player_shoots+i)->px - margin;
					(player_shoots+i)->second_px2 = (player_shoots+i)->px2 + KWindowWidth;
					(player_shoots+i)->direction=0;
				} else {
					(player_shoots+i)->px = player->px + esat::SpriteWidth( *(ground_right+0) ) + margin;
					(player_shoots+i)->second_px = (player_shoots+i)->px - KWindowWidth;
					(player_shoots+i)->px2 = (player_shoots+i)->px + margin;
					(player_shoots+i)->second_px2 = (player_shoots+i)->px2 - KWindowWidth;
					(player_shoots+i)->direction=1;
				}
				(player_shoots+i)->aux_px = (player_shoots+i)->px;
				(player_shoots+i)->py = player->py + (esat::SpriteHeight(*(ground_right+0))/2);
				random = rand()%30;
				(player_shoots+i)->shooting = true;

				if(random<20){
						(player_shoots+i)->color.r = 255;
						(player_shoots+i)->color.g = 255;
						(player_shoots+i)->color.b = 255;
				}else if(random>20&&random<25){
						(player_shoots+i)->color.r = 255;
						(player_shoots+i)->color.g = 51;
						(player_shoots+i)->color.b = 224;
				}else{
						(player_shoots+i)->color.r = 51;
						(player_shoots+i)->color.g = 255;
						(player_shoots+i)->color.b = 255;
				}
			}
		}
	}
}

void UpdatePlayerShoot(Player *player) {

	for(int i=0;i<g_maxshoots;i++) {

		if((player_shoots+i)->shooting) {

			switch((player_shoots+i)->direction){
				case 0:
					if((player_shoots+i)->aux_px - (player_shoots+i)->px2 < (player_shoots+i)->max_width){
						(player_shoots+i)->px2-=(player_shoots+i)->speed;
						(player_shoots+i)->second_px2-=(player_shoots+i)->speed;
					 }else{
						 (player_shoots+i)->px-=(player_shoots+i)->speed;
						 (player_shoots+i)->second_px-=(player_shoots+i)->speed;
					 }

					if((player_shoots+i)->px - (player_shoots+i)->px2 < 1){
						(player_shoots+i)->shooting=false;
						(player_shoots+i)->border=false;
						player->count_shoots--;
					}

					if((player_shoots+i)->px < KWindowWidth){
						(player_shoots+i)->border=true;
					}

					(player_shoots+i)->width = 	(player_shoots+i)->px - (player_shoots+i)->px2;
					(player_shoots+i)->second_width = 	(player_shoots+i)->second_px - (player_shoots+i)->second_px2;

				break;
				case 1:
				 if((player_shoots+i)->px2 - (player_shoots+i)->aux_px < (player_shoots+i)->max_width){
					(player_shoots+i)->px2+=(player_shoots+i)->speed;
					(player_shoots+i)->second_px2+=(player_shoots+i)->speed;
				 }else{
					 (player_shoots+i)->px+=(player_shoots+i)->speed;
					 (player_shoots+i)->second_px+=(player_shoots+i)->speed;
				 }

				if((player_shoots+i)->px2 - (player_shoots+i)->px < 1){
					(player_shoots+i)->shooting=false;
					player->count_shoots--;
				}

				if((player_shoots+i)->px > KWindowWidth){
					(player_shoots+i)->border=true;
				}

				(player_shoots+i)->width = 	(player_shoots+i)->px2 - (player_shoots+i)->px;
				(player_shoots+i)->second_width = 	(player_shoots+i)->second_px2 - (player_shoots+i)->second_px;


				break;
			}
		}
	}
}

void DrawPlayerShoot(){
	for(int i=0;i<g_maxshoots;i++){
		if((player_shoots+i)->shooting){
			esat::DrawSetStrokeColor((player_shoots+i)->color.r,(player_shoots+i)->color.g,(player_shoots+i)->color.b);

			if((player_shoots+i)->border){
				esat::DrawLine((player_shoots+i)->second_px, (player_shoots+i)->py, (player_shoots+i)->second_px2, (player_shoots+i)->py);
			}
			esat::DrawLine((player_shoots+i)->px, (player_shoots+i)->py, (player_shoots+i)->px2, (player_shoots+i)->py);
		}
	}
}
