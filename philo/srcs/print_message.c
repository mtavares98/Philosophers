/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:21:20 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/09 17:03:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_two_messages(t_philo *p)
{
	pthread_mutex_lock(p->print);
	printf("%lu %i %s\n", \
	time_diff(p->t->start, current_time()), p->id, "has taken a fork");
	printf("%lu %i %s\n", \
	time_diff(p->t->start, current_time()), p->id, "is eating");
	pthread_mutex_unlock(p->print);
	p->last_meal = current_time();
}

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(p->print);
	printf("%lu %i %s\n", \
	time_diff(p->t->start, current_time()), p->id, str);
	pthread_mutex_unlock(p->print);
}
