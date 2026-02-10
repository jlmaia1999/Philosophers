#include "philosophers.h"

void	philo_join(t_data *data)
{
	int	i;

	i  = 0;
	while (i < data->args.n_philo)
	{
		if (pthread_join(data->phi_arr[i].thread, NULL) != 0)
		{
			print_error("Failed to join threads\n", &data->waiter);
			set_end(&data->waiter);
			break ;
		}
		i++;
	}
}