#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * PrintHello(void*ptr);
 pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

int main()
{          
	   pthread_t thread1, thread2;
           const char *message1= "Thread1";
           const char *message2= "Thread2";
             pthread_create(&thread1,NULL, PrintHello,(void*) message1);
              pthread_create(&thread2,NULL, PrintHello, (void*) message2) ; 
                 
                 pthread_join(thread1,NULL);
 printf("deadlock starts here!!\n");
                   pthread_join(thread2,NULL);
                   pthread_join(thread1,NULL);
                                      
               
}


void * PrintHello(void*ptr)
{  
  pthread_mutex_lock( &mutex1 );
   char*message;
     message= (char*) ptr;
       printf("Hello World! I am first locker, %s\n",message);
}
