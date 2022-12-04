#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long	int		total;
	std::string		min1;
	std::string		max1;
	std::string		min2;
	std::string		max2;
	int				imin1;
	int				imax1;
	int				imin2;
	int				imax2;

	fd.open("./input", std::fstream::in);
	total = 0;
	while (std::getline(fd, s))
	{
		min1 = s.substr(0, s.find_first_of('-'));
		max1 = s.substr(s.find_first_of('-') + 1, s.find_first_of(',') - s.find_first_of('-') - 1);
		min2 = s.substr(s.find_first_of(',') + 1, s.find_last_of('-') - s.find_first_of(',') - 1);
		max2 = s.substr(s.find_last_of('-') + 1);

		imin1 = atoi(min1.c_str());
		imax1 = atoi(max1.c_str());
		imin2 = atoi(min2.c_str());
		imax2 = atoi(max2.c_str());

		if (imin1 >= imin2 && imin1 <= imax2)
			total++;
		else if (imin1 <= imin2 && imax1 >= imin2)
			total++;
	}
	std::cout << total << std::endl;
}