/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:21:20 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/08 17:28:09 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_debug(t_philo *p)
{
	pthread_mutex_lock(p->print);
	printf("%lu %i num_eaten: %i\n", \
	time_diff(p->t->start, current_time()), p->id + 1, p->num_time_eaten);
	pthread_mutex_unlock(p->print);
}

void	print_two_messages(t_philo *p)
{
	pthread_mutex_lock(p->print);
	printf("%lu %i %s\n", \
	time_diff(p->t->start, current_time()), p->id + 1, "has taken a fork");
	printf("%lu %i %s\n", \
	time_diff(p->t->start, current_time()), p->id + 1, "is eating");
	pthread_mutex_unlock(p->print);
	p->last_meal = current_time();
}

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(p->print);
	printf("%lu %i %s\n", \
	time_diff(p->t->start, current_time()), p->id + 1, str);
	pthread_mutex_unlock(p->print);
}
