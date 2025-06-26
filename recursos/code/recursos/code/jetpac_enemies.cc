
#include "jetpac_enemies_list.cc"

void EnemyTypeAndPoints(TEnemy *enemy){
  switch(g_level){
    case 1: case 9:  enemy->type=1; enemy->points=25; break;
    case 2: case 10: enemy->type=2; enemy->points=80; break;
    case 3: case 11: enemy->type=3; enemy->points=40; break;
    case 4: case 12: enemy->type=4; enemy->points=55; break;
    case 5: case 13: enemy->type=5; enemy->points=50; break;
    case 6: case 14: enemy->type=6; enemy->points=60; break;
    case 7: case 15: enemy->type=7; enemy->points=25; break;
    case 8: case 16: enemy->type=8; enemy->points=50; break;
  }
}

TColor SelectColor(){
  int selector=rand()%4;
  TColor c;
  switch (selector){
    case 0: c.r=0;   c.g=255; c.b=0;   break;
    case 1: c.r=255; c.g=0;   c.b=0;   break;
    case 2: c.r=255; c.g=0;   c.b=255; break;
    case 3: c.r=0;   c.g=255; c.b=255; break;
  }
  return c;
}

void InitEnemy(TEnemy *enemy) {
  enemy->pos.x=-50;
  enemy->pos.y=rand()%((KWindowHeight-250)+100);
  EnemyTypeAndPoints(enemy);
  enemy->alive=true;
  enemy->color=SelectColor();
  enemy->hori=rand()%2;
  enemy->vert=rand()%3;
  enemy->death_counter=0;
}

void GenerateEnemies(){
  if(g_num_enemies < 5*(1+g_difficulty) && (g_frame_count%(fps))==0){
    TEnemy enemy;
    InitEnemy(&enemy);
    InsertEnemy(&enemies_list, enemy);
  }
  g_frame_count++;
}

void EnemyMov(TEnemy *enemy){
  switch(enemy->hori){
    case 0: enemy->pos.x-=g_enemies_speed; break;
    case 1: enemy->pos.x+=g_enemies_speed; break;
  }
  switch(enemy->type) {
    case 1: case 4: case 7:
      switch(enemy->vert){
        case 1: enemy->pos.y+=0.5f;break;
        case 2: enemy->pos.y-=0.5f;break;
      }
    break;
    case 2: case 3: case 6: case 5: case 8:
      switch(enemy->vert){
        case 1: enemy->pos.y+=g_enemies_speed;break;
        case 2: enemy->pos.y-=g_enemies_speed;break;
      }
    break;
  }
}

void EnemyBorderControl(TEnemy *enemy){
  if(enemy->pos.x < -70) {
    enemy->pos.x=KWindowWidth;
  }else if(enemy->pos.x > KWindowWidth + 50){
    enemy->pos.x = 0;
  }else if(enemy->pos.x < -5 && enemy->pos.x>=-30){
    enemy->pos.x = KWindowWidth;
  }
}

bool Collide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
  if(x1>=x2 && x1<=(x2+w2) && y1>=y2 && y1<=(y2+h2)) return true;
  if((x1+w1)>=x2 && (x1+w1)<=(x2+w2) && y1>=y2 && y1<=(y2+h2)) return true;
  if((x1+w1)>=x2 && (x1+w1)<=(x2+w2) && (y1+h1)>=y2 && (y1+h1)<=(y2+h2)) return true;
  if(x1>=x2 && x1<=(x2+w2) && (y1+h1)>=y2 && (y1+h1)<=(y2+h2)) return true;
  return false;
}

