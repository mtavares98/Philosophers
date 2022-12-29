/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:47:08 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/29 18:42:26 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_lu	current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

t_lu	time_diff(t_lu start, t_lu last_action)
{
	return (last_action - start);
}
