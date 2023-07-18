/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:10:24 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/18 20:25:34 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void parse_philo(int ac, char **av)
{	
	data_call()->num_philos = ft_atoi(av[1]);
	data_call()->philo_die	= ft_atoi(av[2]);
	data_call()->philo_eat_time = ft_atoi(av[3]);
	data_call()->philo_sleep = ft_atoi (av[4]);
	if (ac == 6)
	{
		data_call()->must_eat = ft_atoi (av[5]);
		if (data_call()->must_eat <= 0)
		{
			printf("Error\n");
			return;
		}
	}
	if (data_call()->num_philos <= 0 || data_call()->philo_die <= 0 || data_call()->philo_eat_time <= 0 || \
		data_call()->philo_sleep <= 0)
		{
			printf("Error\n");
			return;
		}
	philo_start();
}

void	philo_start(void)
{
	int		i;
	t_forks	*forks;
	t_philo	*philo;

	i = -1;
	data_call()->start = get_time();
	pthread_mutex_init(&dead_call()->death, NULL);
	philo = new_philos(data_call());
	forks = forks_init(data_call());
	if (!philo || !forks)
		return (free_all(forks, philo));
	while (++i < data_call()->num_philos)
		philo[i].forks = forks;
	i = -1;
	while (++i < data_call()->num_philos)
		pthread_create(&philo[i].philo, NULL, philo_jobs, (void *)&philo[i]);
	while (--i > -1)
		pthread_join(philo[i].philo, NULL);
	free(philo);
	i = -1;
	while (++i < data_call()->num_philos)
		pthread_mutex_destroy(&forks[i].forks);
	free(forks);
	return ;
}

t_philo	*new_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = malloc(sizeof(t_philo) * (data_call()->num_philos));
	if (!philos)
		return (NULL);
	while (++i < data->num_philos)
	{
		philos[i].data = data_call();
		philos[i].philo_index = i + 1;
		philos[i].last_eaten = 0;
		philos[i].sleeping = 0;
		philos[i].times_eaten = 0;
		philos[i].both_forks = 0;
	}
	return (philos);
}