void EnemyBulletCollision(TEnemy *enemy, PlayerShoot *bullets, Player *player) {

  for(int i=0; i < player->count_shoots; ++i) {
    switch((*(bullets+i)).direction){
      case 0:
      if(enemy->alive && (*(bullets+i)).shooting &&
        (Collide((*(bullets+i)).px2, (*(bullets+i)).py, (*(bullets+i)).width, 5, enemy->pos.x, enemy->pos.y, 50, 50 )) ||
        (Collide((*(bullets+i)).second_px2, (*(bullets+i)).py, (*(bullets+i)).width, 5, enemy->pos.x, enemy->pos.y, 50, 50 ))) {
        enemy->alive=false;
        player->score += enemy->points;
      }
      break;

      case 1:
      if(enemy->alive && (*(bullets+i)).shooting &&
        (Collide((*(bullets+i)).px, (*(bullets+i)).py, (*(bullets+i)).width, 5, enemy->pos.x, enemy->pos.y, 50, 50 )) ||
        (Collide((*(bullets+i)).second_px, (*(bullets+i)).py, (*(bullets+i)).width, 5, enemy->pos.x, enemy->pos.y, 50, 50 ))) {
        enemy->alive=false;
        player->score += enemy->points;
      }
      break;
    }
  }
}

void EnemyPlayerCollision(TEnemy enemy, Player *player){
  if(enemy.alive && player->alive && Collide(enemy.pos.x, enemy.pos.y, 50, 50,
     player->px, player->py, player->px2-player->px, player->py2-player->py)) {
        SetAllEnemiesDead(&enemies_list);
        enemy.alive=false;
        player->alive=false;
        player->lives--;
        // Cambia de jugador cada vez que uno muere
        if(gamestate == 1 && (player+0)->lives < 0){
          gamestate = 0;
          InitializePlayer();
          ship.level = 1;
        }
        if(gamestate == 2) {
          if(g_current_player == 0 && (player+1)->lives > 0){
            g_current_player = 1;
          } else if(g_current_player == 1 && (player+0)->lives > 0){
            g_current_player = 0;
          } else {
            gamestate = 0;
            InitializePlayer();
            ship.level = 1;
          }
        }
  }
}

bool ColisionWithPlatform(TEnemy enemy, TPlatform platf) {
  return Collide(enemy.pos.x, enemy.pos.y, 50, 50,
                (float) platf.px, (float) platf.py,
                (float) (platf.px2-platf.px), (float) (platf.py2-platf.py));
}

int SideColisionWithPlatform(TEnemy enemy, TPlatform platf){
  if(ColisionWithPlatform(enemy, platf)){
    if(enemy.pos.x + 45 < platf.px && (enemy.pos.y < platf.py2 || enemy.pos.y + 50 > platf.py)) {return 1;}
    if(enemy.pos.x + 5 > platf.px2 && (enemy.pos.y < platf.py2 || enemy.pos.y + 50 > platf.py)) {return 2;}
    if(enemy.pos.y + 45 < platf.py && (enemy.pos.x < platf.px2 || enemy.pos.x + 50 > platf.px))  {return 3;}
    if(enemy.pos.y + 5 > platf.py2 && (enemy.pos.x < platf.px2 || enemy.pos.x + 50 > platf.px)) {return 4;}
    }
  return 0;
}

bool ScreenBorderColision(TEnemy enemy){
  return (enemy.pos.y<=72 || enemy.pos.y+50>=552);
}

void EnemyExploding(TEnemy *enemy){
  for(int i=0;i<3;++i){
    if(ColisionWithPlatform(*enemy,*(platform+i)) || ScreenBorderColision(*enemy)){
      enemy->alive=false;
    }
  }
}

void EnemyBouncing(TEnemy *enemy){
    for(int i=0;i<3;++i){
      switch(SideColisionWithPlatform(*enemy,*(platform+i))) { //Rebotan
        case 1: enemy->hori=0; break;
        case 2: enemy->hori=1; break;
        case 3: enemy->vert=2; break;
        case 4: enemy->vert=1; break;
      }
    }
  if(ScreenBorderColision(*enemy) && enemy->pos.y<75){
    enemy->vert=1;
  }else if(ScreenBorderColision(*enemy) && enemy->pos.y>500){
    enemy->vert=2;
  }
}

