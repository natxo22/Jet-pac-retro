

void TextSpectrum(){
	esat::DrawSetTextFont("./recursos/font/zx-spectrum-7/zx_spectrum-7.ttf");
}

void WritteWhite(){						//Funcion para escribir en Blanco
	esat::DrawSetTextBlur(0);
  esat::DrawSetFillColor(255,255,255);
  esat::DrawSetTextSize(20 * redimension);
}

void WritteBlack(){						//Funcion para escribir en Negro
	esat::DrawSetTextBlur(0);
  esat::DrawSetFillColor(0,0,0);
  esat::DrawSetTextSize(20 * redimension);
}

void WritteBlue(){						//Funcion para escribir en Azul
	esat::DrawSetTextBlur(0);
  esat::DrawSetFillColor(0,195,217);
  esat::DrawSetTextSize(20 * redimension);
}

void WritteYellow(){						//Funcion para escribir en Amarillo
	esat::DrawSetTextBlur(0);
  esat::DrawSetFillColor(255,240,0);
  esat::DrawSetTextSize(20 * redimension);
}

void DrawMask(){

/*PLAYER MASK                                                      PLAYER MASK*/
	p = (float*) malloc ( 10 * sizeof (float));


	*(p+0) = playermask.pos.x;
	*(p+1) = playermask.pos.y;
	*(p+2) = playermask.pos.x + bitsize * playermask.textsize;
	*(p+3) = playermask.pos.y;
	*(p+4) = playermask.pos.x + bitsize * playermask.textsize;
	*(p+5) = playermask.pos.y + bitsize;
	*(p+6) = playermask.pos.x;
	*(p+7) = playermask.pos.y + bitsize;
	*(p+8) = *(p+0);
	*(p+9) = *(p+1);


/*MOVEMENT MASK                                                  MOVEMENT MASK*/
	m = (float*) malloc ( 10 * sizeof (float));


	*(m+0) = movementmask.pos.x;
	*(m+1) = movementmask.pos.y;
	*(m+2) = movementmask.pos.x + bitsize * movementmask.textsize;
	*(m+3) = movementmask.pos.y;
	*(m+4) = movementmask.pos.x + bitsize * movementmask.textsize;
	*(m+5) = movementmask.pos.y + bitsize;
	*(m+6) = movementmask.pos.x;
	*(m+7) = movementmask.pos.y + bitsize;
	*(m+8) = *(m+0);
	*(m+9) = *(m+1);

	/*    LIVES MASK                        	                          LIVES MASK*/
		l_1 = (float*) malloc ( 10 * sizeof (float));

		livesmask_1.pos.x = bitsize * 9;
		livesmask_1.pos.y = 3;

		livesmask_2.pos.x = bitsize * 21;
		livesmask_2.pos.y = 3;

		*(l_1+0) = livesmask_1.pos.x;
		*(l_1+1) = livesmask_1.pos.y;
		*(l_1+2) = livesmask_1.pos.x + 18;
		*(l_1+3) = livesmask_1.pos.y;
		*(l_1+4) = livesmask_1.pos.x + 18;
		*(l_1+5) = livesmask_1.pos.y + bitsize;
		*(l_1+6) = livesmask_1.pos.x;
		*(l_1+7) = livesmask_1.pos.y + bitsize;
		*(l_1+8) = *(l_1+0);
		*(l_1+9) = *(l_1+1);

		l_2 = (float*) malloc ( 10 * sizeof (float));


		*(l_2+0) = livesmask_2.pos.x;
		*(l_2+1) = livesmask_2.pos.y;
		*(l_2+2) = livesmask_2.pos.x + 18;
		*(l_2+3) = livesmask_2.pos.y;
		*(l_2+4) = livesmask_2.pos.x + 18;
		*(l_2+5) = livesmask_2.pos.y + bitsize;
		*(l_2+6) = livesmask_2.pos.x;
		*(l_2+7) = livesmask_2.pos.y + bitsize;
		*(l_2+8) = *(l_2+0);
		*(l_2+9) = *(l_2+1);

esat::DrawSetFillColor(255, 255, 255);

}

