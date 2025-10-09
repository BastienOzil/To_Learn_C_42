
#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

volatile sig_atomic_t timeout_occurred = 0;

void alarm_handler(int sig)
{
    (void)sig;
    timeout_occurred = 1;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t pid;
    int status;
    struct sigaction sa;

    if (f == NULL)
        return -1;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = alarm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) == -1)
        return -1;

    timeout_occurred = 0;

    pid = fork();

    if (pid == -1)
        return -1;

    else if (pid == 0)
    {
        signal(SIGALRM, SIG_DFL);
        f();
        exit(0);
    }
    else
    {
        pid_t result;

        alarm(timeout);
        result = waitpid(pid, &status, 0);
        alarm(0);

        if (result == -1)
            return -1;

        if (timeout_occurred)
        {
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);

            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return 0;
        }

        if (WIFEXITED(status))
        {
            int exit_code = WEXITSTATUS(status);

            if (exit_code == 0)
            {
                if (verbose)
                    printf("Nice function!\n");
                return 1;
            }
            else
            {
                if (verbose)
                    printf("Bad function: exited with code %d\n", exit_code);
                return 0;
            }
        }
        else if (WIFSIGNALED(status))
        {
            int sig = WTERMSIG(status);

            if (verbose)
                printf("Bad function: %s\n", strsignal(sig));
            return 0;
        }
        else if (WIFSTOPPED(status))
        {
            int sig = WSTOPSIG(status);

            if (verbose)
                printf("Bad function: %s\n", strsignal(sig));
            return 0;
        }
    }

    return -1;
}
