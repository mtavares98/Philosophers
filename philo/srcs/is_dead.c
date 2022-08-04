/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:49:09 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/04 03:09:02 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *p)
{
	pthread_mutex_lock(p->dead);
	if (get_actual_time() - p->time.last_meal >= (t_lu)p->data->time_to_die)
		*(p->is_dead) = 1;
	pthread_mutex_unlock(p->dead);
	return (*(p->is_dead));
}
