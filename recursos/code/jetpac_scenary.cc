
void InitPlatform(){
	(platform+0)->px = 24*5;
	(platform+0)->px2 = 24*4 + 24*7;
	(platform+0)->py = 24*10;
	(platform+0)->py2 = 24*10 + 24;

	(platform+1)->px = 24*16;
	(platform+1)->px2 = 24*15 + 24*5;
	(platform+1)->py = 24*13;
	(platform+1)->py2 = 24*13 + 24;

	(platform+2)->px = 24*25;
	(platform+2)->px2 = 24*24 + 24*7;
	(platform+2)->py = 24*7;
	(platform+2)->py2 = 24*7 + 24;
}

void PlayerEntered(){
	if(ship.fill == 6 && ((players+g_current_player)->px < ship.px + 49) &&
	  ((players+g_current_player)->px2 > ship.px) &&
	  ((players+g_current_player)->py > ship.py)) {
			ship.player_in = true;
			(players+g_current_player)->py = 800;
			SetAllEnemiesDead(&enemies_list);
	}
}

void Lift_Off(){

  if(ship.fill == 6 && ship.stop == 0 && ship.player_in == true){
      ship.py -= 2;
      (BlockFigures+6)->position.y = ship.py+49*3+1;
      (BlockFigures+7)->position.y = ship.py+49*3+1;
      (BlockFigures+4)->position.y = ship.py+1;
      (BlockFigures+5)->position.y = ship.py+49*2;
      (BlockFigures+8)->position.y = ship.py+49*3+10;
      (BlockFigures+10)->position.y = ship.py+49*3;
  }

  if(ship.py < 10 && ship.stop == 0){
		  ship.stop = 1;
      ship.level++;
      ship.fill = 0;
      ship.in_position = true;

			SetAllEnemiesDead(&enemies_list);
			g_level++;
			if(g_level>16) {
				g_level = 1;
				g_difficulty++;
			}
			if( (ship.level ==1) || (ship.level ==5) || (ship.level ==9) || (ship.level ==13) ){
				RestartPlayerPosition((players+g_current_player));
			}
     }

}

void Land(){

  if(ship.stop == 1 && ship.in_position == false){
    ship.fill = 0;
    ship.py=353;
    ship.stop = 0;
    ship.px_disassembled_2 = 24*7;
    ship.py_disassembled_2 =24*10-49;
    ship.px_disassembled_1 = 24*17;
    ship.py_disassembled_1 = 24*13-49;

    (BlockFigures+7)->dimensionY = 0;
    (BlockFigures+6)->position.y = ship.py +49*3;
    (BlockFigures+7)->position.y = ship.py +49*3;
    (BlockFigures+10)->position.y = ship.py +49*3;
	}

  if( ship.stop == 1 && ship.in_position == true){
    ship.py += 2;
    (BlockFigures+6)->position.y = ship.py+49*3 +2;
    (BlockFigures+7)->position.y = ship.py+49*3 +2;
    (BlockFigures+4)->position.y = ship.py +2;
    (BlockFigures+5)->position.y = ship.py+49*2;
    (BlockFigures+8)->position.y = ship.py+49*3+10;
    (BlockFigures+10)->position.y = ship.py+49*3;
    ship.first_part = false;
    ship.second_part = false;
    ship.taked = false;
    ship.taked2 = false;
    ship.player_in =false;
  }


  if( ship.stop == 1 && ship.py > 353){
    ship.py=353;
    ship.stop = 0;
    ship.first_part = false;
    ship.second_part = false;
    ship.taked = false;
    ship.taked2 = false;
    ship.player_in = false;
		RestartPlayerPosition((players+g_current_player));
  }


}

void MaskFollowPlayer() {
  (BlockFigures+9)->position.y = (players+g_current_player)->py;
  (BlockFigures+9)->position.x = (players+g_current_player)->px;
  if(!(players+g_current_player)->alive) {
    (BlockFigures+9)->dimensionX=0;
    (BlockFigures+9)->dimensionY=0;
  } else {
    if((players+g_current_player)->in_ground) {
      (BlockFigures+9)->dimensionX = esat::SpriteWidth(*(ground_left+((players+g_current_player)->animation))) - 3;
      (BlockFigures+9)->dimensionY = esat::SpriteHeight(*(ground_left+((players+g_current_player)->animation)));
    }else{
      (BlockFigures+9)->dimensionX = esat::SpriteWidth(*(air_left+((players+g_current_player)->animation)));
      (BlockFigures+9)->dimensionY = esat::SpriteHeight(*(air_left+((players+g_current_player)->animation)));
    }
  }
}


