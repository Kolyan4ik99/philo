
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
# define ERROR_CREATE_MUTEX		-13
# define SUCCESS				0
# define FAIL					1

# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FINISH 5
# define MICROSEC 1000
# define SEC MICROSEC * 1000

typedef struct	start_data_s {
	int			number_phil;
	long		tt_die;
	long		tt_eat;
	long		tt_sleep;
	long		count_te;
	pthread_mutex_t	*forks;
	struct timeval	time;
}				start_data_t;

typedef struct		thread_s {
	long			id;
	pthread_t		pthread;
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	pthread_mutex_t	*start;
	long			life_time;
	int				action;
	long			tt_eat;
	long			time;
}					thread_t;

/* main */
int			main(int argc, char **argv);

/* args_handling.c */
int			fill_start_data(start_data_t *start_data, char **argv);
int			start_parse_args(char **argv, start_data_t *start_data);

/* thread_create.c */
void		*create_thread(void *param);
thread_t	*fill_thread(thread_t *threads, start_data_t *data);
void		print_action(thread_t *thread);
int			init_monitor(thread_t *thread, start_data_t *startData);

void	take_fork(thread_t *thread, struct timeval time);
void	put_fork(thread_t *thread, struct timeval time);

#endif