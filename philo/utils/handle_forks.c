/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:06:03 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/19 14:35:25 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	available_forks(t_philo *phi, int index)
{
	while (is_alive(phi))
	{
		pthread_mutex_lock(&phi->forks[index].forks);
		if (phi->forks[index].has_fork == 0)
		{
			phi->forks[index].has_fork = 1;
			phi->both_forks += 1;
			print_message(phi, "has taken a fork");
			pthread_mutex_unlock(&phi->forks[index].forks);
			break ;
		}
		else
			pthread_mutex_unlock(&phi->forks[index].forks);
	}
	return (0);
}

int	check_forks(t_philo *phi)
{
	int	left;
	int	right;

	right = phi->philo_index;
	left = phi->philo_index - 1;
	if (right == data_call()->num_philos)
		right = 0;
	phi->right_fork = right;
	phi->left_fork = left;
	if (is_alive(phi))
	{
		available_forks(phi, right);
		available_forks(phi, left);
		if (phi->both_forks == 2)
			philo_eat(phi);
		return (1);
	}
	return (0);
}

void	put_forks(t_philo *phi, int index)
{
	pthread_mutex_lock(&phi->forks[index].forks);
	phi->forks[index].has_fork = 0;
	pthread_mutex_unlock(&phi->forks[index].forks);
}

t_forks	*forks_init(t_data *data)
{
	t_forks	*fork;
	int		i;

	i = -1;
	fork = malloc(sizeof(t_forks) * (data->num_philos));
	if (!fork)
		return (NULL);
	pthread_mutex_init(&fork->print, NULL);
	while (++i < data->num_philos)
	{
		fork[i].print = fork[0].print;
		fork[i].has_fork = 0;
		pthread_mutex_init(&fork[i].forks, NULL);
	}
	return (fork);
}
