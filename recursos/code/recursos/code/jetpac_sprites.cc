
// General Spritesheet
esat::SpriteHandle spritesheet;

//Player Left Ground Sprites
esat::SpriteHandle player_left_ground_one_sprite, player_left_ground_two_sprite,
                   player_left_ground_three_sprite, player_left_ground_four_sprite;

//Player Right Ground Sprites
esat::SpriteHandle player_right_ground_one_sprite, player_right_ground_two_sprite,
                   player_right_ground_three_sprite, player_right_ground_four_sprite;

//Player Left Air Sprites
esat::SpriteHandle player_left_air_one_sprite, player_left_air_two_sprite,
                   player_left_air_three_sprite, player_left_air_four_sprite;

//Player Right Air Sprites
esat::SpriteHandle player_right_air_one_sprite, player_right_air_two_sprite,
                   player_right_air_three_sprite, player_right_air_four_sprite;

//Enemies Sprites
esat::SpriteHandle asteroid_left_sprite, asteroid_left_alt_sprite,
                   asteroid_right_sprite, asteroid_right_alt_sprite,
                   fluff_sprite, fluff_alt_sprite,
                   bubble_sprite, bubble_alt_sprite,
                   fighter_plane_right_sprite, fighter_plane_left_sprite,
                   ufo_sprite,
                   cross_sprite,
                   falcon_right_sprite, falcon_left_sprite,
                   pou_sprite;

//Ships sprites
esat::SpriteHandle first_ship_top_sprite, first_ship_mid_sprite, first_ship_bottom_sprite,
                   second_ship_top_sprite, second_ship_mid_sprite, second_ship_bottom_sprite,
                   third_ship_top_sprite, third_ship_mid_sprite, third_ship_bottom_sprite,
                   fourth_ship_top_srite, fourth_ship_mid_sprite, fourth_ship_bottom_sprite,
                   fire_one, fire_two;

//Explosion sprites
esat::SpriteHandle first_explosion_sprite,
                   second_explosion_sprite,
                   third_explosion_sprite;

//Life icon sprite
esat::SpriteHandle life_icon_sprite;

void LoadGeneralSprite() {
  spritesheet = esat::SpriteFromFile("recursos/sprites/jetpac_spritesheet.png");
}

void LoadPlayerSprites() {
  int x=69, y=102, width=42, height=66;
  player_left_ground_one_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=135;
  player_left_ground_two_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=207;
  player_left_ground_three_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=276;
  player_left_ground_four_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  *(ground_left+0) = player_left_ground_one_sprite;
  *(ground_left+1) = player_left_ground_two_sprite;
  *(ground_left+2) = player_left_ground_three_sprite;
  *(ground_left+3) = player_left_ground_four_sprite;

  x=75; y=195;
  player_right_ground_one_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=144;
  player_right_ground_two_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=213;
  player_right_ground_three_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=282;
  player_right_ground_four_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  *(ground_right+0) = player_right_ground_one_sprite;
  *(ground_right+1) = player_right_ground_one_sprite;
  *(ground_right+2) = player_right_ground_one_sprite;
  *(ground_right+3) = player_right_ground_one_sprite;

  x=576; y=102; width=48; height=72;
  player_left_air_one_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=651;
  player_left_air_two_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=723; y=99;
  player_left_air_three_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=795;
  player_left_air_four_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  *(air_left+0) = player_left_air_one_sprite;
  *(air_left+1) = player_left_air_one_sprite;
  *(air_left+2) = player_left_air_one_sprite;
  *(air_left+3) = player_left_air_one_sprite;

  x=576; y=186;
  player_right_air_one_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=648; y=189;
  player_right_air_two_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=723; y=186;
  player_right_air_three_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=795;
  player_right_air_four_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  *(air_right+0) = player_right_air_one_sprite;
  *(air_right+1) = player_right_air_one_sprite;
  *(air_right+2) = player_right_air_one_sprite;
  *(air_right+3) = player_right_air_one_sprite;

}

void LoadEnemiesSprites() {
  int x=743, y=265, width=50, height=50;
  asteroid_left_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=815;
  asteroid_left_alt_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=743; y=320;
  asteroid_right_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=815;
  asteroid_right_alt_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=746; y=375;
  fluff_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=818;
  fluff_alt_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=746; y=437;
  bubble_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=818;
  bubble_alt_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=746; y=500;
  fighter_plane_right_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=818;
  fighter_plane_left_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=746; y=550;
  ufo_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  y=610;
  cross_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  y=668;
  falcon_right_sprite = esat::SubSprite(spritesheet, x, y, width, height); x=818;
  falcon_left_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=746; y=735;
  pou_sprite = esat::SubSprite(spritesheet, x, y, width, height);
}

void LoadShipsSprites() {
  int x=240, y=423, width=48, height=48;
  first_ship_top_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=489;
  first_ship_mid_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=558;
  first_ship_bottom_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=333; y=423;
  second_ship_top_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=492;
  second_ship_mid_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=558;
  second_ship_bottom_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=462; y=423;
  third_ship_top_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=492;
  third_ship_mid_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=561;
  third_ship_bottom_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=588; y=423;
  fourth_ship_top_srite = esat::SubSprite(spritesheet, x, y, width, height); y=492;
  fourth_ship_mid_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=558;
  fourth_ship_bottom_sprite = esat::SubSprite(spritesheet, x, y, width, height);

  x=351; y=639;
  fire_one = esat::SubSprite(spritesheet, x, y, width, height); x=441;
  fire_two = esat::SubSprite(spritesheet, x, y, width, height);
}

