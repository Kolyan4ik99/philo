
#include "../header/philo.h"

long	count_time(struct timeval left_time, struct timeval right_time)
{
	return ((left_time.tv_sec - right_time.tv_sec) * SEC + (left_time.tv_usec - right_time.tv_usec)) / MICROSEC;
}

void	go_sleep(thread_t *thread)
{
	ft_usleep(thread->data->tt_sleep);
	gettimeofday(&thread->last_eat_time, 0);
	thread->life_time = count_time(thread->last_eat_time, thread->data->birth_time);
	print_action(thread->id, thread->life_time, THINK);
}

void	*create_thread(void *param) {
	thread_t *thread = (thread_t*) param;

	if (thread->id % 2 != 0) {
		ft_usleep(50);
	}
	while (1)
	{
		if (thread->data->flag == 1 && thread->counts_eat == thread->data->count_te)
		{
			thread->end = 1;
			return SUCCESS;
		}
		take_fork(thread);
		put_fork(thread);
		go_sleep(thread);
	}
}

void	take_fork(thread_t *thread)
{
	pthread_mutex_lock(thread->left_fork);
	pthread_mutex_lock(thread->right_fork);
	gettimeofday(&thread->time, 0);
	thread->life_time = count_time(thread->time, thread->data->birth_time);
	print_action(thread->id, thread->life_time, TAKE_FORK);
	print_action(thread->id, thread->life_time, TAKE_FORK);
	print_action(thread->id, thread->life_time, EAT);
	thread->eating = 1;
	thread->counts_eat += 1;
	ft_usleep(thread->data->tt_eat);
	thread->eating = 0;
}

void	put_fork(thread_t *thread)
{
	pthread_mutex_unlock(thread->left_fork);
	pthread_mutex_unlock(thread->right_fork);
	gettimeofday(&thread->time, 0);
	thread->life_time = count_time(thread->time, thread->data->birth_time);
	print_action(thread->id, thread->life_time, SLEEP);
}

int		start_thread(thread_t *threads, start_data_t *data)
{
	int i;

	i = -1;
	while (++i < data->number_phil)
	{
		if (pthread_create(&threads[i].pthread, NULL, &create_thread, &threads[i]))
			exit(ERROR_CREATE_THREAD);
	}
	return (SUCCESS);
}

thread_t	*fill_thread(thread_t *threads, start_data_t *data)
{
	long i;

	i = -1;
	gettimeofday(&data->birth_time, 0);
	threads = malloc((sizeof(thread_t) * data->number_phil));
	if (!threads)
		return NULL;
	data->forks = malloc((sizeof(pthread_mutex_t) * data->number_phil));
	if (!data->forks)
		return NULL;
	while (++i < data->number_phil)
	{
		threads[i].id = i + 1;
		threads[i].life_time = 0;
		threads[i].data = data;
		threads[i].counts_eat = 0;
		threads[i].end = 0;
		threads[i].last_eat_time = threads[i].data->birth_time;
		threads[i].eating = 0;
		if (pthread_mutex_init(&data->forks[i], NULL))
			exit(ERROR_CREATE_MUTEX);
		threads[i].left_fork = &data->forks[i];
		if (i + 1 == data->number_phil)
			threads[i].right_fork = &data->forks[0];
		else
			threads[i].right_fork = &data->forks[i + 1];
	}
	return threads;
}