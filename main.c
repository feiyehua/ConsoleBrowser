/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-16 16:07:53
 * @LastEditTime : 2024-12-26 20:39:24
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : main.c
 *      © 2024 FeiYehua
 */

#include<stdio.h>
#define bool short
#include"ReadInput.h"
#include"String.h"

int main()
{
    char a[]="ahdhkekjackjhewiuajcjad";
    printf("%s",strSearch(&a[0],getEnd(a),"hke"));
    return 0;
}