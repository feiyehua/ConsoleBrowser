/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 11:01:33
 * @LastEditTime : 2024-12-26 22:39:30
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Attributes.h
 * @     © 2024 FeiYehua
 */
#ifndef __ATTRIBUTES_H__
#define __ATTRIBUTES_H__

#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include"String.h"
typedef enum NAME{
    HEADING,PARAGARPH,IMAGE,DIV
}NAME;
typedef enum COLOR{
    RED,BLUE,GREEN
}COLOR;
typedef enum DIRECTION{
    ROW,COLUMN
}DIRECTION;
typedef enum ALIGN{
    START,END,CENTER,SPACE_EVENLY
}ALIGN;
struct element{
    COLOR color;
    NAME name;
    DIRECTION direction;
    ALIGN align;
    bool em;
    bool i;
    bool u;
    int w;
    int h;
    char src[100];
    int width;
};
int getAttribute(char** strPtr,const char* endPtr,struct element* element);
//解析字符串，获取attribute
int checkEnd(char* startStr,char* endStr);
//检查一个括号内是否有/
int getElementName(char** strPtr,const char* endPtr,NAME* name);
//解析一个元素的元素名

//如果尖括号内还有其他属性，则返回0，strPtr修改到第一个属性的起始位置；
//如果尖括号内没有其他属性，则返回1，strPtr修改到尖括号末
int parseBracket(char* startStr,const char* endStr,struct element* attribute);
//解析括号里的字符、属性
#undef bool
#endif