void GameSelection(){

/*		1																																			 1*/
	if(esat::IsKeyDown('1') && playerselection != 1){
		playerselection = 1;
	}
	if(blink >= fps && playerselection == 1){
		playermask.pos.y = bitsize * 7;
		playermask.pos.x = bitsize * 6;
		playermask.textsize = 17;
		DrawMask();
		esat::DrawSolidPath(p,5);
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 8, "1   1 PLAYER GAME");
	}
/*		2																																			 2*/
	if(esat::IsKeyDown('2') && playerselection != 2){
		playerselection = 2;
	}
	if(blink >= fps && playerselection == 2){
		playermask.pos.y = bitsize * 9;
		playermask.pos.x = bitsize * 6;
		playermask.textsize = 17;
		DrawMask();
		esat::DrawSolidPath(p,5);
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 10, "2   2 PLAYER GAME");
	}
/*		3																																		 	 3*/
	if(esat::IsKeyDown('3') && moveselection != 1){
		moveselection = 1;
	}
	if(blink >= fps && moveselection == 1){
		movementmask.pos.y = bitsize * 11;
		movementmask.pos.x = bitsize * 6;
		movementmask.textsize = 12;
		DrawMask();
		esat::DrawSolidPath(m,5);
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 12, "3   KEYBOARD");
	}
/*		4																																			 4*/
	if(esat::IsKeyDown('4') && moveselection != 2){
		moveselection = 2;
	}
	if(blink >= fps && moveselection == 2){
		movementmask.pos.y = bitsize * 13;
		movementmask.pos.x = bitsize * 6;
		movementmask.textsize = 21;
		DrawMask();
		esat::DrawSolidPath(m,5);
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 14, "4   KEMPSTON JOYSTICK");
	}

/*    START                                                              START*/
	if(esat::IsKeyDown('5') && playerselection == 1 && gamestate == 0 && moveselection == 1){
		gamestate++;
		//1 JUGADOR KEYBOARD
	}
	if(esat::IsKeyDown('5') && playerselection == 2 && gamestate == 0 && moveselection == 1){
		gamestate += 2;
		//2 JUGADORES KEYBOARD
	}
	if(esat::IsKeyDown('5') && playerselection == 1 && gamestate == 0 && moveselection == 2){
		gamestate = -1;
		//1 JUGADOR JOYSTICK
	}
	if(esat::IsKeyDown('5') && playerselection == 2 && gamestate == 0 && moveselection == 2){
		gamestate = -2;
		//2 JUGADORES JOYSTICK
	}
/*    BLINK                                                              BLINK*/
	if(blink >= fps * 2){
		blink = 0;
	}
	blink++;
}

void Introduction(){
/*    WHITE TEXT                                                    WHITE TEXT*/
	TextSpectrum();
	WritteWhite();

	esat::DrawText(bitsize * 2, bitsize, "1UP                      2UP");
	esat::DrawText(bitsize * 6, bitsize * 5, "JETPAC GAME SELECTION");
	if(playerselection != 1 || blink <= fps){
		esat::DrawText(bitsize * 6, bitsize * 8, "1   1 PLAYER GAME");
	}
	if(playerselection != 2 || blink <= fps){
		esat::DrawText(bitsize * 6, bitsize * 10, "2   2 PLAYER GAME");
	}
	if(moveselection != 1 || blink <= fps){
		esat::DrawText(bitsize * 6, bitsize * 12, "3   KEYBOARD");
	}
	if(moveselection != 2 || blink <= fps){
		esat::DrawText(bitsize * 6, bitsize * 14, "4   KEMPSTON JOYSTICK");
	}
	esat::DrawText(bitsize * 6, bitsize * 19,  "5   START GAME");
	esat::DrawText(0, bitsize * 23, "©1983 A.C.Q ALL RIGHTS RESERVED");
/*    SCORE                                                         		 SCORE*/
	WritteYellow();//Score
	esat::DrawText(bitsize, bitsize * 2,"000000      000000      000000");
/*    HIGHSCORE                                                      HIGHSCORE*/
	WritteBlue();//HighScore
	esat::DrawText(bitsize * 15, bitsize, "HI");


}

