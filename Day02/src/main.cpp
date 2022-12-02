#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	long	int		total;
	int				i;
	std::string		xyz = "XYZ";
	std::string		abc = "ABC";

	fd.open("./input", std::fstream::in);
	total = 0;
	while (std::getline(fd, s))
	{
		if (xyz.find(s[2]) == 0)
		{
			i = abc.find(s[0]) - 1;
			if (i < 0)
				i = 2;
			total += i + 1;
		}
		else if (xyz.find(s[2]) == 1)
		{
			i = abc.find(s[0]);
			total += i + 4;
		}
		else
		{
			i = abc.find(s[0]) + 1;
			if (i > 2)
				i = 0;
			total += i + 7;
		}
	}
	std::cout << total << std::endl;
}