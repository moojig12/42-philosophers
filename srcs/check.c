#include "philo.h"

static int	check_for_alpha(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	pre_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Invalid number of arguments\n"), 1);
	if (check_for_alpha(argv, argc))
		return (printf("Non-numeral found in arguments\n"), 1);
	if (ph_atoi(argv[1]) < 1 || ph_atoi(argv[1]) > 500)
		return (printf("Invalid number of Philosophers\n"), 1);
	if (ph_atoi(argv[2]) < 1)
		return (printf("Invalid time to die\n"), 1);
	if (ph_atoi(argv[3]) < 1)
		return (printf("Invalid time to eat\n"), 1);
	if (ph_atoi(argv[4]) < 1)
		return (printf("Invalid time to sleep\n"), 1);
	if (argv[5])
		if (ph_atoi(argv[5]) < 1)
			return (printf("Invalid times to eat\n"), 1);
	return (0);
}
