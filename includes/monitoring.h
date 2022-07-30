/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:26:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/29 23:30:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <fcntl.h>

# include <defines.h>
# include <structs.h>

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_control	*c(void);
void		initialize_control(int argc, char **argv);

int			argc(void);
char		**argv(void);

bool		help_flag(void);
void		activate_help_flag(void);
bool		simplify_flag(void);
void		activate_simplify_flag(void);

char		*config_path(void);
void		set_config_path(char *path);

int			config_fd(void);
void		open_config(void);
void		close_config(void);

char		*log_path(void);
void		set_log_path(char *path);

int			log_fd(void);
void		open_log(void);
void		close_log(void);

void		close_files(void);

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * FLAGS
\******************************************************************************/

void		handle_flags(void);
void		parse_flags(void);

void		set_simple_flags(char *flag);
bool		is_simple_flag(char *argument);

void		set_file_flags(char **arguments);
bool		is_file_flag(char *arg);

void		help_and_quit(void);
void		simplify_and_quit(void);

/******************************************************************************\
 * CONFIG
\******************************************************************************/

void		handle_config(void);

bool		is_valid_protocol(char *field);

char		*extract_field(char **fields, int index);
char		*get_field(char *protocol, char **fields, int index);

/******************************************************************************\
 * VALIDATORS
\******************************************************************************/

void		validate_fields(char **fields);

void		validate_http(char **fields);
void		validate_ping(char **fields);
void		validate_dns(char **fields);

bool		is_valid_frequency(char *str);

/******************************************************************************\
 * HTTP
\******************************************************************************/

bool		is_http_method(char *field);
bool		is_http_code(char *field);

/******************************************************************************\
 * SHELL
\******************************************************************************/

void		clear(void);

/******************************************************************************\
 * FILES
\******************************************************************************/

int			create_file_or_die(char *path);
int			open_file_or_die(char *path);
int			close_or_die(int close_me);

/******************************************************************************\
 *
\******************************************************************************/

void		quit(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(char *error_message);
void		free_and_die(void *free_me, char *error_message);
void		free_arr_and_die(char **free_me, char *error_message);

#endif
