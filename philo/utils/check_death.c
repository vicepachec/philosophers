/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:51:13 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/18 21:51:26 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_death(void)
{
	int		death;

	pthread_mutex_lock(&dead_call()->death);
	death = dead_call()->is_dead;
	pthread_mutex_unlock(&dead_call()->death);
	if (death)
		return(1);
	return (0);
}

int	is_alive(t_philo *philos)
{
	long int	last_eaten;

	if (check_death())
		return (0);
	last_eaten = get_time() - philos->last_eaten;
	if (last_eaten >= philos->data->philo_die)
		{
			pthread_mutex_lock(&dead_call()->death);
			dead_call()->is_dead++;
			if (dead_call()->is_dead == 1)
				print_message(philos ,"died");
			pthread_mutex_unlock(&dead_call()->death);
			return (0);
		}
	return (1);
	
}