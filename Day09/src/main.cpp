#include <day1.hpp>
#include <vector>
#include <algorithm>

int				map[20000][20000];

typedef void (*moves)(int *px, int *py, int toMove, int aux);

void	move(int *p1x, int *p2x, int *p1y, int *p2y)
{
	if (*p1x - *p2x > 1)
	{
		if (*p1y - *p2y > 0)
			*p1y -= 1;
		else if (*p2y - *p1y > 0)
			*p1y += 1;
		*p1x -= 1;
	}
	else if (*p2x - *p1x > 1)
	{
		if (*p1y - *p2y > 0)
			*p1y -= 1;
		else if (*p2y - *p1y > 0)
			*p1y += 1;
		*p1x += 1;
	}
	else if (*p1y - *p2y > 1)
	{
		if (*p1x - *p2x > 0)
			*p1x -= 1;
		else if (*p2x - *p1x > 0)
			*p1x += 1;
		*p1y -= 1;
	}
	else if (*p2y - *p1y > 1)
	{
		if (*p1x - *p2x > 0)
			*p1x -= 1;
		else if (*p2x - *p1x > 0)
			*p1x += 1;
		*p1y += 1;
	}
}

void	moveSides(int *px, int *py, int toMove, int aux)
{
	if (aux == 0)
		aux++;
	while (toMove > 0)
	{
		px[0] += aux;
		for (size_t i = 1; i < 10; i++)
			move(&px[i], &px[i - 1], &py[i], &py[i - 1]);
		map[py[9]][px[9]] = 1;
		toMove--;
	}
}

void	moveUD(int *px, int *py, int toMove, int aux)
{
	aux -= 2;
	if (aux == 0)
		aux++;
	while (toMove > 0)
	{
		py[0] += aux;
		for (size_t i = 1; i < 10; i++)
			move(&px[i], &px[i - 1], &py[i], &py[i - 1]);
		map[py[9]][px[9]] = 1;
		toMove--;
	}
}

void	getTotal( void )
{
	int	total;

	total = 0;
	for (size_t i = 0; i < 20000; i++)
	{
		for (size_t j = 0; j < 20000; j++)
			if (map[i][j] == 1)
				total++;
	}
	std::cout << total << std::endl;
}

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	std::string		options;
	int				px[10];
	int				py[10];

	moves	moves[4] = {moveSides, moveSides, moveUD, moveUD};
	fd.open("./input", std::fstream::in);
	for (size_t i = 0; i < 10; i++)
		px[i] = py[i] = 10000;
	options = "LRUD";
	while (std::getline(fd, s))
		moves[options.find_first_of(s[0])](px, py, atoi(s.substr(s.find_first_of(' ')).c_str()), options.find_first_of(s[0]) - 1);
	getTotal();
}