#include "philosophers.h"

int	check_number(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (i == 0 && s[i] == '-')
			i++;
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	return (1);
}

int	check_valid(int	ac, char **value)
{
	int	i;

	i = 1;
	if(ac < 5 || ac > 6)
		return (0);
	while (value && value[i])
	{
		if(!check_number(value[i++]))
		{
			return (0);
		}
	}
	return (1);
}

void	args_values(char **value, t_args *args)
{
	args->n_philo = ft_atoi(value[1]);
	args->death_time = ft_atoi(value[2]);
	args->eat_time = ft_atoi(value[3]);
	args->sleep_time = ft_atoi(value[4]);
	if (value [5])
		args->n_meals = ft_atoi(value[5]);
	else 
		args->n_meals = -1;
}

int	check_sign(int ac, t_args *args)
{
	if (args->death_time < 0 || args->eat_time < 0 || args->n_philo < 0 ||
		args->sleep_time < 0)
		return (0);
	if (args->n_meals < 0 && ac == 6)
		return (0);
	return (1);
}

int	parsing(int	ac, char **value, t_args *args)
{
	if(!check_valid(ac, value))
		return (0);
	args_values(value, args);
	if (!check_sign(ac, args))
		return (0);
	return (1);
}
