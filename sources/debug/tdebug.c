/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdebug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:27:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:47:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

/*
** Behaves like printf but with a "DEBUG: " suffix and an endline.
** Only prints if debug flag is enabled.
** Uses system's printf and derivatives so it's thread safe.
*/
void	tdebug(const char *format, ...)
{
	va_list	ap;

	if (!debug())
		return ;
	fprintf(stdout, "%sDEBUG:%s\t", YB, RC);
	va_start(ap, format);
	vfprintf(stdout, format, ap);
	fprintf(stdout, "\n");
	va_end(ap);
}