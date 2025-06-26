#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <time.h>

#include <stdlib.h>
#include <stdio.h>

#include "recursos/code/jetpac_structs.cc"
#include "recursos/code/jetpac_global_vars.cc"
#include "recursos/code/jetpac_aux_functions.cc"
#include "recursos/code/jetpac_sprites.cc"
#include "recursos/code/jetpac_player.cc"
#include "recursos/code/jetpac_player_shoot.cc"
#include "recursos/code/jetpac_enemies.cc"
#include "recursos/code/jetpac_scenary.cc"
#include "recursos/code/jetpac_powerups.cc"
#include "recursos/code/jetpac_interface.cc"

int esat::main(int argc, char **argv) {

  esat::WindowInit(KWindowWidth,KWindowHeight);
  WindowSetMouseVisibility(true);
  srand(time(NULL));

  // Inits();
  LoadSprites();
  InitPlatform();
  InitializePlayer();
  InitializeShoot();
	SetSet();
  SetShip();

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);

    ScreenType();


    esat::DrawEnd();

    do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);


    esat::WindowFrame();
  }

  ReleaseSprites();
  FreePuntero();
  esat::WindowDestroy();
  return 0;
}
