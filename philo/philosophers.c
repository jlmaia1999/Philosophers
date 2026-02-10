#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_args));
	if (init_philo(argc, argv, &data))
	{
		philo_manager(&data);
		philo_join(&data);
		free_data(&data, NULL);
	}
}