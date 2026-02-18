/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:25:18 by jomaia            #+#    #+#             */
/*   Updated: 2026/02/18 15:34:32 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>


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
	t_mutex	msg_mut;
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

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		parse_args(int argc, char **argv, t_args *param);
int		print_error(char *str, t_waiter *waiter);
int		sf_malloc(void **ptr, unsigned long size);
void	free_data(t_data *data, char *error);
int		sf_create_mutex(t_mutex *mutex);
void	sf_destroy_mutex(t_mutex *mutex);
long	get_curent_time(t_waiter *waiter);
int		init_philo(int argc, char **argv, t_data *data);
void	msg(t_waiter *waiter, int n, char *action);
void	msg_died(t_waiter *waiter, int n);
void	philo_manager(t_data *data);
void	accurate_sleep(long	delta, t_waiter *waiter);
bool	read_end(t_waiter *waiter);
void	set_end(t_waiter *waiter);
void	*philo_loop(void *arg);
long	get_curent_time(t_waiter *waiter);
void	philo_join(t_data *data);



#endif