void EnemyFollowing(TEnemy *enemy, Player player) {
  if(enemy->type != 4) {
    if(enemy->pos.x<player.px){
      enemy->hori=1;
    }else if(enemy->pos.x>player.px){
      enemy->hori=0;
    }
  }
  if(enemy->pos.y<player.py){
    enemy->vert=1;
  }else if(enemy->pos.y>player.py){
    enemy->vert=2;
  }else if(enemy->pos.y==player.py){
    enemy->vert=0;
  }
}

void EnemyBehaviour(TEnemy *enemy, Player player){
  switch (enemy->type) {
    case 1:case 7: //meteoritos y falcon
      EnemyExploding(enemy);
    break;
    case 2:case 3:case 6: //Pelusas, Burbujas y Pads
      EnemyBouncing(enemy);
    break;
    case 4: //Caza
      EnemyExploding(enemy);
      EnemyFollowing(enemy, player);
    break;
    case 5:case 8: //ufo y pou
      EnemyFollowing(enemy, player);
    break;
  }
}

void EnemyDeathAnimation(TEnemy *enemy){
  if(!enemy->alive && enemy->death_counter<11){
    enemy->death_counter++;
  }
  if(!enemy->alive && enemy->death_counter<4){
    esat::DrawSprite(first_explosion_sprite,enemy->pos.x,enemy->pos.y);
  }
  if(!enemy->alive && enemy->death_counter>3 && enemy->death_counter<8){
    esat::DrawSprite(second_explosion_sprite,enemy->pos.x,enemy->pos.y);
  }
  if(!enemy->alive && enemy->death_counter>7 && enemy->death_counter<11){
    esat::DrawSprite(third_explosion_sprite,enemy->pos.x,enemy->pos.y);
  }
}

void DrawEnemyPlatforms(){
  float *p1 = (float*)malloc(10*sizeof(float)),
        *p2 = (float*)malloc(10*sizeof(float)),
        *p3 = (float*)malloc(10*sizeof(float));

  *(p1+0)=(platform+0)->px; *(p1+1)=(platform+0)->py;
  *(p1+2)=(platform+0)->px2; *(p1+3)=(platform+0)->py;
  *(p1+4)=(platform+0)->px2; *(p1+5)=(platform+0)->py2;
  *(p1+6)=(platform+0)->px; *(p1+7)=(platform+0)->py2;
  *(p1+8)=(platform+0)->px; *(p1+9)=(platform+0)->py;
  esat::DrawSetFillColor(0,200,0);
  esat::DrawSolidPath(p1, 5);
  free(p1);

  *(p2+0)=(platform+1)->px; *(p2+1)=(platform+1)->py;
  *(p2+2)=(platform+1)->px2; *(p2+3)=(platform+1)->py;
  *(p2+4)=(platform+1)->px2; *(p2+5)=(platform+1)->py2;
  *(p2+6)=(platform+1)->px; *(p2+7)=(platform+1)->py2;
  *(p2+8)=(platform+1)->px; *(p2+9)=(platform+1)->py;
  esat::DrawSetFillColor(0,200,0);
  esat::DrawSolidPath(p2, 5);
  free(p2);

  *(p3+0)=(platform+2)->px; *(p3+1)=(platform+2)->py;
  *(p3+2)=(platform+2)->px2; *(p3+3)=(platform+2)->py;
  *(p3+4)=(platform+2)->px2; *(p3+5)=(platform+2)->py2;
  *(p3+6)=(platform+2)->px; *(p3+7)=(platform+2)->py2;
  *(p3+8)=(platform+2)->px; *(p3+9)=(platform+2)->py;
  esat::DrawSetFillColor(0,200,0);
  esat::DrawSolidPath(p3, 5);
  free(p3);
}

