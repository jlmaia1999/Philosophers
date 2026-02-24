/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:59:59 by jomaia            #+#    #+#             */
/*   Updated: 2026/02/24 11:05:14 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_end(t_waiter *waiter)
{
	pthread_mutex_lock(&waiter->end_mut.lock);
	waiter->end = true;
	pthread_mutex_unlock(&waiter->end_mut.lock);
}

bool	read_end(t_waiter *waiter)
{
	bool	ret;

	pthread_mutex_lock(&waiter->end_mut.lock);
	ret = waiter->end;
	pthread_mutex_unlock(&waiter->end_mut.lock);
	return (ret);
}
