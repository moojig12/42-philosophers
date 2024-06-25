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
		return (ph_print("Wrong number of Arguments!\n", 2));
	if (ph_atoi(argv[1]) < 1 || ph_atoi(argv[1]) > MAX || \
	!check_num(argv[1]))
		return (ph_print("Invalid number of Philosophers!\n", 2));
	if (ph_atoi(argv[2]) < 1 || !check_num(argv[2]))
		return (ph_print("Invalid time to die!\n", 2));
	if (ph_atoi(argv[3]) < 1 || !check_num(argv[3]))
		return (ph_print("Invalid time to eat!\n", 2));
	if (ph_atoi(argv[4]) < 1 || !check_num(argv[4]))
		return (ph_print("Invalid time to sleep!\n", 2));
	if (argv[5] && (ph_atoi(argv[5]) < 0 || !check_num(argv[5])))
		return (ph_print("Invalid number of times to eat!\n", 2));
	return (0);
}
