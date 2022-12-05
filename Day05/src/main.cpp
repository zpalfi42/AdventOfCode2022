#include <day1.hpp>

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	int				i;
	int				move;
	int				from;
	int				to;
	std::string		sfrom;
	std::string		sto;
	std::string		smove;
	std::string		tomove;
	std::string		stack[9];

	fd.open("./input", std::fstream::in);
	while (std::getline(fd, s))
	{
		i = 0;
		if (s[0] == '\0')
			break ;
		while (i < (int)s.length())
		{
			i = s.find_first_of('[', i);
			if (i < 0)
				break;
			stack[i / 4] = s[i + 1] + stack[i / 4];
			i++;
		}
	}
	while (std::getline(fd, s))
	{
		smove = s[s.find_first_of(' ') + 1];
		if (s[s.find_first_of(' ') + 2] != ' ')
			smove = smove + s[s.find_first_of(' ') + 2];
		sfrom = s[s.find_first_of(' ', s.find_first_of(' ') + 4) + 1];
		sto = s[s.size() - 1];
		move = atoi(smove.c_str());
		from = atoi(sfrom.c_str()) - 1;
		to = atoi(sto.c_str()) - 1;
		tomove = stack[from].substr((stack[from].size() - move));
		stack[to] = stack[to] + tomove;
		stack[from].resize(stack[from].size() - move);
	}
	for (int i = 0; i < 9; i++)
		std::cout << stack[i][stack[i].size() - 1];
	std::cout << std::endl;
}