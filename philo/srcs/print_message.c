/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:21:20 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/30 18:07:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(t_philo *p, char *str, int is_eating)
{
	t_lu	diff;

	p->last_action = current_time();
	if (is_eating)
		p->last_meal = p->last_action;
	if (pthread_mutex_lock(p->print) != 0)
		return ;
	diff = time_diff(p->t->start, current_time());
	printf("%lums philo %i %s\n", diff, p->id, str);
	if (pthread_mutex_unlock(p->print) != 0)
		return ;
}
