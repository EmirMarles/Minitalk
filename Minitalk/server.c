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
// server receives 
volatile int received_bits = 0;
volatile unsigned char received_char = 0;

static void ft_receive_bit(int sig);

int main(void)
{
    struct  sigaction sa;
    // if (argc < 1)
    //     return 0;
    sa.sa_handler = ft_receive_bit;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction (SIGUSR1, &sa , NULL);
    sigaction (SIGUSR2, &sa , NULL);

    printf("The process id: %i\n",getpid());
    printf("Waiting for the message...\n");


    while (1)
        pause();
    return (0);
}

// static void ft_signal_handler(int sig,  siginfo_t *info, void * context)
// {
//     printf("the signal %i is received\n", sig);
// }

static void ft_receive_bit(int sig)
{
    received_char = (received_char << 1) | (sig == SIGUSR2);
    received_bits++;

    if (received_bits == 8)
    {
        printf("%c", received_char);
        fflush(stdout);  // Ensure output is printed immediately
        received_bits = 0;
        received_char = 0;
    }
}