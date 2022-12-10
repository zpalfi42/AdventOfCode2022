#include <day1.hpp>
#include <vector>
#include <algorithm>

std::string	moveSprite(std::string sprite, int x)
{
	while (x > 0)
	{
		if ((int)sprite.find_last_of('#') - (int)sprite.find_first_of('#') < 2)
			sprite = '#' + sprite;
		else
			sprite = '.' + sprite;
		x--;
	}
	while (x < 0)
	{
		sprite = sprite.substr(1);
		x++;
	}
	return (sprite);
}

void paint(std::string *result, std::string sprite, int cycles, int *generalCycle, int *cycleToFind, int *lastCycleToFind)
{
	while (cycles > 0)
	{
		result[(*cycleToFind/40) - 1] = result[(*cycleToFind/40) - 1] + sprite[*generalCycle - *lastCycleToFind];
		if (*generalCycle == *cycleToFind)
		{
			*lastCycleToFind += 40;
			*cycleToFind += 40;
		}
		cycles--;
		*generalCycle += 1;
	}
}

int	main( void )
{
	std::fstream	fd;
	std::string		s, sprite;
	std::string		options[2] = {"addx", "noop"};
	int				cycles, x, cycleToFind, generalCycle, lastCycleToFind;
	std::string		result[6];

	fd.open("./input", std::fstream::in);
	cycles = generalCycle = lastCycleToFind = 1;
	cycleToFind = 40;
	sprite = "###......................................";
	while (std::getline(fd, s))
	{
		cycles = options->find(s.substr(0, s.find_first_of(' '))) + 2;
		x = 0;
		if (cycles > 1)
			x = atoi(s.substr(s.find_first_of(' ')).c_str());
		paint(result, sprite, cycles, &generalCycle, &cycleToFind, &lastCycleToFind);
		sprite = moveSprite(sprite, x);
	}
	for (int i = 0; i < 6; i++)
	{
		std::replace(result[i].begin(), result[i].end(), '.', ' ');
		std::cout << result[i] << std::endl;
	}
}