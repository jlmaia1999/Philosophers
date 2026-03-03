/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:40 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/03 13:32:20 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"
# include "stdbool.h"

typedef struct	s_params
{
	int	n_philo;
	long	delta_death;
	long	delta_eat;
	long	delta_sleep;
	long	_n_meals;
}	t_params;

typedef	struct s_waiter
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*philo;
	
}	t_waiter;

int	ft_atoi(const char *nptr);

#endif