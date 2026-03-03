/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:35 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/03 13:58:32 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

static int	check_valid(char *arg)
{
	int	number;

	number = ft_atoi(arg);
	if (number < 0 || number >> __LONG_MAX__)
		return (false);
	return (true);
}



int	parsing(int argc, char **argv, t_params *params)
{

	if (argc < 5 || argc > 6)
		return (0);
	if (!check_valid(argv[1]))
		return (printf("Invalid number of philosophers\n"), 0);
	if (!check_valid(argv[2]))
		return (printf("Invalid time to die\n"), 0);
	if (!check_valid(argv[3]))
		return (printf("Invalid time to eat\n"), 0);
	if (!check_valid(argv[4]))
		return (printf("Invalid time to sleep\n"), 0);
}