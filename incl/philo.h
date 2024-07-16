#ifndef PHILO_H
# define PHILO_H

# define MAX 300
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo {
	pthread_t	thread;
	int	id;
	int	eating;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat_count;
	int	start_time;
	int	last_meal;
	int	meals_eaten;
	int	philo_count;
	int	*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
}	t_philo;

typedef struct s_program {
	t_philo	*philo;
	int	found_dead;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
}	t_program;

// A function to monitor for observer
void	*monitor(void *pointer);

// routine actions
void	*philo_routine(void *pointer);
int		dead_loop(t_philo *philo);
void	eat(t_philo *philo);
void	sleepy(t_philo *philo);
void	think(t_philo *philo);


// Main thread creation
void	create_threads(t_program *program, pthread_mutex_t *forks);


// initiation
void	initiate_forks(pthread_mutex_t *forks, int philo_count);
void	initiate_program(t_program *program, t_philo *philo);
void	initiate_philosophers(t_philo *philo, pthread_mutex_t *forks, \
	t_program *program, char **argv);

// check
int	check_num(char *argv);
int	check_dead(t_philo *philo);
int	check_all_ate(t_philo *philo);
int	preliminary_check(int argc, char **argv);

// misc
int		ph_atoi(char *input);
void	ph_print_philo(char *message, t_philo *philo);
size_t	get_current_time(void);
void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks);
int		ft_usleep(size_t milliseconds);

#endif