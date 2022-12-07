/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:58:30 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/07 16:13:30 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleep_action(t_lu action, t_philo *p)
{
	t_lu	begin;
	t_lu	passed;

	begin = current_time();
	passed = 0;
	while (!is_dead(p) && passed < action)
	{
		usleep(100);
		passed = time_diff(begin, current_time());
	}
}
