#include "philo.h"

int	check_num(char *argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	preliminary_check(int argc, char **argv)
{
	/* if (!check_numerical_value(argv, argc))
		return (ph_print("non-numeric value detected!\n", 2)); */
	if (argc != 5 && argc != 6)
		return (printf("Invalid arguments!\n"));
	if (ph_atoi(argv[1]) < 1 || ph_atoi(argv[1]) > MAX || \
	!check_num(argv[1]))
		return (printf("Invalid number of Philosophers!\n"));
	if (ph_atoi(argv[2]) < 1 || !check_num(argv[2]))
		return (printf("Invalid time to die!\n"));
	if (ph_atoi(argv[3]) < 1 || !check_num(argv[3]))
		return (printf("Invalid time to eat!\n"));
	if (ph_atoi(argv[4]) < 1 || !check_num(argv[4]))
		return (printf("Invalid time to sleep!\n"));
	if (argv[5] && (ph_atoi(argv[5]) < 0 || !check_num(argv[5])))
		return (printf("Invalid number of times to eat!\n"));
	return (0);
}
