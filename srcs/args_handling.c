
#include "../header/philo.h"

static void fill_null(start_data_t *start_data)
{
	start_data->number_phil = 0;
	start_data->tt_die = 0;
	start_data->tt_eat = 0;
	start_data->tt_sleep = 0;
	start_data->count_te = 0;
	start_data->flag = 0;
}

static int check_data(start_data_t *start_data)
{
	if (start_data->number_phil == 0 || start_data->tt_die == 0 \
 || start_data->tt_eat == 0 || start_data->tt_sleep == 0)
		return (1);
	return (0);
}

static void	print_data(start_data_t *start_data)
{
	printf("number_phil = %d\n", start_data->number_phil);
	printf("tt_die = %ld\n", start_data->tt_die);
	printf("tt_eat = %ld\n", start_data->tt_eat);
	printf("tt_sleep = %ld\n", start_data->tt_sleep);
	printf("count_te = %ld\n", start_data->count_te);
}

int		start_parse_args(char **argv, start_data_t *start_data)
{
	fill_null(start_data);
	if (fill_start_data(start_data, argv) == 1)
		return (FAIL);
	if (check_data(start_data))
		return (FAIL);
	print_data(start_data);
	return (SUCCESS);
}

long	catch_number(char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]) || i > 9)
			return (SUCCESS);
	}
	return (ft_atoi(argv));
}

int		catch_number_int(char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]) || i > 9)
			return (SUCCESS);
	}
	return (ft_atoi(argv));
}

int		fill_start_data(start_data_t *start_data, char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		if (i == 1)
			start_data->number_phil = catch_number_int(argv[i]);
		else if (i == 2)
			start_data->tt_die = catch_number(argv[i]);
		else if (i == 3)
			start_data->tt_eat = catch_number(argv[i]);
		else if (i == 4)
			start_data->tt_sleep = catch_number(argv[i]);
		else if (i == 5)
			start_data->count_te = catch_number(argv[i]);
	}
	if (start_data->number_phil <= 0 || start_data->tt_die <= 0 \
		|| start_data->tt_eat <= 0 || start_data->tt_sleep <= 0)
		return (FAIL);
	if (i == 6)
	{
		start_data->flag = 1;
		if (!start_data->count_te) {
			return (FAIL);
		}
	}
	return (SUCCESS);
}