/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:02:33 by emarles           #+#    #+#             */
/*   Updated: 2025/03/02 15:20:26 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//SIGUSR1
//SIGUSR2
static void ft_send_signal(pid_t pid, unsigned char c);
static void ft_send_bit(pid_t pid, unsigned int bit);

int main(int argc, char*argv[])
{
    pid_t pid;
    int i;
    char *string;
    char c;
    if (argc < 3)
        printf("not enough arguments\n");
    else
    {
        pid = ft_atoi(argv[1]);
        string = ft_strdup(argv[2]);
        printf("the string is %s\n", string);
        i = 0;
        while (string[i] != '\0') // to send the signal
        {
            c = string[i];
            ft_send_signal(pid, c);
            i++;
            usleep(42);
        }
        free(string);
    }
    return (0);
}

static void ft_send_signal(pid_t pid, unsigned char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        ft_send_bit(pid, (c >> i) & 1);
        i--;
    }
}
static void ft_send_bit(pid_t pid, unsigned int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else 
        kill(pid, SIGUSR2);
    usleep(10000);
}