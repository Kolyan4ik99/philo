
#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# include "../libft/libft.h"

# define ERROR_CREATE_THREAD	-11
# define ERROR_JOIN_THREAD		-12
# define SUCCESS				0
# define FAIL					1

# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FINISH 5

typedef struct	start_data_s {
	int			number_phil;
	long		tt_die;
	long		tt_eat;
	long		tt_sleep;
	long		count_te;
}				start_data_t;

typedef struct		thread_s {
	long			id;
	pthread_t		pthread;
	long			life_time;
	int				action;
}					thread_t;

/* main */
int			main(int argc, char **argv);

/* args_handling.c */
int			fill_start_data(start_data_t *start_data, char **argv);
int			start_parse_args(char **argv, start_data_t *start_data);

/* thread_create.c */
void		*create_thread(void *param);
thread_t	*fill_thread(thread_t *threads, long number_of_philo);
void		print_action(thread_t *thread);

#endif