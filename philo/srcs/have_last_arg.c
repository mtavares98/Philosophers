/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_last_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:29:02 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/23 22:33:04 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_num_times_to_eat(t_gen gen)
{
	if (!gen.have_last_arg)
		return (1);
	else if (!gen.num_time_to_eat)
		return (0);
	return (1);
}
