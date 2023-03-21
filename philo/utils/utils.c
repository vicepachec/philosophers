/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:36:00 by vpacheco          #+#    #+#             */
/*   Updated: 2023/03/21 17:08:34 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long int	get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}