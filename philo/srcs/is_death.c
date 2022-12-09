/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:42:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/09 16:46:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_death(t_philo *p)
{
	int	death;

	pthread_mutex_lock(&p->death->death);
	death = p->death->is_death;
	pthread_mutex_unlock(&p->death->death);
	return (death);
}

int	is_dead(t_philo *p)
{
	if (check_death(p))
		return (1);
	if (time_diff(p->last_meal, current_time() - p->t->start) \
	>= (t_lu)p->data.time_to_die)
	{
		pthread_mutex_lock(&p->death->death);
		p->death->is_death++;
		if (p->death->is_death == 1)
			print_message(p, "died");
		pthread_mutex_unlock(&p->death->death);
		return (1);
	}
	return (0);
}
