
#include "../header/philo.h"

void	*create_thread(void *param) {
	thread_t *thread = (thread_t*) param;

	print_action(thread);
	return SUCCESS;
}

thread_t	*fill_thread(thread_t *threads, long number_of_philo)
{
	long i;
	struct timeval time;

	i = -1;
	gettimeofday(&time, 0);
	threads = malloc((sizeof(thread_t) * number_of_philo) + 1);
	if (!threads)
		return NULL;
	while (++i < number_of_philo)
	{
		threads[i].id = i;
		threads[i].life_time = 0;
	}
	i = -1;
	while (++i < number_of_philo)
	{
		if (pthread_create(&threads[i].pthread, NULL, &create_thread, &threads[i]))
			exit(ERROR_CREATE_THREAD);
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
		printf("%ld %ld has been die\n", thread->life_time, thread->id);
}