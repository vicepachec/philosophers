/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:10:24 by vpacheco          #+#    #+#             */
/*   Updated: 2023/04/04 17:19:41 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_start(t_data **data)
{
	int i;
	t_philo *philo;
	
	i = -1;
	(*data)->real_time = get_time();
	philo = new_philos(data);
	while (++i < (*data)->num_philos)
	{
		pthread_create(&philo[i].philo, NULL, philo_routine, void*);
	}
}

t_philo	*new_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = malloc(sizeof(t_data) * ((*data).num_philos));
	if (!philos)
		return (NULL);
	while (++i < data->num_philos)
	{
		philos[i].data = data;
		philos[i].philo_index = i + 1;
		philos[i].last_eaten = 0;
		philos[i].sleeping = 0;
		philos[i].times_eaten = 0;
		philos[i].has_fork = 0;
	}
	return (philos);
}