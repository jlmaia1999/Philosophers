#include "philosophers.h"

void	set_end(t_waiter *waiter)
{
	pthread_mutex_lock(&waiter->end_mut);
	waiter->end = true;
	pthread_mutex_unlock(&waiter->end_mut);
}

bool	read_end(t_waiter *waiter)
{
	bool	ret;
	pthread_mutex_lock(&waiter->end_mut);
	ret = waiter->end;;
	pthread_mutex_unlock(&waiter->end_mut);
	return (ret);
}