void Take_Pieces(){
  if(ship.in_position == false){
    if(ship.first_part == false){

      if((players+g_current_player)->px > 24*16 &&
         (players+g_current_player)->px < 24*16+49 &&
         (players+g_current_player)->py > ship.py_disassembled_1 -40 &&
         (players+g_current_player)->py < ship.py_disassembled_1 ) {
          ship.taked = true;
      }
      if(ship.taked == true) {
        ship.px_disassembled_1 = (players+g_current_player)->px+20;
        ship.py_disassembled_1 = (players+g_current_player)->py+20;
        (BlockFigures+4)->position.x = (players+g_current_player)->px;
        (BlockFigures+4)->position.y = (players+g_current_player)->py+20;
        (BlockFigures+8)->position.y = ship.py+49*4+10;
      }

    }


      if(ship.second_part == true){
        if((players+g_current_player)->px > ship.px_disassembled_2 &&
           (players+g_current_player)->px < ship.px_disassembled_2+49 &&
           (players+g_current_player)->py > ship.py_disassembled_2 -40 &&
           (players+g_current_player)->py < ship.py_disassembled_2) {
             ship.taked2 =true;
        }
        if(ship.taked2 == true){
          ship.px_disassembled_2 = (players+g_current_player)->px+20;
          ship.py_disassembled_2 = (players+g_current_player)->py+20;
          (BlockFigures+5)->position.x = (players+g_current_player)->px;
          (BlockFigures+5)->position.y = (players+g_current_player)->py+20;
        }
      }
  }
}

void Drop_Pieces(){

  if(ship.px_disassembled_1 > ship.px-6 && ship.px_disassembled_1 < ship.px + 55){
    ship.px_disassembled_1 = ship.px;

    ship.taked = false;
    ship.first_part = true;
    ship.second_part = true;
    if(ship.py_disassembled_1 < ship.py+49){
      ship.py_disassembled_1 += 2;
    }
    if(ship.py_disassembled_1 > ship.py+49){
      ship.py_disassembled_1 = ship.py+49;

    }

  }

  if(ship.px_disassembled_2 > ship.px-6 && ship.px_disassembled_2 < ship.px + 55){
    ship.px_disassembled_2 = ship.px;

    ship.taked2 = false;

    ship.second_part = false;
    if(ship.py_disassembled_2 < ship.py){
      ship.py_disassembled_2 += 2;
    }
    if(ship.py_disassembled_2 > ship.py){
      ship.py_disassembled_2 = ship.py;
      (BlockFigures+7)->dimensionY = -147;

    }

  }


}

void In_Position(){
  if(ship.in_position == false){

    (BlockFigures+5)->position.x = ship.px_disassembled_2;
    (BlockFigures+5)->position.y = ship.py_disassembled_2;
    if(ship.taked == false){
    (BlockFigures+4)->position.x = ship.px_disassembled_1;
    (BlockFigures+4)->position.y = ship.py_disassembled_1;
    }
  }
}

void drawSprite_Stage(TFigures r){

  if(r.i<4){
    int sprites = r.dimensionX / 24;

      for (int i = 0; i <sprites ;i++){
          if (i == 0){
              esat::DrawSprite(*(r.platform+0), r.position.x+(i*24), r.position.y);
          }//else {
          if(i > 0 && i < sprites - 1) {
              esat::DrawSprite(*(r.platform+1), r.position.x+(i*24), r.position.y);

          }
          if(i == sprites - 1){
              esat::DrawSprite(*(r.platform+2), r.position.x+(sprites*24-24), r.position.y);
          }
      }
  }


}

void DrawSpriteShip(){
    Land();
    if(ship.level >0 && ship.level<5){
      ship.sprite = 0;
    }
    if(ship.level >4 && ship.level<9){
      ship.sprite = 1;
    }
    if(ship.level >8 && ship.level<13){
      ship.sprite = 2;
    }
    if(ship.level >12 && ship.level<17){
      ship.sprite = 3;
    }
    if( (ship.level !=1) && (ship.level !=5) && (ship.level !=9) && (ship.level !=13) ){
    ship.in_position = true;
    esat::DrawSprite(*(ship.sprites_ship_propeller+ship.sprite),  ship.px, ship.py+49*2);
    esat::DrawSprite(*(ship.sprites_ship_body+ship.sprite),  ship.px, ship.py+49);
    esat::DrawSprite(*(ship.sprites_ship_head+ship.sprite),  ship.px, ship.py);
    (BlockFigures+7)->dimensionY = -147;
    }else{
      ship.in_position = false;
    esat::DrawSprite(*(ship.sprites_ship_propeller+ship.sprite),  ship.px, ship.py+49*2);
    esat::DrawSprite(*(ship.sprites_ship_body+ship.sprite) ,ship.px_disassembled_1 ,ship.py_disassembled_1 );
    esat::DrawSprite(*(ship.sprites_ship_head+ship.sprite),ship.px_disassembled_2   ,ship.py_disassembled_2  );
    }


     if((ship.fill== 6 && ship.py<300) ||(ship.stop == 1 && ship.py <304) ){
        if(ship.time < current_time){
        ship.time = current_time + 100;}

        if(ship.time >= current_time + 50 ){
        esat::DrawSprite(*(ship.sprites_combustion+0),ship.px, ship.py+49*3 +12);
        }else{
        esat::DrawSprite(*(ship.sprites_combustion+1),ship.px, ship.py+49*3 +12);
        }
    }
}



