
#include "../header/philo.h"

void	ft_write(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

void	print_action(long id, long time, int action)
{
	if (action == TAKE_FORK)
		printf("%ld %ld has taken a fork\n", time, id);
	else if (action == EAT)
		printf("%ld %ld is eating\n", time, id);
	else if (action == SLEEP)
		printf("%ld %ld is sleeping\n", time, id);
	else if (action == THINK)
		printf("%ld %ld is thinking\n", time, id);
	else if (action == DIE)
		printf("%ld %ld died\n", time, id);
	else if (action == FINISH)
		printf("%ld %ld has been finish\n", time, id);
}

void	off_thread(thread_t *thread)
{
	int i;

	i = -1;
	while (++i < thread->data->number_phil)
	{
		pthread_detach(thread[i].pthread);
	}
}

int init_monitor(thread_t *thread, start_data_t *data)
{
	int i;
	struct timeval current_time;
	long	print_time;
	long	end_count;

	start_thread(thread, data);
	while (1)
	{
		i = -1;
		end_count = 0;
		gettimeofday(&current_time, 0);
		while (++i < thread->data->number_phil)
		{
//			printf("end_count=%ld, %d\n", end_count, i);
//			printf("%d", thread[i].end);
			if (thread[i].end == 1 && end_count++ > -1)
			{
				if (end_count == thread->data->number_phil)
					return(SUCCESS);
				continue;
			}
			print_time = count_time(current_time, thread->last_eat_time);
			if (thread[i].eating == 0 && thread[i].data->tt_die < print_time)
			{
				off_thread(thread);
				print_action(thread[i].id, thread[i].life_time + print_time, DIE);
				return(DIE);
			}
		}
	}
}

void	ft_usleep(long tt_sleep)
{
	struct timeval	time_1;
	long			time_0;
	gettimeofday(&time_1, NULL);
	time_0 = time_1.tv_sec * 1000 + time_1.tv_usec / 1000;
	while (tt_sleep > ((time_1.tv_sec * 1000 + time_1.tv_usec / 1000) - time_0))
	{
		gettimeofday(&time_1, NULL);
		usleep(100);
	}
}