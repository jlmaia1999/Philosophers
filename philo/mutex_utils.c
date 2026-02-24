/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:00:22 by jomaia            #+#    #+#             */
/*   Updated: 2026/02/24 11:01:46 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