void DrawEnemyBackground(TEnemy enemy) {
  float *vertex = (float*) malloc(10*sizeof(float));
  *(vertex + 0) = enemy.pos.x; *(vertex + 1) = enemy.pos.y;
  *(vertex + 2) = enemy.pos.x+50; *(vertex + 3) = enemy.pos.y;
  *(vertex + 4) = enemy.pos.x+50; *(vertex + 5) = enemy.pos.y+50;
  *(vertex + 6) = enemy.pos.x; *(vertex + 7) = enemy.pos.y+50;
  *(vertex + 8) = enemy.pos.x; *(vertex + 9) = enemy.pos.y;
  esat::DrawSetFillColor(enemy.color.r, enemy.color.g, enemy.color.b);
  esat::DrawSetStrokeColor(0,0,0);
  esat::DrawSolidPath(vertex, 5);
  free(vertex);
}

void DrawEnemy(TEnemy *enemy){
  bool animation_frames=(g_enemy_animation_index/fps)%2==0;  //variable that divides by number an amount of frames that represents a part of una fps so that the animation can change.
   if(enemy->alive){
     DrawEnemyBackground(*enemy);
     switch (enemy->type) {
       case 1:  if(animation_frames) {
                  if(enemy->hori == 0) {
                    esat::DrawSprite(asteroid_left_sprite, enemy->pos.x, enemy->pos.y);
                  } else if (enemy->hori == 1) {
                    esat::DrawSprite(asteroid_right_sprite, enemy->pos.x, enemy->pos.y);
                  }
                } else if(!animation_frames) {
                  if(enemy->hori == 0) {
                    esat::DrawSprite(asteroid_left_alt_sprite,enemy->pos.x,enemy->pos.y);
                  } else if(enemy->hori == 1) {
                    esat::DrawSprite(asteroid_right_alt_sprite,enemy->pos.x,enemy->pos.y);
                  }
                } break;
       case 2:  if(animation_frames){
                  esat::DrawSprite(fluff_sprite,enemy->pos.x,enemy->pos.y);
                } else if(!animation_frames){
                  esat::DrawSprite(fluff_alt_sprite,enemy->pos.x,enemy->pos.y);
                } break;
       case 3:  if(animation_frames){
                  esat::DrawSprite(bubble_sprite,enemy->pos.x,enemy->pos.y);
                } else if(!animation_frames){
                  esat::DrawSprite(bubble_alt_sprite,enemy->pos.x,enemy->pos.y);
                } break;
       case 4:
                if(enemy->hori == 0) {
                  esat::DrawSprite(fighter_plane_left_sprite,enemy->pos.x,enemy->pos.y);
                } else if(enemy->hori == 1) {
                  esat::DrawSprite(fighter_plane_right_sprite,enemy->pos.x,enemy->pos.y);
                }
                break;
       case 5:  esat::DrawSprite(ufo_sprite,enemy->pos.x,enemy->pos.y); break;
       case 6:  esat::DrawSprite(cross_sprite,enemy->pos.x,enemy->pos.y); break;
       case 7:
                if(enemy->hori == 0) {
                  esat::DrawSprite(falcon_left_sprite,enemy->pos.x,enemy->pos.y); break;
                } else if(enemy->hori == 1) {
                  esat::DrawSprite(falcon_right_sprite,enemy->pos.x,enemy->pos.y); break;
                }
                break;
       case 8:  esat::DrawSprite(pou_sprite,enemy->pos.x,enemy->pos.y); break;
     }
   }else if(!enemy->alive){
     EnemyDeathAnimation(enemy);
   }
   g_enemy_animation_index++;
}

void Enemies(){
  GenerateEnemies();
  TNode *enemy_node;
  for(enemy_node=enemies_list;enemy_node!=nullptr;enemy_node=enemy_node->next){
    if(enemy_node->enemy.alive){
      EnemyMov(&enemy_node->enemy);
      EnemyBehaviour(&enemy_node->enemy, (*(players+g_current_player)));
      EnemyBorderControl(&enemy_node->enemy);
      EnemyPlayerCollision(enemy_node->enemy, (players+g_current_player));
      EnemyBulletCollision(&enemy_node->enemy, player_shoots, (players+g_current_player));
    }
    DrawEnemy(&enemy_node->enemy);
  }
  DeleteDeathEnemiesFromList(&enemies_list);
}
