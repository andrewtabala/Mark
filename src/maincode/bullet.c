#include "../headers/game.h"

void	init_bullet(t_bullet *bullet, t_pr *g)
{
	const int speed[] = {3, 5, 7, 9, 12, 15, 18, 21};

	bullet->speed = speed[rand() % (g->lev * 2)];
	bullet->x = rand() % g->w_width;
	bullet->y = rand() % 30;
}

int		bullet_kills(t_pr *g, t_bullet *bullet) {
	return (bullet->y >= 535 && bullet->y <= 640 - 30 && ((bullet->x >= g->xguy - 4 && bullet->x <= g->xguy + 38)
		|| (g->menubar == 2 && bullet->x >= g->xteammate - 4 && bullet->x <= g->xteammate + 38)));
}

void	bullet_fire(t_pr *g)
{
	int amount_bullet[] = {60, 55, 50, 45, 30, 25, 20, 15, 10, 5, 1};

	if (g->bullet_count != MAX_BULLETS && (!(rand() % amount_bullet[BS - 1]) || !((int)g->points % 500)))
	{
		init_bullet(&g->bullets[g->bullet_count], g);
		g->bullet_count++;
	}
	for (int i = 0; i < g->bullet_count; i++)
	{
		g->bullets[i].y += g->bullets[i].speed;
		if (g->bullets[i].y >= g->w_height) {
			init_bullet(&g->bullets[i], g);
		}
		if (bullet_kills(g, &g->bullets[i])) {
			game_over(g);
		}
		drawdrop(g, g->bullets[i].x, g->bullets[i].y);
	}
}
