



unsigned char fps=25;                                                           //A constant related to FPS control.
double current_time,last_time;

//
// Luismi / Ignacio Sempere
//

const int KWindowWidth=768, KWindowHeight=576, KEnemySpeed=10;

int g_level=1, g_num_enemies=0, g_frame_count=0, g_enemies_speed=5,score_p1=0,
    score_p2=0, g_enemy_animation_index=0, g_difficulty=0, g_current_player=0;

TEnemyNode *enemies_list=nullptr;

TSave_Game SaveGame;
FILE  *SaveGameFile;

esat::SpriteHandle *ground_left  = (esat::SpriteHandle*) malloc(4 * sizeof(esat::SpriteHandle));
esat::SpriteHandle *ground_right = (esat::SpriteHandle*) malloc(4 * sizeof(esat::SpriteHandle));
esat::SpriteHandle *air_left     = (esat::SpriteHandle*) malloc(4 * sizeof(esat::SpriteHandle));
esat::SpriteHandle *air_right    = (esat::SpriteHandle*) malloc(4 * sizeof(esat::SpriteHandle));
esat::SpriteHandle *explosion    = (esat::SpriteHandle*) malloc(3 * sizeof(esat::SpriteHandle));


//
// Raul
//

//Player_shot
const int g_maxshoots=10;

PlayerShoot *player_shoots=(PlayerShoot*)malloc(g_maxshoots*sizeof(PlayerShoot));
Player *players = (Player*)malloc(2*sizeof(Player));  //Luismi
TPlatform *platform = (TPlatform*) malloc(3*sizeof(TPlatform));
Powerup powerup;


//
// Nacho Fabra
//

  //Menu
TMask playermask, movementmask;
int redimension = 3; // variable reescalable
int bitsize = 8 * redimension; // variable reescalable
int moveselection = 1, playerselection = 1;
int gamestate = 0; //estado del juego
int blink;

float *p = NULL;
float *m = NULL;

int score_1 = 0, score_2 = 1, score_hi = 0; //puntuacion
char *score_player1 = (char*) malloc(6*sizeof(char)); //puntero de puntuacion para la visualicación del juador
char *score_player2 = (char*) malloc(6*sizeof(char));//puntero de puntuacion para la visualicación del juador
char *hi_score = (char*) malloc(6*sizeof(char));//puntero de la mayor puntuacion para la visualicación del juador
char *player_1_lives = (char*) malloc(sizeof(char));
char *player_2_lives = (char*) malloc(sizeof(char));

TMask livesmask_1, livesmask_2;
float *l_1 = NULL;
float *l_2 = NULL;


//
//Ivan
//

int totalItems;
TFigures r;
TFigures *BlockFigures;
TShip ship;
