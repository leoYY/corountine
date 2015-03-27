// Copyright (c) 2015 Baidu.com , Inc. All Rights Reserved
// @author: yuanyi (yuan.yi.coding@gmail.com)
// @brief : 

#ifndef _COROUTINE_H_
#define _COROUTINE_H_

#define DEFAULT_STACK_SIZE (8 * 1024 * 1024)

typedef void (*coroutine(void)) CoroutineFunc

enum CoroutineState {
    READY = 0,
    RUNNING,
    SUSPENDED,
    FINISH
};

struct CoroutineContext;

struct Scheduler {
    char stack[DEFAULT_STACK_SIZE];
    ucontext_t main;
    int next_id;
    int cap;
    CoroutineContext **coroutines; 
};

struct CoroutineContext {
    size_t stack_size;
    void* ud;
    Scheduler* scheduler;
    int id;
    char* stack;
}

#endif

