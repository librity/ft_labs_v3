/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/03 01:59:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	run_log(void)
{
	while (true)
		handle_key();
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	run_log();
	exit(EXIT_SUCCESS);
}
