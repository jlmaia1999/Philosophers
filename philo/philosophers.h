/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:25:18 by jomaia            #+#    #+#             */
/*   Updated: 2026/02/10 14:08:21 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "unistd.h"
# include "sys/time.h"
# include "string.h"
# include "stdbool.h"


typedef struct s_args
{
	long	n_philo;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	n_meals;
}	t_args;

typedef struct s_mutex
{
	pthread_mutex_t	lock;
	bool			set;
}	t_mutex;

typedef struct s_waiter
{
	t_mutex	*forks;
	t_mutex	*philo;
	t_mutex	end_mut;
	t_mutex	init_mut;
	long	start_time;
	int		finished_count;
	bool	end;
}	t_waiter;

typedef struct s_philo
{
	t_waiter	*waiter;
	pthread_t	thread;
	t_args		args;
	long		last_meal;
	int			fork[2];
	int			nbr;
	int			eat_count;
	bool		finished;
}	t_philo;

typedef struct s_data
{
	t_philo		*phi_arr;
	t_waiter	waiter;
	t_args		args;
}	t_data;

int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int	parsing(int	ac, char **value, t_args *args);

#endif
#endif