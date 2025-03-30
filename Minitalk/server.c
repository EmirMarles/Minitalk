/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:27:49 by emarles           #+#    #+#             */
/*   Updated: 2025/03/29 17:27:49 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void ft_receive_bit(int sig, siginfo_t *info, void* context)
{
    static unsigned char received_char = 0;
    static unsigned int received_bits = 0;
    int pid = 0;
    (void)context;
    if (!pid)
        pid = info->si_pid;
    received_char = (received_char << 1) | (sig == SIGUSR2);// sets the received bit to 1 if SIGUSR2 or to 0 if SIGUSR1
    received_bits++;
    if (received_bits == 8)
    {
        write(1, &received_char, 1);
        if (received_char == '\0')
        {

            write(1, "\nThe message has been fully received\n", 38);
            kill(pid, SIGUSR1);
            pid = 0;
        }
        received_bits = 0;
        received_char = 0;
    }
}
int main(void)
{
    struct  sigaction sa;
    pid_t   pid;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_receive_bit;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa , NULL); // how a proccess should handle a new signal
    sigaction(SIGUSR2, &sa , NULL);//(1st is the signal, 2nd is the pointer to a sig struct , 4rd where the old sig info should be saved)

    pid = getpid();
    printf("The process id: %i\n", pid);
    printf("Waiting for the message...\n");

    while (1)
    pause();
    return (0);
}