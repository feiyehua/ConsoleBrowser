/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 15:36:54
 * @LastEditTime : 2024-12-27 17:38:08
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Array.h
 * @     © 2024 FeiYehua
 */
#ifndef __ARRAY_H__
#define __ARRAY_H__
#include<stdlib.h>
#include"Attributes.h"
typedef struct OutputArray{
    element* el;
    char c;
}OutputArray;
//分配一个m*n的输出内容数组
OutputArray** allocateArray(int m,int n);
void freeArray(OutputArray** loc,int m,int n);

#endif