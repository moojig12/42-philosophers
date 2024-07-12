#ifndef PHILO_H
# define PHILO_H

# define MAX 200
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo {
	pthread_t	thread;
	int	meals_eaten;
	int	mealts_to_eat;
	int	state;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program {
	pthread_t	*philo;
	pthread_t	*observer;
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat_count;
	int	found_dead;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
}	t_program;

// A function to monitor for observer
void	*monitor(void *pointer);

// check
int	check_num(char *argv);
int	preliminary_check(int argc, char **argv);

// misc
int	ph_atoi(char *input);
int	ph_print(char *message, int fd);

#endif