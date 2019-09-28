#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//Almicke Navarro
//CST221
//September 27, 2019
//This is my own take on the Week 5 DQ created by Michael Landreth

//make x a global variable
int x;

/**
 * Thread 1 function.
 *
 * @param a Not used.
 * @return Always null.
 */
void *thread1(void *a)
{
    //change to a while loop so that we would still repeat the actions below until x reaches 9
    while(x < 10)
    {
        // Print a message to the console, increment x, and sleep for awhile
        printf("This is Thread 1 ..... %d\n", x);
        x++;
        sleep(1);
    }
    return NULL;
}

/**
 * Thread 2 function.
 *
 * @param a Not used.
 * @return Always null.
 */
void *thread2(void *a)
{
    //change to a while loop so that we would still repeat the actions below until x reaches 19
    while(x < 20)
    {
        // Print a message to the console, increment x, and sleep for awhile
        printf("This is Thread 2 ..... %d\n", x);
        x++;
        sleep(2);
    }
    return NULL;
}

/**
 * Main application entry point to create some threads.
 *
 * @return 1 if error or 0 if OK returned to code the caller.
 */
int main()
{
    pthread_t tid1, tid2;

    //create the first thread for the 1st process
    if(pthread_create(&tid1, NULL, thread1, NULL))
    {
        printf("\n ERROR creating thread 1");
        exit(1);
    }
    
    //wait for this thread to terminate
    if(pthread_join(tid1, NULL))
    {
        printf("\n ERROR joining thread 1");
        exit(1);
    }
    
    //create another new thread for the 2nd process to be called after the 1st thread terminates
    if(pthread_create(&tid2, NULL, thread2, NULL))
    {
        printf("\n ERROR creating thread 2");
        exit(1);
    }
    
    //wait for this thread to terminate
    if(pthread_join(tid2, NULL))
    {
        printf("\n ERROR joining thread 2");
        exit(1);
    }

    // Thread creation cleanup
    pthread_exit(NULL);
}


