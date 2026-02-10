#include "philosophers.h"

int	init_philo(int argc, char **argv, t_data *data)
{
	unsigned int	i;

	memset(&data->waiter, 0, sizeof(t_waiter));
	memset(&data->args, 0, sizeof(t_args));
	data->args.n_meals = -1;
	if (!parsing(argc, argv, &data->args))
		return 0;
	i = data->args.n_philo;
	data->waiter.finished_count = i;
	
}