#include "../headers/game.h"

void	playframes(t_pr *g)
{
	drawback(g);
	drawland(g);
	drawui(g);
	drawguy(g);
	bullet_fire(g);
}

void	setdef(t_pr *g)
{
	BS = 5;
	g->pauseswitch = 0;
	g->menuswitch = 1;
	g->menubar = 1;
	g->pointscolor = 6381921;
	g->level_speed = 3;
	g->w = 64;
	g->lev = 1;
	g->w_width = 480;
	g->w_height = 640;
	g->xguy = g->w_width/2 - 32;
}

void	init(t_pr *g)
{
	srand(time(0));
	bzero(g, sizeof(t_pr));
	setdef(g);
	g->mlx_ptr = mlx_init();
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	g->menuSound = Mix_LoadMUS("music/menu.mp3");
	g->firstLevel = Mix_LoadMUS("music/level1.mp3");
	g->secondLevel = Mix_LoadMUS("music/level2.mp3");
	g->thirdLevel = Mix_LoadMUS("music/level3.mp3");
	g->fourthLevel = Mix_LoadMUS("music/level4.mp3");
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->w_width, g->w_height, "Mark");
	g->img_keys = mlx_xpm_file_to_image(g->mlx_ptr, "textures/keys.xpm", &g->w, &g->w);
	g->img_keyscoop = mlx_xpm_file_to_image(g->mlx_ptr, "textures/keyscoop.xpm", &g->w, &g->w);
	g->img_mark = mlx_xpm_file_to_image(g->mlx_ptr, "textures/backmenu.xpm", &g->w, &g->w);
	g->img_diff = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diff.xpm", &g->w, &g->w);
	g->img_diffr = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diffr.xpm", &g->w, &g->w);
	g->img_diffl = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diffl.xpm", &g->w, &g->w);
	g->img_win = mlx_xpm_file_to_image(g->mlx_ptr, "textures/win.xpm", &g->w, &g->w);
	g->img_gameover = mlx_xpm_file_to_image(g->mlx_ptr, "textures/gameover.xpm", &g->w, &g->w);
	g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
	g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteam.xpm", &g->w, &g->w);	
	g->bullets = (t_bullet *)calloc(MAX_BULLETS, sizeof(t_bullet));
	g->xteammate = g->w_width - g->w;
}
