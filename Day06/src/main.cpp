#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	std::string		sub;
	int				i;
	int				globali;
	int				firstRep;
	int				aux;

	fd.open("./input", std::fstream::in);
	std::getline(fd, s);
	sub = s.substr(0, 14);
	i = -1;
	firstRep = -1;
	aux = 0;
	globali = 0;
	while (42)
	{
		firstRep = -1;
		aux = 0;
		i = -1;
		while (++i < 14)
		{
			if (sub.find_first_of(sub[i]) != sub.find_last_of(sub[i]))
			{
				if (firstRep == -1)
					firstRep = i;
				aux = 1;
			}
		}
		if (aux == 0)
			break ;
		globali += firstRep + 1;
		sub = s.substr(globali, 14);
	}
	std::cout << sub << globali + 14 << std::endl;
}