/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 11:01:33
 * @LastEditTime : 2024-12-26 11:37:00
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Attributes.h
 * @     © 2024 FeiYehua
 */
#ifndef __ATTRIBUTES_H__
#define __ATTRIBUTES_H__
#define bool short
#include<string.h>
typedef enum ELEMENT{
    HEADING,PARAGARPH,IMAGE,DIV
}ELEMENT;
typedef enum COLOR{
    RED,BLUE,GREEN
}COLOR;
typedef enum DIRECTION{
    ROW,COLUMN
}DIRECTION;
typedef enum ALIN{
    START,END,CENTER,SPACE_EVENLY
}ALIN;
struct attribute{
    COLOR color;
    ELEMENT element;
    bool em;
    bool i;
    bool u;
    int w;
    int h;
    char src[100];
    int width;
};
int getAttribute(char* str,struct attribute** attribute);
//解析字符串，获取attribute
int checkEnd(char* startStr,char* endStr);
//检查一个括号内是否有/
void getElement(char** strPtr,const char* endPtr,ELEMENT* element)
//解析一个元素的元素名
int parseBracket(char* startStr,const char* endStr,struct attribute* attribute);
//解析括号里的字符、属性
#undef bool
#endif