/*OPTION IF U SELECT JOYSTICK                      OPTION IF U SELECT JOYSTICK*/
void NotAvalible(){
	WritteWhite();
	esat::DrawText(0, bitsize * 11, "	   JOYSTICK IS NOT AVAILIBLE   ");
	esat::DrawText(0, bitsize * 13, "      PRESS SPACE TO RETURN     ");
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
		gamestate = 0;
		moveselection = 1;
	}
}

void ScoreInGame(){

	score_1 = (players+0)->score;
	score_2 = (players+1)->score;
	itoa((players+0)->lives, player_1_lives, 10);
	itoa((players+1)->lives, player_2_lives, 10);

	if(score_1 > score_2) {
		score_hi = score_1;
	} else {
		score_hi = score_2;
	}

	DrawMask();
	esat::DrawSolidPath(l_1, 5);

	if(playerselection == 2){
		DrawMask();
		esat::DrawSolidPath(l_2, 5);
		esat::DrawText(bitsize * 20, bitsize, player_2_lives);
		esat::DrawSprite(life_icon_sprite, bitsize * 21, 3);
	}

	TextSpectrum();
	WritteWhite();
	esat::DrawText(bitsize * 2, bitsize, "1UP                      2UP");
	esat::DrawText(bitsize * 8, bitsize, player_1_lives);
	esat::DrawSprite(life_icon_sprite, bitsize * 9, 3);



	WritteBlue();//HighScore
	esat::DrawText(bitsize * 15, bitsize, "HI");
	WritteYellow();
	itoa(score_1,score_player1,10);
	itoa(score_hi, hi_score,10);
	itoa(score_2,score_player2,10);
/*    FIRST PLAYER SCORE                                    FIRST PLAYER SCORE*/
	if(score_1 < 10){
		esat::DrawText(bitsize, bitsize * 2, "00000");
		esat::DrawText(bitsize * 6, bitsize * 2,score_player1);
	}
	if(score_1 < 100 && score_1 >= 10){
		esat::DrawText(bitsize, bitsize * 2, "0000");
		esat::DrawText(bitsize * 5, bitsize * 2,score_player1);
	}
	if(score_1 < 1000 && score_1 >= 100){
		esat::DrawText(bitsize, bitsize * 2, "000");
		esat::DrawText(bitsize * 4, bitsize * 2,score_player1);
	}
	if(score_1 < 10000 && score_1 >= 1000){
		esat::DrawText(bitsize, bitsize * 2, "00");
		esat::DrawText(bitsize * 3, bitsize * 2,score_player1);
	}
	if(score_1 < 100000 && score_1 >= 10000){
		esat::DrawText(bitsize, bitsize * 2, "0");
		esat::DrawText(bitsize * 2, bitsize * 2,score_player1);
	}
	if(score_1 < 1000000 && score_1 >= 100000){
		esat::DrawText(bitsize, bitsize * 2,score_player1);
	}
/*    HI-SCORE                                                        HI-SCORE*/
	if(score_hi < 10){
		esat::DrawText(bitsize * 13, bitsize * 2, "00000");
		esat::DrawText(bitsize * 18, bitsize * 2,hi_score);
	}
	if(score_hi < 100 && score_hi >= 10){
		esat::DrawText(bitsize * 13, bitsize * 2, "0000");
		esat::DrawText(bitsize * 17, bitsize * 2,hi_score);
	}
	if(score_hi < 1000 && score_hi >= 100){
		esat::DrawText(bitsize * 13, bitsize * 2, "000");
		esat::DrawText(bitsize * 16, bitsize * 2,hi_score);
	}
	if(score_hi < 10000 && score_hi >= 1000){
		esat::DrawText(bitsize * 13, bitsize * 2, "00");
		esat::DrawText(bitsize * 15, bitsize * 2,hi_score);
	}
	if(score_hi < 100000 && score_hi >= 10000){
		esat::DrawText(bitsize * 13, bitsize * 2, "0");
		esat::DrawText(bitsize * 14, bitsize * 2,hi_score);
	}
	if(score_hi < 1000000 && score_hi >= 100000){
		esat::DrawText(bitsize * 13, bitsize * 2,hi_score);
	}
/*    SECOND PLAYER SCORE                                  SECOND PLAYER SCORE*/
	if(score_2 < 10){
		esat::DrawText(bitsize * 25, bitsize * 2, "00000");
		esat::DrawText(bitsize * 30, bitsize * 2,score_player2);
	}
	if(score_2 < 100 && score_2 >= 10){
		esat::DrawText(bitsize * 25, bitsize * 2, "0000");
		esat::DrawText(bitsize * 29, bitsize * 2,score_player2);
	}
	if(score_2 < 1000 && score_2 >= 100){
		esat::DrawText(bitsize * 25, bitsize * 2, "000");
		esat::DrawText(bitsize * 28, bitsize * 2,score_player2);
	}
	if(score_2 < 10000 && score_2 >= 1000){
		esat::DrawText(bitsize * 25, bitsize * 2, "00");
		esat::DrawText(bitsize * 27, bitsize * 2,score_player2);
	}
	if(score_2 < 100000 && score_2 >= 10000){
		esat::DrawText(bitsize * 25, bitsize * 2, "0");
		esat::DrawText(bitsize * 26, bitsize * 2,score_player2);
	}
	if(score_2 < 1000000 && score_2 >= 100000){
		esat::DrawText(bitsize * 25, bitsize * 2,score_player2);
	}
}

