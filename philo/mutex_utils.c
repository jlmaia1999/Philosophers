#include "philosophers.h"

int	sf_create_mutex(t_mutex *mutex)
{
	mutex->set = false;
	if (pthread_mutex_init(&mutex->lock, NULL) != 0)
		return (0);
	mutex->set = true;
	return (1);
}

void	sf_destroy_mutex(t_mutex *mutex)
{
	if (mutex->set)
		pthread_mutex_destroy(&mutex->lock);
}