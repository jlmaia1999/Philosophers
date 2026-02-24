/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:00:42 by jomaia            #+#    #+#             */
/*   Updated: 2026/02/24 11:02:33 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset (&data, 0, sizeof(t_data));
	if (init_philo(argc, argv, &data))
	{
		philo_manager(&data);
		philo_join(&data);
		free_data(&data, NULL);
	}
}
