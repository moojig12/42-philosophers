#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_input {
	int	philo_count;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_input;

typedef struct s_philo {
	pthread_t		thread;
	int				id;
	int				start_time;
	int				last_eaten;
	int				times_eaten;
	int				eating;
	int				*dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_input			*input;
}	t_philo;

typedef struct s_program {
	int				dead;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	// t_input			*input;
}	t_program;

// threads
void	create_threads(t_program *program, t_philo *philo, t_input *input);

// routine
void	*routine(void *ptr);
void	*monitor(void *ptr);

// initiate
void	initiate_program(t_program *program, t_philo *philo, t_input *input);
t_input	*save_input(char **argv);

// check
int		pre_check(int argc, char **argv);

// utils
int		ph_atoi(char *input);
void	destroy_all(t_program *program);
size_t	get_time();
size_t	get_current_time(t_philo *philo);

#endif