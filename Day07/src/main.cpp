#include <day1.hpp>
#include <vector>
#include <algorithm>

std::vector <int>	allSizes;
int					answer;

struct dir
{
	std::string 		name;
	std::vector <dir>	next;
	struct dir			*prev;

	int					subtotal;
};

int	getSize( dir *dir)
{
	int	i;

	i = -1;
	while (++i < (int)dir->next.size())
		dir->subtotal += getSize(&dir->next[i]);
	if (dir->subtotal < 100000)
		answer += dir->subtotal;
	allSizes.push_back(dir->subtotal);
	return (dir->subtotal);
}

void	getAnswer2(int totalSize)
{
	int	i;
	int	dif;
	int	best;

	std::sort(allSizes.begin(), allSizes.end());
	dif = 70000000;
	i = -1;
	while (++i < (int)allSizes.size())
	{
		if (70000000 - (totalSize - allSizes[i]) > 30000000 && 70000000 - (totalSize - allSizes[i]) < dif)
		{
			dif = 70000000 - (totalSize - allSizes[i]);
			best = allSizes[i];
		}
	}
	std::cout << "Answer for part 2: *" << best << "*" << std::endl; 
	std::cout << "The final free disk space is: 70000000 - (" << totalSize << " - *" << best << "*) = " << dif << std::endl;
}

int	main( void )
{
	std::fstream	fd;
	std::string		s;
	std::string		snum;
	struct dir		*root = new dir;
	int				totalSize;

	root->prev = root;
	root->name = "root";
	answer = 0;

	dir				*curr = root;
	fd.open("./input", std::fstream::in);
	while (std::getline(fd, s))
	{
		if (s[0] == '$' && s[2] == 'c')
		{
			if (s[5] == '.')
				curr = curr->prev;
			else
			{
				snum = s.substr(5);
				if (snum[0] != '/')
					for(int i = 0; i < (int)(curr->next).size(); i++)
						if (snum == curr->next[i].name)
							curr = &curr->next[i];
			}
		}
		else if (s[0] == 'd')
		{
			dir	*subdir = new dir;
			subdir->prev = curr;
			subdir->name = s.substr(4);
			curr->next.push_back(*subdir);
		}
		else if (s[0] >= '0' && s[0] <= '9')
		{
			snum = s.substr(0, s.find_first_of(' '));
			curr->subtotal += atoi(snum.c_str());
		}
	}
	totalSize = getSize(root);
	std::cout << "Answer for part 1: *" << answer << "*" << std::endl;
	getAnswer2(totalSize);
}