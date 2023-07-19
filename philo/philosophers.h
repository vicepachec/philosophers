/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:34:33 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/19 14:35:31 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data		t_data;
typedef struct s_dead		t_dead;
typedef struct s_forks		t_forks;
typedef struct s_philo		t_philo;
typedef struct s_message	t_message;

struct s_data
{
	int			philo_eat_time;
	int			philo_sleep;
	int			philo_die;
	int			num_philos;
	int			philo_think;
	int			must_eat;
	long int	start;
	t_forks		*forks;
};

struct s_dead
{
	int				is_dead;
	pthread_mutex_t	death;
};

struct s_forks
{
	int				has_fork;
	pthread_mutex_t	forks;
	pthread_mutex_t	print; 
};

struct s_philo
{
	long int	last_eaten;
	long int	sleeping;
	int			left_fork;
	int			right_fork;
	int			both_forks;
	int			philo_index;
	int			times_eaten;
	pthread_t	philo;
	t_data		*data;
	t_dead		*dead;
	t_forks		*forks;
};

long int	get_time(void);
void		philo_start(t_data *data);
void		print_message(t_philo *philos, char *str);
int			ft_atoi(const char *str);
int			check_death(void);
int			is_alive(t_philo *philos);
int			philo_eat(t_philo *philos);
void		put_forks(t_philo *phi, int index);
t_forks		*forks_init(t_data *data);
void		free_all(t_forks *forks, t_philo *philos);
void		parse_philo(int ac, char **av);
int			check_forks(t_philo *phi);
void		*philo_jobs(void *arg);
t_philo		*new_philos(t_data *data);
t_dead		*dead_call(void);
t_data		*data_call(void);
int			available_forks(t_philo *philo, int index);
int			philo_sleep(t_philo *philos);
#endif