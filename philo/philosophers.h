/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:34:33 by vpacheco          #+#    #+#             */
/*   Updated: 2023/03/21 17:09:09 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data
{
	int	philo_eat_time;
	int	philo_sleep;
	int	philo_die;
	int	philo_think;
	int	times_eaten;
	int	philo_number;
	long long int	real_time;
}			t_data;

#endif