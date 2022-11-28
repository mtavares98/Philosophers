/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:42:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/28 16:27:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *p, t_time *t)
{
	int	death;

	death = 0;
	if (time_diff(t->last_meal, current_time()) >= (t_lu)p->data.time_to_die)
	{
		pthread_mutex_lock(p->death->death);
		death = 1;
		if (!*p->death->is_death)
		{
			*p->death->is_death = death;
			print_message(p, t, "is dead", 0);
		}
		pthread_mutex_unlock(p->death->death);
	}
	return (death);
}
