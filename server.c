#include <signal.h>
#include "ft_printf/ft_printf.h"

struct s_server
{
    int bit_count;
    int character;
} g_server = {0, 0};

void process_character(void)
{
    if (g_server.character == '\n')
    {
        ft_printf("\n");
    }
    else
    {
        ft_printf("%c", g_server.character);
    }
    fflush(stdout);
    g_server.character = 0;
    g_server.bit_count = 0;
}

void handle_signal(int signal)
{
    g_server.character <<= 1;
    if (signal == SIGUSR2)
    {
        g_server.character += 1;
    }
    g_server.bit_count++;

    if (g_server.bit_count == 8)
    {
        process_character();
    }
}

int main(void)
{
    struct sigaction sa;

    g_server.bit_count = 0;
    g_server.character = 0;
    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_printf("Server PID: %d\n", getpid());
    while (1)
    {
        pause();
    }
    return (0);
}