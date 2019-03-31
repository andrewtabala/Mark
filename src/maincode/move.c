#include "../headers/game.h"

void		move_left(int i, t_pr *g) {
	(g->menubar == 1 || g->menubar == 3 || i == 0) ? g->img_guy =
		mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy2.xpm", &g->w, &g->w) : 0;
	(g->menubar == 2 && i == 123) ? (g->img_teammate =
		mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteam2.xpm", &g->w, &g->w)) : 0;
	if (g->lev >= 3)
	{
		(g->menubar == 1 || i == 0 || g->menubar == 3) ? g->img_guy =
			mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace2.xpm", &g->w, &g->w) : 0;
		(g->menubar == 2 && i == 123) ? (g->img_teammate =
			mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteamspace2.xpm", &g->w, &g->w)) : 0;
	}
	if (g->xguy > 0 && (i == 0 || g->menubar == 1 || g->menubar == 3))
		g->xguy -= 8;
	else if (g->menubar == 2 && g->xteammate > 0 && i == 123)
		g->xteammate -= 8;
}

void		move_right(int i, t_pr *g) {
	(g->menubar == 1 || i == 2 || g->menubar == 3) ? g->img_guy =
		mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w) : 0;
	(g->menubar == 2 && i == 124) ? (g->img_teammate =
		mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteam.xpm", &g->w, &g->w)) : 0;
	if (g->lev >= 3)
	{
		(g->menubar == 1 || i == 2 || g->menubar == 3) ? g->img_guy =
			mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w) : 0;
		(g->menubar == 2 && i == 124) ? (g->img_teammate =
			mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteamspace.xpm", &g->w, &g->w)) : 0;
	}
	if (g->xguy < g->w_width - 64 && (i == 2 || g->menubar == 1 || g->menubar == 3))
		g->xguy += 8;
	else if (g->menubar == 2 && g->xteammate < g->w_width - 64 && i == 124)
		g->xteammate += 8;
}
