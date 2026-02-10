#include "philosophers.h"

void	msg(t_waiter *waiter, int n, char *action)
{
	long	time;

	pthread_mutex_lock(&waiter->msg_mut);
	time = get_curent_time(waiter) - waiter->start_time;
	if (!read_end(waiter))
		printf("%ld %d died\n", time, n);
	pthread_mutex_unlock(&waiter->msg_mut);
}

void	msg_died(t_waiter *waiter, int n)
{
	long	time;

	pthread_mutex_lock(&waiter->msg_mut);
	time = get_curent_time(waiter) - waiter->start_time;
	if (!read_end(waiter))
	{
		printf("%ld %d died\n", time, n);
		set_end(waiter);
	}
	pthread_mutex_unlock(&waiter->msg_mut);
}