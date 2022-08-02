/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 17:40:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	initialize_mutex(t_tmutex *mutex)
{
	int	result;

	result = pthread_mutex_init(mutex, NULL);
	if (result != 0)
		tdie(THRD_MUTEX_INIT_ERR);
}

void	destroy_mutex(t_tmutex *mutex)
{
	int	result;

	result = pthread_mutex_destroy(mutex);
	if (result != 0)
		tdie(THRD_MUTEX_DESTROY_ERR);
}