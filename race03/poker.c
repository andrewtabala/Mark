#include "poker.h"

void	set(t_pr *p)
{
	if (C1[2])
	{
		C1V[1] = C1[1];
		C1S[0] = C1[2];
	}
	else
		C1S[0] = C1[1];
	C1V[0] = C1[0];
	if (C2[2])
	{
		C2V[1] = C2[1];
		C2S[0] = C2[2];
	}
	else
		C2S[0] = C2[1];
	C2V[0] = C2[0];
	if (C3[2])
	{
		C3V[1] = C3[1];
		C3S[0] = C3[2];
	}
	else
		C3S[0] = C3[1];
	C3V[0] = C3[0];
	if (C4[2])
	{
		C4V[1] = C4[1];
		C4S[0] = C4[2];
	}
	else
		C4S[0] = C4[1];
	C4V[0] = C4[0];
	if (C5[2])
	{
		C5V[1] = C5[1];
		C5S[0] = C5[2];
	}
	else
		C5S[0] = C5[1];
	C5V[0] = C5[0];

}

void	validate3(t_pr *p)
{
	if ((C1[2] && (C1[2] != 'H' || C1[2] != 'C' || C1[2] != 'S' || C1[2] != 'D')) ||
		 (!C1[2] && (C1[1] != 'H' || C1[1] != 'C' || C1[1] != 'S' || C1[1] != 'D')) ||
		 (C2[2] && (C2[2] != 'H' || C2[2] != 'C' || C2[2] != 'S' || C2[2] != 'D')) ||
		 (!C2[2] && (C2[1] != 'H' || C2[1] != 'C' || C2[1] != 'S' || C2[1] != 'D')) ||
		 (C3[2] && (C3[2] != 'H' || C3[2] != 'C' || C3[2] != 'S' || C3[2] != 'D')) ||
		 (!C3[2] && (C3[1] != 'H' || C3[1] != 'C' || C3[1] != 'S' || C3[1] != 'D')) ||
		 (C4[2] && (C4[2] != 'H' || C4[2] != 'C' || C4[2] != 'S' || C4[2] != 'D')) ||
		 (!C4[2] && (C4[1] != 'H' || C4[1] != 'C' || C4[1] != 'S' || C4[1] != 'D')) ||
		 (C5[2] && (C5[2] != 'H' || C5[2] != 'C' || C5[2] != 'S' || C5[2] != 'D')) ||
		 (!C5[2] && (C5[1] != 'H' || C5[1] != 'C' || C5[1] != 'S' || C5[1] != 'D')))
	{
		printf("%s\n", "Invalid card suit");
		exit(0);
	}
}

void	validate2(t_pr *p)
{
	char	*check = NULL;
	if (C1[2])
		check = C1;
	else if (C2[2])
		check = C2;
	else if (C3[2])
		check = C3;
	else if (C4[2])
		check = C4;
	else if (C5[2])
		check = C5;
	if ((check && check[0] != '1' && check[1] != '0') ||
		(V1) || (V2) || (V3) || (V4) || (V5))
	{
		printf("%s\n", "Invalid card rank");
		exit(0);
	}

	validate3(p);
}

void	validate1(t_pr *p)
{
	if (strcmp(C1, C2) == 0 || strcmp(C1, C3) == 0 ||
		strcmp(C1, C4) == 0 || strcmp(C1, C5) == 0 ||
		strcmp(C2, C3) == 0 || strcmp(C2, C4) == 0 ||
		strcmp(C2, C5) == 0 || strcmp(C3, C4) == 0 ||
		strcmp(C3, C5) == 0 || strcmp(C4, C5) == 0)
	{
		printf("%s\n", "Error: duplicate cards");
		exit(0);
	}
	validate2(p);
}

int		main(int argc, char **argv)
{
	t_pr p;
	if (argc != 6)
	{
		printf("%s\n", "usage: ./race03 [card1] [card3] [card3] [card4] [card5]");	
		return (0);
	}
	p.card1 = argv[1];
	p.card2 = argv[2];
	p.card3 = argv[3];
	p.card4 = argv[4];
	p.card5 = argv[5];
	validate1(&p);
	return (0);
}