void ScreenType(){
	switch (gamestate) {
/*    MENU                                                                MENU*/
		case 0:
			Introduction();
			GameSelection();
		break;
/*    1 PLAYER                                                        1 PLAYER*/
		case 1:
		// Inputs();
    DetectPlayerShoot((players+g_current_player));
    MovePlayer((players+g_current_player));

    // Update();
		ScoreInGame();
    UpdatePlayerShoot((players+g_current_player));
    BorderPlayer((players+g_current_player));
    AppearPowerup();
    ColisionPowerUp();
    FullFuel();
    FillFuel();
    PlayerColisionWithPlatforms((players+g_current_player));
    MaskFollowPlayer();
    Enemies();
    DeathPlayer((players+g_current_player));

    Land();
    UpdateFuel();
    Lift_Off();
    Take_Pieces();
    Drop_Pieces();
    In_Position();
    PlayerEntered();

    // Draws();
    DrawSet(); //Pinta escenario y máscaras
    DrawSpriteShip();
    DrawPowerup();
    DrawPlayerShoot();
    DrawPlayer((players+g_current_player));

    SaveGameState();
    LoadSaveGame();
		break;
/*    2 PLAYER                                                        2 PLAYER*/
		case 2:
		// Inputs();
    DetectPlayerShoot((players+g_current_player));
    MovePlayer((players+g_current_player));

    // Update();
		ScoreInGame();
    UpdatePlayerShoot((players+g_current_player));
    BorderPlayer((players+g_current_player));
    AppearPowerup();
    ColisionPowerUp();
    FullFuel();
    FillFuel();
    PlayerColisionWithPlatforms((players+g_current_player));
    MaskFollowPlayer();
    Enemies();
    DeathPlayer((players+g_current_player));

    Land();
    UpdateFuel();
    Lift_Off();
    Take_Pieces();
    Drop_Pieces();
    In_Position();
    PlayerEntered();

    // Draws();
    DrawSet(); //Pinta escenario y máscaras
    DrawSpriteShip();
    DrawPowerup();
    DrawPlayerShoot();
    DrawPlayer((players+g_current_player));

    SaveGameState();
    LoadSaveGame();
		break;
/*    1 JOYSTICK PLAYER		                                   1 JOYSTICK PLAYER*/
		case -1:
			NotAvalible();
		break;
/* 		2 JOYSTICK PLAYER		                                   2 JOYSTICK PLAYER*/
		case -2:
			NotAvalible();
		break;
	}
}
