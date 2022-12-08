#include <day1.hpp>
#include <vector>
#include <algorithm>

int	best;

int	lookLeft(std::string *map, int i, int j)
{
	int	aux = j;
	while (--aux >= 0)
		if (map[i][aux] >= map[i][j])
			return (j - aux);
	return (j);
}

int	lookRight(std::string *map, int i, int j)
{
	int aux = j;
	while (++aux < (int)map[0].length())
		if (map[i][aux] >= map[i][j])
			return (aux - j);
	return (aux - j - 1);
}

int	lookUp(std::string *map, int i, int j)
{
	int	aux = i;
	while (--aux >= 0)
		if (map[aux][j] >= map[i][j])
			return (i - aux);
	return (i);
}

int	lookDown(std::string *map, int i, int j)
{
	int aux = i;
	while (++aux < (int)map[0].length())
		if (map[aux][j] >= map[i][j])
			return (aux - i);
	return (aux - i - 1);
}

void	proveVisible(std::string *map, int i, int j)
{
	int	visibility;

	visibility = lookUp(map, i, j) * lookDown(map, i, j)
				* lookLeft(map, i, j)* lookRight(map, i, j);
	if (visibility > best)
		best = visibility;
}

int	main( void )
{
	std::fstream	fd;
	std::string		map[100];
	int				i;
	int				j;

	i = 0;
	best = 0;
	fd.open("./input", std::fstream::in);
	while (std::getline(fd, map[i]))
		i++;
	i = -1;
	while (++i < (int)map[0].length())
	{
		j = -1;
		while (++j < (int)map[0].length())
			proveVisible(map, i, j);
	}
	std::cout << best << std::endl;
}