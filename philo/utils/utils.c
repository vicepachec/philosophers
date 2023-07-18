/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:36:00 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/18 18:52:05 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long int	get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_philo *philos, char *str)
{
	printf("%ldms philo%i %s\n", get_time() - \
			philos->data->start, philos->philo_index, str);
	return ;
}

void free_all(t_forks *forks, t_philo *philos)
{
	int i;
	static t_data *data;
	
	i = -1;
	if (forks)
	{
		while (++ i < data->num_philos)
			pthread_mutex_destroy(&forks[i].forks);
		free(data->forks);
	}
	free(forks);
	free(philos);
}

t_dead *dead_call(void)
{
	static t_dead	death;
	return(&death);
}

t_data *data_call(void)
{
	static t_data data;
	return (&data);
}