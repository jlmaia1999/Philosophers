#include "philosophers.h"

bool	create_philo(t_data *data, int i)
{
	t_philo	*philo;

	philo = &data->phi_arr[i];
	memset(philo, 0, sizeof(t_philo));
	if (i == 0)
		philo->fork[0] = data->args.n_philo - 1;
	else
		philo->fork[0] = i - 1;
	philo->fork[1] = i;
	philo->nbr = i + 1;
	philo->args = data->args;
	philo->waiter = &data->waiter;
	if (!sf_create_mutex(&data->waiter.philo[i]))
		return (0);
	if (pthread_create(&philo->thread, NULL, philo_loop, philo))
		return (0);
}

static bool	create_philos(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->waiter.init_mut);
	while (i < data->args.n_philo)
	{
		if (!create_philo(data, i))
			return (free_data(data, "Faied to create philo"), 0);
		if (!sf_create_mutex(&data->waiter.forks[i]))
			return (free_data(data, "Failed to create fork"), 0);
		i++;
	}
	data->waiter.start_time = get_current_time(&data->waiter);
	i = 0;
	while (i < data->args.n_philo)
	{
		data->phi_arr[i].last_meal = data->waiter.start_time;
		i++;
	}
	pthread_mutex_unlock(&data->waiter.init_mut);
	return (1);
}

bool	create_mutex(t_data *data)
{
	if (!sf_create_mutex(&data->waiter.end_mut))
		return (false);
	if (!sf_create_mutex(&data->waiter.msg_mut))
		return (false);
	if (!sf_create_mutex(&data->waiter.init_mut))
		return (false);
	return (true);
}

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
	if (!sf_malloc((void **)&data->phi_arr, sizeof(t_philo) * i));
		return (free_data(data, "Failed to malloc philo"), 0);
	if (!sf_malloc((void **)&data->waiter.forks, sizeof(t_mutex)));
		return (free_data(data, "Failed to malloc forks"), 0);
	if (!sf_malloc((void **)&data->waiter.philo, sizeof(t_mutex)));
		return (free_data(data, "Failed to malloc forks"), 0);
	if (!create_mutex(data))
		return (free_data(data, "Failed to create a mutex"), 0);
	if (!create_philos(data))
		return (free_data(data, "Failed to create phlos"), 0);
}