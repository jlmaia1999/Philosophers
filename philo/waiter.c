#include "philosophers.h"

static bool	reached_target(t_data *data)
{
	t_args		args;
	t_waiter	*waiter;
	bool		ret;
	int			i;

	waiter = &data->waiter;
	args = data->args;
	i = 0;
	while (i < args.n_philo)
	{
		pthread_mutex_lock(&waiter->philo[i]);
		ret = data->phi_arr[i].eat_count == args.n_meals;
		pthread_mutex_unlock(&waiter->philo[i]);
		if (!ret)
			return (false);
		i++;
	}
	return (true);
}

static bool	philo_died(t_data *data, int i)
{
	t_args		args;
	t_waiter	*waiter;
	bool		ret;
	long		time;

	waiter = &data->waiter;
	args = data->args;
	ret = false;
	pthread_mutex_lock(&waiter->philo[1]);
	time = get_curent_time(waiter);
	if (!data->phi_arr[i].finished)
	{
		if(time > data->phi_arr[i].last_meal + args.death_time)
		{
			ret = true;
			msg_died(waiter, data->phi_arr[i].nbr);
		}
	}
	pthread_mutex_unlock(&waiter->philo[i]);
	return (ret);
}

void	philo_manager(t_data *data)
{
	int	i;

	while (!read_end(&data->waiter))
	{
		i = 0;
		while(philo_died(data, i))
			return ;
		i++;
	}
	if (reached_target(data))
		return ;
}