

//LuisMI / Xispa

  //Enemies

struct TVec2{
  float x,y;
};

struct TColor{
  unsigned char r,g,b,a=255;
};

struct TEnemy{
  TVec2 pos;
  int type, points;
  bool alive;
  TColor color;
  int hori, vert;
  int death_counter;
};

struct TBullet{
  TVec2 pos;
  bool alive;
};

struct TEnemyNode{
  TEnemy enemy;
  TEnemyNode *next;
};

// Raul

  //Platforms
struct TPlatform{
	int px,py,px2,py2;
};

struct Player{
	int px, py, px2, py2;
  int vel_x, vel_y;
  int direction, animation, explosion_timer, count_shoots, death_timer;
  int lives, score;
  bool in_ground, in_air, exploding, is_playing, alive;
};

  //PlayerShoot

struct PlayerShoot{
  int px, aux_px, py, px2, second_px, second_px2, max_width, direction, speed, width, second_width;
  bool shooting, border;
  TColor color;
};

struct Powerup{
	int px,py,px2,py2, appearance, platform, animation;
	esat::SpriteHandle *sprite = (esat::SpriteHandle*) malloc(5*sizeof(esat::SpriteHandle));
	bool alive, carry, destination, fuel, air;
};




//
// Nacho
//

struct TMask{
	esat::Vec2 pos;
	int textsize;
};


//
// Ivan
//

struct TCoordinates{
 float x, y;
};

struct TShip{

  int px = 24*22;
  int py = 353;
  int level = 1;
  int fill = 0;
  int px_disassembled_2 = 24*7;
  int py_disassembled_2 =24*10-49;
  int px_disassembled_1 = 24*17;
  int py_disassembled_1 = 24*13-49;
  int time;
  bool in_position = true;
  int sprite;
  bool second_part = false;
  bool taked = false;
  bool taked2 = false;
  bool stop = false;
  bool first_part = false;
  bool player_in = false;
  esat::SpriteHandle *sprites_ship_head = (esat::SpriteHandle*) malloc(4*sizeof(esat::SpriteHandle));
  esat::SpriteHandle *sprites_ship_body = (esat::SpriteHandle*) malloc(4*sizeof(esat::SpriteHandle));
  esat::SpriteHandle *sprites_ship_propeller = (esat::SpriteHandle*) malloc(4*sizeof(esat::SpriteHandle));
  esat::SpriteHandle *sprites_combustion = (esat::SpriteHandle*) malloc(2*sizeof(esat::SpriteHandle));
};

struct TFigures{
  int points;
  TCoordinates position;
  TColor colour;
  int i;
  int dimensionX,dimensionY;
  esat::SpriteHandle *platform = (esat::SpriteHandle*) malloc(3*sizeof(esat::SpriteHandle));

  int size = 24;
};



// LuisMi 
struct TSave_Game{
  Player *players;
  PlayerShoot *bullets;
  int g_level;
  int g_difficulty;
  int gamestate;
  int g_current_player;
  TShip nave;
};
