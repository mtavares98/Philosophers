/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:29:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/23 21:16:22 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_lu	get_time(t_lu start)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		exit(1);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - start);
}
