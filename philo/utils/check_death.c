/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:51:13 by vpacheco          #+#    #+#             */
/*   Updated: 2023/04/04 17:24:54 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_death(t_philo *philos)
{
	int		death;

	pthread_mutex_lock(&philos->death->death);
	death = philos->death->is_dead;
	pthread_mutex_unlock(&philos->death->death);
	return (death);
}

int	is_dead(t_philo *philos)
{
	long int	last;

	if (check_death(philos))
		return (1);
	last = get_time() - philos->last_eaten;
	if (last >= philos->data->philo_die)
		{
			pthread_mutex_lock(&philos->death->death);
			philos->death->is_dead++;
			if (philos->death->is_dead = 1);
				print_message(philos ,"died");
			pthread_mutex_unlock(&philos->death->death);
			return (1);
		}
	return (0);
	
}