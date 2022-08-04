/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:21:01 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/04 03:04:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_lu	time_diff(t_lu	start, t_lu end)
{
	return (end - start);
}

t_lu	get_time(t_philo *p, int is_eating)
{
	t_timeval	c_t;
	t_lu		ct;

	gettimeofday(&c_t, NULL);
	ct = c_t.tv_sec * 1000 + c_t.tv_usec / 1000 \
		- p->time.last_meal;
	if (is_eating)
	{
		p->time.last_meal = ct;
		p->time.last_action = p->time.last_meal;
	}
	else
		p->time.last_action = ct;
	return (ct);
}

t_lu	get_actual_time(void)
{
	t_timeval	c_t;

	gettimeofday(&c_t, NULL);
	return (c_t.tv_sec * 1000 + c_t.tv_usec / 1000);
}