void LoadPowerUpsSprites(){
  	*(powerup.sprite+0) = esat::SubSprite(spritesheet, 67, 384, 46, 36);
  	*(powerup.sprite+1) = esat::SubSprite(spritesheet, 63, 450, 48, 27);
  	*(powerup.sprite+2) = esat::SubSprite(spritesheet, 63, 507, 48, 24);
  	*(powerup.sprite+3) = esat::SubSprite(spritesheet, 63, 567, 45, 39);
  	*(powerup.sprite+4) = esat::SubSprite(spritesheet, 63, 639, 45, 33);
  	*(powerup.sprite+5) = esat::SubSprite(spritesheet, 69, 321, 49, 33); //fuel
}

void LoadExplosionSprites() {
  int x=414, y=219, width=72, height=48;
  first_explosion_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=165;
  second_explosion_sprite = esat::SubSprite(spritesheet, x, y, width, height); y=102;
  third_explosion_sprite = esat::SubSprite(spritesheet, x, y, width, height);
  *(explosion+0) = first_explosion_sprite;
  *(explosion+1) = second_explosion_sprite;
  *(explosion+2) = third_explosion_sprite;
}

void LoadLifeIconSprite() {
  int x=441, y=48, width=18, height=24;
  life_icon_sprite = esat::SubSprite(spritesheet, x, y, width, height);
}

void LoadSprites() {
  LoadGeneralSprite();
  LoadPlayerSprites();
  LoadEnemiesSprites();
  LoadShipsSprites();
  LoadPowerUpsSprites();
  LoadExplosionSprites();
  LoadLifeIconSprite();
}

void ReleaseGeneralSprite() {
  esat::SpriteRelease(spritesheet);
}

void ReleasePlayerSprites() {
  esat::SpriteRelease(player_left_ground_one_sprite);
  esat::SpriteRelease(player_left_ground_two_sprite);
  esat::SpriteRelease(player_left_ground_three_sprite);
  esat::SpriteRelease(player_left_ground_four_sprite);

  esat::SpriteRelease(player_right_ground_one_sprite);
  esat::SpriteRelease(player_right_ground_two_sprite);
  esat::SpriteRelease(player_right_ground_three_sprite);
  esat::SpriteRelease(player_right_ground_four_sprite);

  esat::SpriteRelease(player_left_air_one_sprite);
  esat::SpriteRelease(player_left_air_two_sprite);
  esat::SpriteRelease(player_left_air_three_sprite);
  esat::SpriteRelease(player_left_air_four_sprite);

  esat::SpriteRelease(player_right_air_one_sprite);
  esat::SpriteRelease(player_right_air_two_sprite);
  esat::SpriteRelease(player_right_air_three_sprite);
  esat::SpriteRelease(player_right_air_four_sprite);
}

void ReleaseEnemiesSprites() {
  esat::SpriteRelease(asteroid_left_sprite);
  esat::SpriteRelease(asteroid_left_alt_sprite);
  esat::SpriteRelease(asteroid_right_sprite);
  esat::SpriteRelease(asteroid_right_alt_sprite);
  esat::SpriteRelease(fluff_sprite);
  esat::SpriteRelease(fluff_alt_sprite);
  esat::SpriteRelease(bubble_sprite);
  esat::SpriteRelease(bubble_alt_sprite);
  esat::SpriteRelease(fighter_plane_left_sprite);
  esat::SpriteRelease(fighter_plane_right_sprite);
  esat::SpriteRelease(ufo_sprite);
  esat::SpriteRelease(cross_sprite);
  esat::SpriteRelease(falcon_left_sprite);
  esat::SpriteRelease(falcon_right_sprite);
  esat::SpriteRelease(pou_sprite);
}

void ReleaseShipsSprites() {
  esat::SpriteRelease(first_ship_top_sprite);
  esat::SpriteRelease(first_ship_mid_sprite);
  esat::SpriteRelease(first_ship_bottom_sprite);
  esat::SpriteRelease(second_ship_top_sprite);
  esat::SpriteRelease(second_ship_mid_sprite);
  esat::SpriteRelease(second_ship_bottom_sprite);
  esat::SpriteRelease(third_ship_top_sprite);
  esat::SpriteRelease(third_ship_mid_sprite);
  esat::SpriteRelease(third_ship_bottom_sprite);
  esat::SpriteRelease(fourth_ship_top_srite);
  esat::SpriteRelease(fourth_ship_mid_sprite);
  esat::SpriteRelease(fourth_ship_bottom_sprite);
  esat::SpriteRelease(fire_one);
  esat::SpriteRelease(fire_two);
}

void ReleasePowerUpsSprites(){
  for(int i=0;i<5;i++) {
  	esat::SpriteRelease(*(powerup.sprite+i));
  }
}

void ReleaseExplosionSprites() {
  esat::SpriteRelease(first_explosion_sprite);
  esat::SpriteRelease(second_explosion_sprite);
  esat::SpriteRelease(third_explosion_sprite);
}

void ReleaseLifeIconSprite() {
  esat::SpriteRelease(life_icon_sprite);
}

void ReleaseSprites() {
  ReleaseGeneralSprite();
  ReleasePlayerSprites();
  ReleaseEnemiesSprites();
  ReleaseShipsSprites();
  ReleasePowerUpsSprites();
  ReleaseExplosionSprites();
  ReleaseLifeIconSprite();
}