void DrawStageItem(TFigures r){

    float *p=NULL;
    p=(float*)malloc((r.points+1)*2*sizeof(float));

    *(p+0)=r.position.x;
    *(p+1)=r.position.y;
    *(p+2)=r.position.x+r.dimensionX;
    *(p+3)=r.position.y;
    *(p+4)=r.position.x+r.dimensionX;
    *(p+5)=r.position.y+r.dimensionY;
    *(p+6)=r.position.x;
    *(p+7)=r.position.y+r.dimensionY;
    *(p+8)=*(p+0);
    *(p+9)=*(p+1);

    esat::DrawSetFillColor(r.colour.r,r.colour.g,r.colour.b);
    esat::DrawSetStrokeColor(0,0,0,255);
    esat::DrawSolidPath(p,r.points+1);
    drawSprite_Stage(r);
    free(p);

}




void SetSet(){
  esat::SpriteHandle spritesheet = esat::SpriteFromFile("recursos/sprites/jetpac_spritesheet.png");
  totalItems = 11 ;

  TFigures cuadrado;

  BlockFigures=(TFigures*)malloc(11*sizeof(TFigures));
  //seteo platform
  cuadrado.position.x = 24*5;
  cuadrado.position.y = 24*10;
  cuadrado.dimensionX = 24*6;
  cuadrado.dimensionY = 24;
  cuadrado.points = 4;
  cuadrado.i =0;
  cuadrado.colour.r = 7;
  cuadrado.colour.g = 127;
  cuadrado.colour.b = 15 ;
  *(cuadrado.platform+0)  = esat::SubSprite(spritesheet, 396, 321, 24, 24  );
  *(cuadrado.platform+1)  = esat::SubSprite(spritesheet, 435, 321, 24, 24  );
  *(cuadrado.platform+2)  = esat::SubSprite(spritesheet, 474, 321, 24, 24  );

  *(BlockFigures+cuadrado.i)=cuadrado;



  //seteo platform 2
  cuadrado.position.x = 24*16;
  cuadrado.position.y = 24*13;
  cuadrado.dimensionX = 24*4;
  cuadrado.dimensionY = 24;
  cuadrado.i = 1 ;
  *(BlockFigures+cuadrado.i)=cuadrado;


  //seteo platform 3
  cuadrado.position.x = 24*25;
  cuadrado.position.y = 24*7;
  cuadrado.i = 2;
  cuadrado.dimensionX = 24*6;
  cuadrado.dimensionY = 24;
  *(BlockFigures+cuadrado.i)=cuadrado;


    //seteo suelo
  cuadrado.position.x = 0;
  cuadrado.position.y = 500;
  cuadrado.dimensionX = 768;
  cuadrado.dimensionY = 24;
  cuadrado.colour.r = 149;
  cuadrado.i = 3;
  cuadrado.colour.g = 145;
  cuadrado.colour.b = 13 ;
  *(BlockFigures+cuadrado.i)=cuadrado;


  cuadrado.position.x = ship.px;
  cuadrado.position.y = ship.py;
  cuadrado.dimensionX = 49;
  cuadrado.dimensionY = 49;
  cuadrado.i=4;
  cuadrado.colour.r = 255;
  cuadrado.colour.g = 255;
  cuadrado.colour.b = 255;
  *(BlockFigures+cuadrado.i)=cuadrado;


  cuadrado.position.x = ship.px;
  cuadrado.position.y = ship.py+49*2;
  cuadrado.dimensionX = 49;
  cuadrado.dimensionY = 49;
  cuadrado.i=5;
  cuadrado.colour.r = 255;
  cuadrado.colour.g = 255;
  cuadrado.colour.b = 255;
  *(BlockFigures+cuadrado.i)=cuadrado;

  cuadrado.position.x = ship.px;
  cuadrado.position.y = ship.py+49*3;
  cuadrado.dimensionX = 49;
  cuadrado.dimensionY = 0;
  cuadrado.i=10;
  cuadrado.colour.r = 213;
  cuadrado.colour.g = 46;
  cuadrado.colour.b = 113;
  *(BlockFigures+cuadrado.i)=cuadrado;

  cuadrado.position.x = ship.px;
  cuadrado.position.y = ship.py+49*3;
  cuadrado.dimensionX = 49;
  cuadrado.dimensionY = -49;
  cuadrado.i=6;
  cuadrado.colour.r = 255;
  cuadrado.colour.g = 255;
  cuadrado.colour.b = 255;
  *(BlockFigures+cuadrado.i)=cuadrado;

  cuadrado.position.x = ship.px;
  cuadrado.position.y = ship.py+49*4+10;
  cuadrado.dimensionX = 49;
  cuadrado.dimensionY = 0;
  cuadrado.i=8;
  cuadrado.colour.r = 188;
  cuadrado.colour.g = 31;
  cuadrado.colour.b = 29;
  *(BlockFigures+cuadrado.i)=cuadrado;

  cuadrado.position.x = (players+g_current_player)->px;
  cuadrado.position.y = (players+g_current_player)->py;
  cuadrado.dimensionX = esat::SpriteWidth(*(ground_left+0));
  cuadrado.dimensionY = esat::SpriteHeight(*(ground_left+0));
  cuadrado.i=9;
  cuadrado.colour.r = 255;
  cuadrado.colour.g = 255;
  cuadrado.colour.b = 255;
  *(BlockFigures+cuadrado.i)=cuadrado;

  cuadrado.position.x = ship.px;
  cuadrado.position.y = ship.py+49*3;
  cuadrado.dimensionX = 49;
  cuadrado.dimensionY = 0;
  cuadrado.i=7;
  cuadrado.colour.r = 255;
  cuadrado.colour.g = 255;
  cuadrado.colour.b = 255;
  *(BlockFigures+cuadrado.i)=cuadrado;
}



