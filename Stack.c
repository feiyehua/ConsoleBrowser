/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 12:29:12
 * @LastEditTime : 2024-12-27 12:41:54
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Stack.c
 *      © 2024 FeiYehua
 */
#include"Stack.h"
void stackPush(Stack* stack,int content)
{
    __StackNode__* newTop=(__StackNode__*)malloc(sizeof(__StackNode__));
    newTop->start=content;
    newTop->last=stack->top;
    stack->top=newTop;
}
void stackPop(Stack* stack)
{
    __StackNode__* _t=stack->top;
    stack->top=stack->top->last;
    free(_t);
    return;
}
int stackTop(Stack* stack)
{
    return stack->top->start;
}