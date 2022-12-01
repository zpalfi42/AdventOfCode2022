#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long	int		total;
	long	int		totalMax;
	long	int		totalMax2;
	long	int		totalMax3;

	fd.open("./input", std::fstream::in);
	total = 0;
	totalMax = 0;
	totalMax2 = 0;
	totalMax3 = 0;
	while (std::getline(fd, s))
	{
		if (s[0] == '\0')
		{
			if (total > totalMax)
			{
				totalMax3 = totalMax2;
				totalMax2 = totalMax;
				totalMax = total;
			}
			else if (total > totalMax2)
			{
				totalMax3 = totalMax2;
				totalMax2 = total;
			}
			else if (total > totalMax3)
				totalMax3 = total;
			total = 0;
			continue;
		}
		total += atoi(s.c_str());
	}
	total = totalMax + totalMax2 + totalMax3;
	std::cout << "Answer for Part 1: " << totalMax << "!" << std::endl;
	std::cout << "Answer for Part 2: " << total << " = " << totalMax << " + " << totalMax2 << " + " << totalMax3 << "!" << std::endl;
}