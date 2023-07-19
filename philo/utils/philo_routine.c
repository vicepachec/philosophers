/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:19:57 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/18 23:16:01 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int		philo_sleep(t_philo *philos)
{
	long int	nap_time;
	long int	napping;
	
	nap_time = get_time();
	napping = 0;
	if (check_death())
		return(0);
	print_message(philos, "is sleeping");
	usleep(100);
	while (napping <= data_call()->philo_sleep)
		napping = get_time() - nap_time;
	return (1);
}

int		philo_eat(t_philo *philos)
{
	long int	eat_time;
	long int	eating;

	eat_time = get_time();
	eating = 0;
	if (check_death())
		return(0);
	usleep(100);
	if (is_alive(philos))
	{
		print_message(philos, "is eating");
		while (eating <= data_call()->philo_eat_time && is_alive(philos))
			eating = get_time() - eat_time;
		philos->last_eaten = get_time();
		put_forks(philos, philos->right_fork);
		put_forks(philos, philos->left_fork);
		philos->both_forks = 0;
		philos->times_eaten++;
	}
	return(1);
}

void *philo_jobs(void *arg)
{
	t_philo *philos;
	
	philos = (t_philo *)arg;
	philos->last_eaten = data_call()->start;
	if (!(philos->philo_index % 2))
			usleep(10000);
	while (is_alive(philos))
	{
		check_forks(philos);
		if (philos->times_eaten == data_call()->must_eat || !(is_alive(philos)))
			break;
		philo_sleep(philos);
		if (!check_death())
			print_message(philos, "is thinking");
		if (data_call()->num_philos % 2)
			usleep(2000);
	}
	return(NULL);
}