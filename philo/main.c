/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:22 by vpacheco          #+#    #+#             */
/*   Updated: 2023/03/21 18:27:26 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main (int ac, char **av)
{
	t_data	data;
	
	data.philo_number = ft_atoi(av[1]);
	data.philo_die	= ft_atoi(av[2]);
	data.philo_eat_time = ft_atoi(av[3]);
	data.philo_sleep = ft_atoi (av[4]);
	if (ac == 6)
	{
		data.times_eaten = ft_atoi (av[5]);
		if (data.times_eaten <= 0)
		{
			printf("Error\n");
			return(1);
		}
	}
	
	if (data.philo_number <= 0 || data.philo_die <= 0 || data.philo_eat_time <= 0 || \
		data.philo_sleep <= 0)
		{
			printf("Error\n");
			return(1);
		}
}