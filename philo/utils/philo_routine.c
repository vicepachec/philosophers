/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:19:57 by vpacheco          #+#    #+#             */
/*   Updated: 2023/04/04 18:21:08 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int		philo_sleep(t_philo *philos)
{
	long int	nap_time;
	long int	napping;
	
	nap_time = get_time();
	napping = 0;
	if (check_death(philos))
		return(1);
	print_message(philos, "is sleeping");
	usleep(100);
	while (napping <= philos->data->philo_sleep)
		napping = get_time() - nap_time;
	return (1);
}

int		philo_eat(t_philo *philos)
{
	long int	eat_time;
	long int	eating;

	eat_time = get_time();
	eating = 0;
	if (check_death(philos))
		return(1);
	usleep(100);
	if (!is_dead(philos))
	{
		print_message(philos, "is eating");
		while (eating <= philos->data->philo_eat_time && !(is_dead(philos)))
			eating = get_time() - eat_time;
		philos->last_eaten = get_time();
	}
}