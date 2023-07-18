/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:01:22 by vpacheco          #+#    #+#             */
/*   Updated: 2023/07/18 16:47:48 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main (int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("Error\n"));
	parse_philo(ac, av);
	return(1);
}