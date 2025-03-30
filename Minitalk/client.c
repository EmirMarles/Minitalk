/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:27:26 by emarles           #+#    #+#             */
/*   Updated: 2025/03/29 17:27:26 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//SIGUSR1
//SIGUSR2
static void ft_send_signal(pid_t pid, char *string);
static void ft_send_bit(pid_t pid, unsigned int bit);
static void ft_positive_answer (int sig);

int main(int argc, char*argv[])
{
    pid_t pid;
    if (argc < 3)
    {
        printf("not enough arguments\n");
        return (0);
    }
    pid = ft_atoi(argv[1]);
    printf("the string is %s\n", argv[2]);
    signal(SIGUSR1, ft_positive_answer);
    ft_send_signal(pid, argv[2]);
    return (0);
}

static void ft_positive_answer (int sig)
{
    if (sig == SIGUSR1)
        write(1, "The message has been succesfully sent :D\n", 40);
}

static void ft_send_signal(pid_t pid, char  *string)
{
    int i;
    int j;
    char c;

    i = 0;
    while (string[i] != '\0') // to send the signal
    {
        c = string[i];
        j = 7;
        while (j >= 0)
        {
            ft_send_bit(pid, (c >> j) & 1);
            j--;
        }
        i++;
    }
    c = '\0';
    j = 7;
    while (j >= 0)
    {
        ft_send_bit(pid, (c >> j) & 1);
        j--;
    }
}
static void ft_send_bit(pid_t pid, unsigned int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else 
        kill(pid, SIGUSR2);
    usleep(1);
}