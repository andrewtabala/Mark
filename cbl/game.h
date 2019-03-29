#ifndef GAME_H
# define GAME_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include "minilibx_macos/mlx.h"

#define MAX_BULLETS	100

enum			e_bullet_type
{
	NORMAL,
	EXPLOSIVE
};

typedef struct	s_bullet
{
	unsigned char		speed;
	int					type;
	int					y;
	int					x;
}				t_bullet;

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
	void	*img_buttonplay;
	void	*img_buttonexit;
	void	*img_buttonframe;
	int		*img_data;
	int		pointscolor;
	int		lev;
	double	points;

	int		menuswitch;
	int		menubar;

	int		xguy;
	int		w;
	int		level_speed;
	int		bullet_count;
	t_bullet *bullets;
}				t_pr;


char	*ft_itoa(int n);
void	img(t_pr *g);
void	drawland(t_pr *g);
void	drawback(t_pr *g);
void	drawguy(t_pr *g);
void	move(int i, t_pr *w);
void	drawdrop(t_pr *g, int x, int y);
void	drawui(t_pr *g);
void	menu(t_pr *g);

#endif