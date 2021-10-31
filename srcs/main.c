
#include "../header/philo.h"

int main(int argc, char **argv)
{
	start_data_t start_data;
	thread_t *threads = NULL;

	struct timeval time;

//	struct timeval time2;
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
	threads = fill_thread(threads, start_data.number_phil);
	gettimeofday(&time, 0);

//	printf("time1 = %d\n", time.tv_usec);

//	usleep(5100000);
//	gettimeofday(&time2, 0);
//	printf("time2 = %d\n", time2.tv_usec);

//	printf("time - time = %ld\n", ((time2.tv_sec * 1000000) + time2.tv_usec) - ((time.tv_sec * 1000000) + time.tv_usec));
//	printf("%ld\n", ((time2.tv_sec * 1000000) + time2.tv_usec) - ((time.tv_sec * 1000000) + time.tv_usec));
//	if (argc == 5)
//		start_five_args(argv);
//	else if (argc == 6)
//		start_six_args(argv);
	return 0;
}