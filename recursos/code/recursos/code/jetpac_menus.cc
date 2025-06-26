

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

void GameSelection(){

float *p = NULL;

p = (float*) malloc ( 10 * sizeof (float));

	*(p+0) =
	*(p+1) =
	*(p+3) =
	*(p+5) =
	*(p+6) =
	*(p+8) = *(p+0);
  *(p+9) = *(p+1);


/*		1																																			 1*/
	if(esat::IsKeyDown('1') && playerselection != 1){
		playerselection = 1;
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 8, "1   1 PLAYER GAME");
		if(blink >= fps){
			esat::DrawSetFillColor(255, 255, 255);
			//esat::DrawSolidPath();
		}
	}
/*		2																																			 2*/
	if(esat::IsKeyDown('2') && playerselection != 2){
		playerselection = 2;
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 10, "2   2 PLAYER GAME");
		if(blink >= fps){
			esat::DrawSetFillColor(255, 255, 255);
			// esat::DrawSolidPath();
		}
	}
/*		3																																		 	 3*/
	if(esat::IsKeyDown('3') && moveselection != 1){
		moveselection = 1;
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 12, "1   1 PLAYER GAME");
		if(blink >= fps){
			esat::DrawSetFillColor(255, 255, 255);
			// esat::DrawSolidPath();
		}
	}
/*		4																																			 4*/
	if(esat::IsKeyDown('4') && moveselection != 2){
		moveselection = 2;
		WritteBlack();
		esat::DrawText(bitsize * 6, bitsize * 14, "2   2 PLAYER GAME");
		if(blink >= fps){
			esat::DrawSetFillColor(255, 255, 255);
			// esat::DrawSolidPath();
		}
	}
/*       START                                                           START*/
	if(esat::IsKeyDown('5') && playerselection == 1 && gamestate == 0){
		gamestate++;
		//1 JUGADOR
	}
	if(esat::IsKeyDown('5') && playerselection == 2 && gamestate == 0){
		gamestate++;
		//2 JUGADORES
	}
	printf("%d\n", blink);
	if(blink >= fps * 2){
		blink = 0;
	}
	blink++;
}

void Introduction(){

	TextSpectrum();
	WritteWhite();

	esat::DrawText(bitsize * 2, bitsize, "1UP                      2UP");
	esat::DrawText(bitsize * 6, bitsize * 5, "JETPAX GAME SELECTION");
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

	WritteYellow();//Score
	esat::DrawText(bitsize, bitsize * 2,"000000      000000      000000");

	WritteBlue();//HighScore
	esat::DrawText(bitsize * 15, bitsize, "HI");


}

Introduction();
GameSelection();
