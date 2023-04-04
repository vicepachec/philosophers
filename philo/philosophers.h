/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:34:33 by vpacheco          #+#    #+#             */
/*   Updated: 2023/04/04 18:14:46 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_data
{
	int	philo_eat_time;
	int	philo_sleep;
	int	philo_die;
	int	num_philos;
	int	philo_think;
	int	must_eat;
	long long int	real_time;
}			t_data;

typedef struct s_dead
{
	int				is_dead;
	pthread_mutex_t death;
}			t_dead;

typedef struct s_philo
{
	int	last_eaten;
	int	sleeping;
	int	has_fork;
	int	philo_index;
	int	times_eaten;
	t_data	*data;
	t_dead	*death;
	pthread_t philo;
}				t_philo;

long int	get_time(void);
void		philo_start(t_data **data);
void		print_message(t_philo *philos, char *str);
int			ft_atoi(const char *str);
int			check_death(t_philo *philos);
int			is_dead(t_philo *philos);
#endif