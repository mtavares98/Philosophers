/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:21:20 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/28 17:24:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(t_philo *p, t_time *t, char *str, int is_eating)
{
	t_lu	diff;

	t->last_action = current_time();
	if (is_eating)
		t->last_meal = t->last_action;
	diff = time_diff(t->start, current_time());
	printf("%lums philo %i %s\n", diff, p->id, str);
}
