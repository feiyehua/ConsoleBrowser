/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 12:29:26
 * @LastEditTime : 2024-12-27 12:35:26
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Stack.h
 * @     © 2024 FeiYehua
 */
#ifndef __STACK_H__
#define __STACK_H__
#include<stdlib.h>
//栈节点实现
typedef struct __StackNode__{
    struct __StackNode__* last;
    int start;
}__StackNode__;
//栈实现
typedef struct Stack{
    int cnt;
    __StackNode__* top;
}Stack;
void stackPush(Stack* stack,int content);
void stackPop(Stack* stack);
int stackTop(Stack* stack);
#endif