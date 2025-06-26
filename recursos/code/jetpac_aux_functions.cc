

TSave_Game SaveGameDataCollect(TSave_Game	*current_game, Player	*players_ptr,
															 TShip nave, PlayerShoot* bullets) {

	TSave_Game *saving_game = current_game;
	saving_game->players=(Player*)malloc(2*sizeof(Player));
	for(int i=0;i<2;++i){
		(saving_game->players+i)->px         =  (*(players_ptr+i)).px;
		(saving_game->players+i)->py				 =	(*(players_ptr+i)).py;
		(saving_game->players+i)->px2				 =	(*(players_ptr+i)).px2;
		(saving_game->players+i)->py2				 =	(*(players_ptr+i)).py2;
		(saving_game->players+i)->vel_x			 =	(*(players_ptr+i)).vel_x;
		(saving_game->players+i)->vel_y			 =	(*(players_ptr+i)).vel_y;
		(saving_game->players+i)->lives			 =	(*(players_ptr+i)).lives;
		(saving_game->players+i)->in_ground	 =	(*(players_ptr+i)).in_ground;
		(saving_game->players+i)->in_air		 =	(*(players_ptr+i)).in_air;
		(saving_game->players+i)->is_playing =	(*(players_ptr+i)).is_playing;
		(saving_game->players+i)->alive			 =	(*(players_ptr+i)).alive;
	}

	saving_game->bullets	=	bullets;

	saving_game->g_level					=	g_level;
	saving_game->g_difficulty			=	g_difficulty;
	saving_game->gamestate				=	gamestate;
	saving_game->g_current_player	=	g_current_player;

	saving_game->nave.px			=	nave.px;
	saving_game->nave.py			=	nave.py;
	saving_game->nave.level		=	nave.level;
	saving_game->nave.fill	=	nave.fill;
	saving_game->nave.time		=	nave.time;

	return *saving_game;
}

void SaveGameState() {
	if(esat::IsKeyDown('S')){
		SaveGameFile = fopen("SaveGame.dat","wb");
		TSave_Game game = SaveGameDataCollect(&SaveGame, players, ship, player_shoots);
		fwrite(&game, sizeof(TSave_Game), 1, SaveGameFile);
		fclose(SaveGameFile);
	}
}

void UpdateSaveGame(TSave_Game saved_game, Player **players_ptr,
										TShip *nave, PlayerShoot **bullets) {

	for(int i=0;i<2;++i){
		(*(players_ptr)+i)->px					=	(saved_game.players+i)->px;
		(*(players_ptr)+i)->py					=	(saved_game.players+i)->py;
		(*(players_ptr)+i)->px2					=	(saved_game.players+i)->px2;
		(*(players_ptr)+i)->py2					=	(saved_game.players+i)->py2;
		(*(players_ptr)+i)->vel_x				=	(saved_game.players+i)->vel_x;
		(*(players_ptr)+i)->vel_y				=	(saved_game.players+i)->vel_y;
		(*(players_ptr)+i)->lives				=	(saved_game.players+i)->lives;
		(*(players_ptr)+i)->in_ground		=	(saved_game.players+i)->in_ground;
		(*(players_ptr)+i)->in_air			=	(saved_game.players+i)->in_air;
		(*(players_ptr)+i)->is_playing	=	(saved_game.players+i)->is_playing;
		(*(players_ptr)+i)->alive				=	(saved_game.players+i)->alive;
	}

	*bullets	=	saved_game.bullets;

	g_level				=	saved_game.g_level;
	g_difficulty	=	saved_game.g_difficulty;
	gamestate			=	saved_game.gamestate;

	nave->px				=	saved_game.nave.px;
	nave->py				=	saved_game.nave.py;
	nave->level			=	saved_game.nave.level;
	nave->fill			=	saved_game.nave.fill;
	nave->time			=	saved_game.nave.time;
}

void LoadSaveGame() {
	if((SaveGameFile = fopen("SaveGame.dat","rb")) != NULL) {
		if(esat::IsKeyDown('L')) {
			 while (fread(&SaveGame, sizeof(SaveGameFile), 1, SaveGameFile)) {
				 UpdateSaveGame(SaveGame, &players, &ship, &player_shoots);
			 }
			fclose(SaveGameFile);
		}
	}
}

void FreePuntero() {
	free(ground_left);
	free(ground_right);
	free(air_left);
	free(air_right);
	free(explosion);
	free(player_shoots);
	free(players);
	free(platform);
	free(BlockFigures);
	free(powerup.sprite);
	free(ship.sprites_ship_head);
	free(ship.sprites_ship_body);
	free(ship.sprites_ship_propeller);
	free(ship.sprites_combustion);
}
