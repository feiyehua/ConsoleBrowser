/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-16 16:07:53
 * @LastEditTime : 2024-12-27 15:22:50
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : main.c
 *      © 2024 FeiYehua
 */

#include<stdio.h>
#include"ReadInput.h"
#include"StringOperations.h"
#include"Attributes.h"
#include"InputParser.h"
#include"Stack.h"
const int screenHeight=10;
const int screenWidth=50;
struct element el[1000];
char *a;
int len;
Stack stack={0,NULL};
int main()
{
    el[0].h=screenHeight;
    el[0].w=screenWidth;
    el[0].name=DIV;
    stackPush(&stack,0);
    freopen("cases/1.in","r",stdin);
    readInput(&len,&a);
    parseInput(a,el,&stack);
    return 0;
}