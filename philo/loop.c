#include "philosophers.h"

static bool	update_time(t_philo *philo, t_waiter *waiter)
{
	pthread_mutex_lock(&waiter->philo[philo->nbr - 1]);
	philo->last_meal = get_curent_time(waiter);
	pthread_mutex_unlock(&waiter->philo[philo->nbr - 1]);
}

static bool	update_eat_count(t_philo *philo, t_waiter *waiter)
{
	bool	finished;

	pthread_mutex_lock(&waiter->philo[philo->nbr-1]);
	philo->eat_count++;
	philo->finished = philo->eat_count == philo->args.n_meals;
	finished = philo->finished;
	pthread_mutex_unlock(&waiter->philo[philo->nbr - 1]);
	return (finished);
}

static bool eat_cycle(t_philo *philo)
{
	t_waiter	*waiter;
	bool		finished;

	waiter = philo->waiter;
	pthread_mutex_lock(&waiter->forks[philo->fork[philo->nbr % 2 == 0]]);
	msg (waiter, philo->nbr, "has taken a fork");
	pthread_mutex_lock(&waiter->forks[philo->fork[philo->nbr % 2 != 0]]);
	msg(waiter, philo->nbr, "has taken a fork");
	update_time(philo, waiter);
	msg (waiter, philo->nbr, "is eating");
	accurate_sleep(philo->args.eat_time, waiter);
	pthread_mutex_unlock(&waiter->forks[philo->fork[philo->nbr % 2 == 0]]);
	pthread_mutex_unlock(&waiter->forks[philo->fork[philo->nbr % 2 != 0]]);
	finished = update_eat_count(philo, waiter);
	return (finished);
}

void	*philo_loop(void *arg)
{
	t_waiter	*waiter;
	t_philo		*philo;

	philo = ((t_philo *) arg);
	waiter = philo->waiter;
	pthread_mutex_lock(&waiter->init_mut);
	pthread_mutex_unlock(&waiter->init_mut);
	if (philo->args.n_philo == 1)
	{
		msg(waiter, philo->nbr, "has taken a fork");
		accurate_sleep(philo->args.death_time, waiter);
		return (NULL);
	}
	if (philo->nbr % 2 == 0)
		accurate_sleep(10, philo->waiter);
	while (!read_end(philo->waiter))
	{
		if (eat_cycle(philo))
			break;
		msg(waiter, philo->nbr, "is sleeping");
		accurate_sleep(philo->args.sleep_time, waiter);
		msg (waiter, philo->nbr, "is thinking");
	}
	return (NULL);
}