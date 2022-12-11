#include <day1.hpp>
#include <vector>
#include <algorithm>


class Monkey
{
private:
	/* data */
public:
	Monkey(){};
	Monkey(std::string name);

	std::string	name;
	std::vector	<int>	items;
	int			div;
	std::string	operation;
	int			opNum;
	int			ifTrue, ifFalse;
	int			count;
};


int	main( void )
{
	std::fstream	fd;
	std::string		s;
	Monkey			monkeys[8];
	int				i, rounds;
	int				from, to, size, best1, best2;

	i = 0;
	fd.open("./input", std::fstream::in);
	while (std::getline(fd, s))
	{
		//std::cout << s << std::endl;
		if (s[0] == 'M')
		{
			monkeys[i].name = s.substr(s.find_first_of(' '));
			i++;
		}
		else if (s.empty())
			continue;
		else if (s[2] == 'S')
		{
			from = s.find_first_of(':');
			to = s.find_first_of(',');
			size = to - from - 2;
			monkeys[i - 1].items.push_back(atoi(s.substr(from + 2, size).c_str()));
			while (42)
			{
				from = to;
				to = s.find_first_of(',', from + 1);
				size = to - from - 2;
				if (from == to || to < 0 || from < 0)
				{
					if (from > 0 && to < 0)
						monkeys[i - 1].items.push_back(atoi(s.substr(from + 2).c_str()));
					break ;
				}
				monkeys[i - 1].items.push_back(atoi(s.substr(from + 2, size).c_str()));
			}
		}
		else if (s[2] == 'O')
		{
			monkeys[i - 1].opNum = atoi(s.substr(s.find_last_of(' ')).c_str());
			if (monkeys[i - 1].opNum == 0)
				monkeys[i - 1].operation = "$";
			else
				monkeys[i - 1].operation = s.substr(s.find_first_of('l') + 3, 1);
		}
		else if (s[2] == 'T')
			monkeys[i - 1].div = atoi(s.substr(s.find_last_of(' ')).c_str());
		else if (s[4] == 'I' && s[5] == 'f')
		{
			if (s[7] == 't')
				monkeys[i - 1].ifTrue = atoi(s.substr(s.find_last_of(' ')).c_str());
			else if (s[7] == 'f')
				monkeys[i - 1].ifFalse = atoi(s.substr(s.find_last_of(' ')).c_str());
		}
		monkeys[i - 1].count = 0;
	}
	rounds = 20;
	while (rounds > 0)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < (int)monkeys[j].items.size(); k++)
			{
				std::cout << "Monkey " << j << " transforms item " << monkeys[j].items[k];
				if (monkeys[j].operation == "+")
				{
					monkeys[j].items[k] += monkeys[j].opNum;
				}
				else if (monkeys[j].operation == "*")
				{
					monkeys[j].items[k] *= monkeys[j].opNum;
				}
				else if (monkeys[j].operation == "$")
				{
					monkeys[j].items[k] *= monkeys[j].items[k];
				}
				monkeys[j].items[k] /= 3;
				std::cout << " to " << monkeys[j].items[k];
				//std::cout << monkeys[j].items[k] << " % " << monkeys[j].div << " = " << monkeys[j].items[k] % monkeys[j].div << std::endl;
				if (monkeys[j].items[k] % monkeys[j].div == 0)
				{
					monkeys[monkeys[j].ifTrue].items.push_back(monkeys[j].items[k]);
					std::cout << " and sends it to monkey TRUE " << monkeys[j].ifTrue << std::endl;
				}
				else
				{
					monkeys[monkeys[j].ifFalse].items.push_back(monkeys[j].items[k]);
					std::cout << " and sends it to monkey FALSE " << monkeys[j].ifFalse << std::endl;
				}
			}
			monkeys[j].count += (int)monkeys[j].items.size();
			monkeys[j].items.clear();
		}
		for (int i = 0; i < 8; i++)
		{
			std::cout << "Monkey " << i << " : ";
			for (int j = 0; j < (int)monkeys[i].items.size(); j++)
				std::cout << monkeys[i].items[j] << ", ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
		rounds--;
	}

	best1 = best2 = 0;
	for (int i = 0; i < 8; i++)
	{
		std::cout << monkeys[i].count << std::endl;
		if (monkeys[i].count > best1)
		{
			best2 = best1;
			best1 = monkeys[i].count;
		}
		else if (monkeys[i].count > best2)
		{
			best2= monkeys[i].count;
		}

	}
	std::cout << best1 << " * " << best2 << " = " << best1 * best2 << std::endl;
}