void SetShip(){
  esat::SpriteHandle spritesheet = esat::SpriteFromFile("recursos/sprites/jetpac_spritesheet.png");
  *(ship.sprites_ship_head+0)  = esat::SubSprite(spritesheet, 239, 422, 49, 49  );
  *(ship.sprites_ship_body+0)  = esat::SubSprite(spritesheet, 239, 492, 49, 49  );
  *(ship.sprites_ship_propeller+0)  = esat::SubSprite(spritesheet, 239, 558, 49, 49  );
  //
  *(ship.sprites_ship_head+1)  = esat::SubSprite(spritesheet, 332, 422, 49, 49  );
  *(ship.sprites_ship_body+1)  = esat::SubSprite(spritesheet, 332, 492, 49, 49  );
  *(ship.sprites_ship_propeller+1)  = esat::SubSprite(spritesheet, 332, 558, 49, 49  );
  //
  *(ship.sprites_ship_head+2)  = esat::SubSprite(spritesheet, 461, 422, 49, 49  );
  *(ship.sprites_ship_body+2)  = esat::SubSprite(spritesheet, 461, 492, 49, 49  );
  *(ship.sprites_ship_propeller+2)  = esat::SubSprite(spritesheet, 461, 561, 49, 49  );
  //
  *(ship.sprites_ship_head+3)  = esat::SubSprite(spritesheet, 587, 422, 49, 49  );
  *(ship.sprites_ship_body+3)  = esat::SubSprite(spritesheet, 587, 492, 49, 49  );
  *(ship.sprites_ship_propeller+3)  = esat::SubSprite(spritesheet, 587, 558, 49, 49);



  *(ship.sprites_combustion+0)  = esat::SubSprite(spritesheet, 350, 638, 49, 46  );
  *(ship.sprites_combustion+1)  = esat::SubSprite(spritesheet, 440, 638, 49, 46  );


}

void FillFuel(){
  if(ship.fill == 0){
  (BlockFigures+10)->dimensionY = 0;

  }
  if(ship.fill == 1){
  (BlockFigures+10)->dimensionY = -25;
  }
    if(ship.fill == 2){
  (BlockFigures+10)->dimensionY = -49;
  }

  if(ship.fill == 3){
  (BlockFigures+10)->dimensionY = -73;

  }

  if(ship.fill == 4){
  (BlockFigures+10)->dimensionY = -98;

  }

  if(ship.fill == 5){
  (BlockFigures+10)->dimensionY = -122;

  }

  if(ship.fill == 6){
  (BlockFigures+10)->dimensionY = -147;

  }

}

void FullFuel(){
  if((ship.fill== 6 && ship.py<300) ||(ship.stop == 1 && ship.py <304) ){

    (BlockFigures+8)->dimensionY = 45;
  }else{
    (BlockFigures+8)->dimensionY = 0;
  }
}

void DrawSet(){
  for(int i=0;i<totalItems;i++) {
    DrawStageItem(*(BlockFigures+i));
  }
}
