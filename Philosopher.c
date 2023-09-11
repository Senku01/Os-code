#include<stdio.h>

typedef int semaphore;
semaphore chopstick[5];

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return(++s);
}

void check(int i)
{
    if(chopstick[i]!=0 && chopstick[(i+1)%5]!=0)
    {
        printf("\n\tPhilosopher %d can eat",i);
    }
}

void philosopher(int i)
{
    check(i);
    wait(chopstick[i]);
    wait(chopstick[i+1]%5);
    printf("\n\tEating in process....");
    signal(chopstick[i]);
    signal(chopstick[i+1]%5);
    printf("\n\tPhilosopher %d completed its works\n",i);
}

int main()
{
    for(int i=1;i<=5;i++)
    {
        chopstick[i]=1;
    }

    printf("\n\t\tDining Philosopher Problem");
    printf("\n\t\t..........................");

    for(int i=1;i<=5;i++)
    {
        printf("\n\nPhilosopher %d falls hungry",i);
        philosopher(i);
    }
}
