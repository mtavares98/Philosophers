/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:42:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/05 18:17:48 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *p)
{
	int	death;

	death = 0;
	if (time_diff(p->last_meal, current_time()) >= (t_lu)p->data.time_to_die \
	|| ((p->num_time_eaten == p->data.num_time_to_eat) \
	&& (p->data.have_last_arg)))
	{
		death = 1;
		pthread_mutex_lock(&p->death->death);
		if (!p->death->is_death)
		{
			p->death->is_death = 1;
			pthread_mutex_unlock(&p->death->death);
			if (time_diff(p->last_meal, current_time()) >= \
			(t_lu)p->data.time_to_die)
				print_message(p, "is dead", 0);
		}
		else
			pthread_mutex_unlock(&p->death->death);
	}
	else
	{
		pthread_mutex_lock(&p->death->death);
		death = p->death->is_death;
		pthread_mutex_unlock(&p->death->death);
	}
	return (death);
}
