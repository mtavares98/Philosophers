/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:04:04 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/11 22:22:23 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef unsigned long		t_lu;
typedef struct s_data		t_data;
typedef struct s_table		t_table;
typedef struct s_death		t_death;
typedef struct s_time		t_time;
typedef struct s_philo		t_philo;

struct s_death
{
	int				*is_death;
	pthread_mutex_t	*death;
};

struct s_data
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	have_last_arg;
	int	num_time_to_eat;
};

struct s_time
{
	t_lu	start;
	t_lu	last_action;
	t_lu	last_meal;
};

struct s_table
{
	int				have_fork;
	pthread_mutex_t	mutex_fork;
};

struct s_philo
{
	int				id;
	int				num_time_eaten;
	pthread_t		philo;
	pthread_mutex_t	*print;
	t_death			*death;
	t_data			data;
	t_table			*table;
};

void	exit_free(t_table **table, t_philo **philo, int i, char *str);
int		is_dead(t_philo *p, t_time *t);
t_lu	current_time(void);
t_lu	time_diff(t_lu start, t_lu last_action);
void	print_message(t_philo *p, t_time *t, char *str, int is_eating);
void	eat(t_philo *p, t_time *t);
int		have_last_arg(int ac);
t_death	*init_death(void);
t_data	intit_data(int ac, char **av);
t_table	*init_table(t_data *data);
t_philo	*init_philo(t_data *data, t_table **table, t_death *death);
void	thread_creation(t_philo **philo);
int		ft_atoi(char *str);

#endif
