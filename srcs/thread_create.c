
#include "../header/philo.h"

long	count_time(struct timeval left_time, struct timeval right_time)
{
	return ((left_time.tv_sec - right_time.tv_sec) * SEC + (left_time.tv_usec - right_time.tv_usec)) / MICROSEC;
}

void	*create_thread(void *param) {
	thread_t *thread = (thread_t*) param;
	struct timeval start_time;
	struct timeval end_time;

	pthread_mutex_unlock(thread->start);
//	while (1)
//	{
		gettimeofday(&start_time, 0);
		take_fork(thread, start_time);
		print_action(thread);
		usleep(thread->tt_eat * MICROSEC);
		put_fork(thread, start_time);
		gettimeofday(&end_time, 0);
		thread->life_time += count_time(end_time, start_time);
		print_action(thread);
//	}
	return NULL;
}

void	take_fork(thread_t *thread, struct timeval time)
{
	(void)time;
	pthread_mutex_lock(&thread->left_fork);
	pthread_mutex_lock(&thread->right_fork);
	thread->action = TAKE_FORK;
}

void	put_fork(thread_t *thread, struct timeval time)
{
	(void)time;
	pthread_mutex_unlock(&thread->left_fork);
	pthread_mutex_unlock(&thread->right_fork);
	thread->action = SLEEP;
	print_action(thread);
	thread->action = EAT;
}

int		start_thread(thread_t *threads, start_data_t *data)
{
	int i;
	pthread_mutex_t *start;

	pthread_mutex_init(start, NULL);
	pthread_mutex_lock(start);
	i = 0;
	while (i < data->number_phil)
	{
		pthread_mutex_lock(&threads[(i - 1) % data->number_phil].left_fork);
		pthread_mutex_lock(&threads[(i + 1) % data->number_phil].right_fork);
		threads[i].start = start;
	}
	i = -1;
	while (++i < data->number_phil)
	{
		if (pthread_create(&threads[i].pthread, NULL, &create_thread, &threads[i]))
			exit(ERROR_CREATE_THREAD);
	}
	pthread_mutex_unlock(start);
	return (SUCCESS);
}

thread_t	*fill_thread(thread_t *threads, start_data_t *data)
{
	long i;

	i = -1;
	gettimeofday(&data->time, 0);
	threads = malloc((sizeof(thread_t) * data->number_phil) + 1);
	if (!threads)
		return NULL;
	data->forks = malloc((sizeof(pthread_mutex_t) * data->number_phil + 1));
	if (!data->forks)
		return NULL;
	while (++i < data->number_phil)
	{
		threads[i].id = i + 1;
		threads[i].life_time = 0;
		threads[i].action = THINK;
		threads[i].tt_eat = data->tt_eat;
		if (pthread_mutex_init(data->forks, NULL))
			exit(ERROR_CREATE_MUTEX);
		threads[i].left_fork = data->forks[(i - 1) % data->number_phil];
		threads[i].right_fork = data->forks[(i + 1) % data->number_phil];
		threads[i].time = 0;
	}
	return threads;
}

void	print_action(thread_t *thread)
{
	int action = thread->action;
	if (action == TAKE_FORK)
		printf("%ld %ld has taken a fork\n", thread->life_time, thread->id);
	else if (action == EAT)
		printf("%ld %ld is eating\n", thread->life_time, thread->id);
	else if (action == SLEEP)
		printf("%ld %ld is sleeping\n", thread->life_time, thread->id);
	else if (action == THINK)
		printf("%ld %ld is thinking\n", thread->life_time, thread->id);
	else if (action == DIE)
		printf("%ld %ld died\n", thread->life_time, thread->id);
	else if (action == FINISH)
		printf("%ld %ld has been finish\n", thread->life_time, thread->id);
}

int init_monitor(thread_t *thread, start_data_t *startData)
{
	int i;

	i = -1;
	while (++i < startData->number_phil)
	{
		start_thread(thread, startData);

	}
	return (SUCCESS);
}