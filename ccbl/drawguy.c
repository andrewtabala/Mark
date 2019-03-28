#include "game.h"

void	drawguy(t_pr *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_guy, g->xguy, g->w_height - 80);
}