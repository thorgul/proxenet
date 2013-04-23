#ifndef _CORE_H
#define _CORE_H

#include <semaphore.h>

#include "main.h"
#include "socket.h"
#include "plugin.h"

#define HTTP_TIMEOUT_SOCK 10    /* in seconds, used for select() call in thread */
#define MAX_VERBOSE_LEVEL 4

typedef struct thread_info {
    pthread_t thread_id;
    int thread_num;
    sock_t sock;
    pthread_mutex_t* mutex;
    plugin_t** plugin_list;
} tinfo_t;

enum proxenet_states {
     INACTIVE = 0x00,
     SLEEPING,        // <-- means not to treat new request
     ACTIVE,
};


unsigned short proxenet_state;
unsigned long long active_threads_bitmask;
sem_t tty_semaphore;
plugin_t *plugins_list;  // points to first plugin

int proxenet_start(); 

#endif /* _CORE_H */