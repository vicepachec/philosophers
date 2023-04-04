/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:22 by vpacheco          #+#    #+#             */
/*   Updated: 2023/04/04 18:56:11 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main (int ac, char **av)
{
	t_data	data;
	
	data.num_philos = ft_atoi(av[1]);
	data.philo_die	= ft_atoi(av[2]);
	data.philo_eat_time = ft_atoi(av[3]);
	data.philo_sleep = ft_atoi (av[4]);
	if (ac == 6)
	{
		data.must_eat = ft_atoi (av[5]);
		if (data.must_eat <= 0)
		{
			printf("Error\n");
			return(1);
		}
	}
	
	if (data.num_philos <= 0 || data.philo_die <= 0 || data.philo_eat_time <= 0 || \
		data.philo_sleep <= 0)
		{
			printf("Error\n");
			return(1);
		}
	philo_start(&data);
}