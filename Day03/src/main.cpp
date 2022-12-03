#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	std::string		s2;
	std::string		s3;
	long	int		total;
	int				i;
	std::string		ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string		abc = "abcdefghijklmnopqrstuvwxyz";

	fd.open("./input", std::fstream::in);
	total = 0;
	while (std::getline(fd, s) && std::getline(fd, s2) && std::getline(fd, s3))
	{
		i = 0;
		while (s[i])
		{
			if (s2.find(s[i]) != std::string::npos && s3.find(s[i]) != std::string::npos)
			{
				std::cout << s[i] << std::endl;
				if (abc.find(s[i]) != std::string::npos)
					total += abc.find(s[i]) + 1;
				else
					total += ABC.find(s[i]) + 27;
				break ;
			}
			i++;
		}
	}
	std::cout << total << std::endl;
}