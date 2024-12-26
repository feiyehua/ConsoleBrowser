/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-16 16:07:53
 * @LastEditTime : 2024-12-26 23:19:15
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : main.c
 *      © 2024 FeiYehua
 */

#include<stdio.h>
#include"ReadInput.h"
#include"String.h"
#include"Attributes.h"
struct element el;
char *a;
int len;
int main()
{
    freopen("cases/1.in","r",stdin);
    //scanf("%s",a);
    readInput(&len,&a);
    parseBracket(a,getEnd(a),&el);
    //printf("%d",atoi(&a[5]));
    return 0;
}