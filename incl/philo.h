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
	int				philo_count;
	long			start_time;
	long			last_eaten;
	int				times_eaten;
	int				eating;
	int				*dead;
	t_input			*input;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_program {
	int				dead_flag;
	t_philo			*philo;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*forks;
	// t_input			*input;
}	t_program;

// threads
void	create_threads(t_program *program, t_philo *philo, t_input *input);

// routine
void	*routine(void *ptr);
void	*monitor(void *ptr);
int		dead_loop(t_philo *philo);

// initiate
void	initiate_program(t_program *program, t_philo *philo, t_input *input);
t_input	*save_input(char **argv);
void	philo_message(char *message, t_philo *philo);

// check
int		pre_check(int argc, char **argv);

// utils
int		ft_usleep(long milliseconds);
int		ph_atoi(char *input);
void	destroy_all(t_program *program);
long	get_time();
long	get_current_time(t_philo *philo);

#endif