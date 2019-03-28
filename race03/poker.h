#ifndef POKER_H
# define POKER_H

# define C1 p->card1
# define C2 p->card2
# define C3 p->card3
# define C4 p->card4
# define C5 p->card5

# define C1S p->card1s
# define C2S p->card2s
# define C3S p->card3s
# define C4S p->card4s
# define C5S p->card5s

# define C1V p->card1v
# define C2V p->card2v
# define C3V p->card3v
# define C4V p->card4v
# define C5V p->card5v

# define V1 C1[0] != '2' && C1[0] != '3' && C1[0] != '4' && C1[0] != '5' && C1[0] != '6' && C1[0] != '7' && C1[0] != '8' && C1[0] != '9' && C1[0] != 'J' && C1[0] != 'Q' && C1[0] != 'K' && C1[0] != 'A'
# define V2 C2[0] != '2' && C2[0] != '3' && C2[0] != '4' && C2[0] != '5' && C2[0] != '6' && C2[0] != '7' && C2[0] != '8' && C2[0] != '9' && C2[0] != 'J' && C2[0] != 'Q' && C2[0] != 'K' && C2[0] != 'A'
# define V3 C3[0] != '2' && C3[0] != '3' && C3[0] != '4' && C3[0] != '5' && C3[0] != '6' && C3[0] != '7' && C3[0] != '8' && C3[0] != '9' && C3[0] != 'J' && C3[0] != 'Q' && C3[0] != 'K' && C3[0] != 'A'
# define V4 C4[0] != '2' && C4[0] != '3' && C4[0] != '4' && C4[0] != '5' && C4[0] != '6' && C4[0] != '7' && C4[0] != '8' && C4[0] != '9' && C4[0] != 'J' && C4[0] != 'Q' && C4[0] != 'K' && C4[0] != 'A'
# define V5 C5[0] != '2' && C5[0] != '3' && C5[0] != '4' && C5[0] != '5' && C5[0] != '6' && C5[0] != '7' && C5[0] != '8' && C5[0] != '9' && C5[0] != 'J' && C5[0] != 'Q' && C5[0] != 'K' && C5[0] != 'A'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_pr
{
	char	*card1;
	char	*card2;
	char	*card3;
	char	*card4;
	char	*card5;

	char	*card1s;
	char	*card2s;
	char	*card3s;
	char	*card4s;
	char	*card5s;

	char	*card1v;
	char	*card2v;
	char	*card3v;
	char	*card4v;
	char	*card5v;
}				t_pr;

#endif