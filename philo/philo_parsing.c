#include "philosophers.h"

static int	is_nbr(char *str, long *nbr, bool istime)
{
	long	temp;
	int		i;

	i = 0;
	temp = 0;
	*nbr = -1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			temp = temp * 10 + str[i] - '0';
		i++;
	}
	*nbr = temp;
	if (istime)
		return (temp <= INT_MAX / 1000);
	return (1);
}

static int	assign(char *str, long *nbr, bool istime, char *msg)
{
	if (!is_nbr(str, nbr, istime))
		return (print_error(msg, NULL));
	return (1);
}

int	parse_args(int argc, char **argv, t_args *param)
{
	int	ret;

	ret = 1;
	if (argc < 5 || argc > 6)
		return (print_error("Wrong argument count", NULL));
	if (!assign(argv[1], &param->n_philo, false, "Parse philosopher count"))
		ret = 0;
	if (!assign(argv[2], &param->death_time, true, "Parse time to die"))
		ret = 0;
	if (!assign(argv[3], &param->eat_time, true, "Parse time to eat"))
		ret = 0;
	if (!assign(argv[4], &param->sleep_time, true, "Parse time to sleep"))
		ret = 0;
	if (argc != 6)
		return (ret);
	if (!assign(argv[5], &param->n_meals, false, "Parse eat count"))
		ret = 0;
	if (param->n_meals == 0)
	{
		ret = 0;
		print_error("Eat count should be bigger than 0", NULL);
	}
	return (ret);
}
