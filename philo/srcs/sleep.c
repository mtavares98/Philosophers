/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:58:30 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/29 18:42:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	sleep_action(t_lu action, t_philo *p)
{
	t_lu	begin;
	t_lu	passed;

	begin = current_time();
	passed = 0;
	while (!is_dead(p) && passed < action)
	{
		if (check_death(p))
			return (1);
		usleep(100);
		passed = time_diff(begin, current_time());
	}
	return (passed >= action);
}
