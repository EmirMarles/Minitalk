/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:27:58 by emarles           #+#    #+#             */
/*   Updated: 2025/03/29 17:27:58 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef minitalk_h
#define minitalk_h

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
// #include <sys/wait.h>
// utils
int ft_atoi(const char *str);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);

#endif