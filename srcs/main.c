
#include "../header/philo.h"

int main(int argc, char **argv)
{
	start_data_t start_data;
	thread_t *threads = NULL;

	struct timeval time3;
	if (argc == 5 || argc == 6)
	{
		if (start_parse_args(argv, &start_data))
			return (FAIL);
	}
	else
	{
		printf("Input correct arguments\n");
		return (FAIL);
	}
	threads = fill_thread(threads, &start_data);
	init_monitor(threads, &start_data);
//	return init_monitor(threads, &start_data);
//	printf("time1 = %d\n", time.tv_usec);

	gettimeofday(&time3, 0);

//	printf("time2 = %d\n", time2.tv_usec);

//	printf("time - time = %ld\n", ((time2.tv_sec * 1000000) + time2.tv_usec) - ((time.tv_sec * 1000000) + time.tv_usec));
//	printf("%ld\n", ((time2.tv_sec * 1000000) + time2.tv_usec) - ((time.tv_sec * 1000000) + time.tv_usec));
//	if (argc == 5)
//		start_five_args(argv);
//	else if (argc == 6)
//		start_six_args(argv);
	return 0;
}