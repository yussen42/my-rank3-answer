#include <stdio.h>
#include <stdlib.h>
​
int	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return (i);
}
void	ft_swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
void	sort_str(char *str)
{
	int	len = ft_strlen(str);

	while (len--)
	{
		int i = 0;
		while (str[i + 1])
		{
			if (str[i] > str[i + 1])
				ft_swap(str + i, str + i + 1);
			i++;
		}
	}
}
void	perm(char *str, int start, int end)
{
	if (start == end)
		puts(str);
	else
	{
		int i = start;
		while (i < end)
		{
			sort_str(str + start);
			ft_swap(str + start, str + i);
			perm(str, start + 1, end);
			ft_swap(str + start, str + i);
			i++;
		}
	}
}
int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	perm(av[1], 0, ft_strlen(av[1]));
	return (0);
}