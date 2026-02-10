/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:53:15 by jomaia            #+#    #+#             */
/*   Updated: 2025/12/17 15:55:35 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *nptr)
{
	long	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10;
		num = num + (*nptr - '0');
		nptr++;
	}
	num = num * sign;
	return (num);
}
