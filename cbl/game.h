#ifndef GAME_H
# define GAME_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "minilibx_macos/mlx.h"

typedef struct 	s_pr
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		w_width;
	int		w_height;

	void	*img_ptr;
	void	*img_land;
	void	*img_back;
	void	*img_guy;
	void	*img_proj;
	int		*img_data;

	int		lev;

	int		xguy;


	int		w;
}				t_pr;

void	img(t_pr *g);
void	drawland(t_pr *g);
void	drawback(t_pr *g);
void	drawguy(t_pr *g);
void	move(int i, t_pr *w);
void	drawdrop(t_pr *g, int x, int y);

#endif