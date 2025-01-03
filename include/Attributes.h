/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 11:01:33
 * @LastEditTime : 2024-12-27 18:40:25
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
#include"StringOperations.h"
typedef enum NAME{
    HEADING,PARAGARPH,IMAGE,DIV
}NAME;
typedef enum COLOR{
    BLACK,RED,BLUE,GREEN
}COLOR;
typedef enum DIRECTION{
    ROW,COLUMN
}DIRECTION;
typedef enum ALIGN{
    START,END,CENTER,SPACE_EVENLY
}ALIGN;
typedef struct ImageInfo{
    size_t width;
    const char* str;
    size_t length;
}ImageInfo;
typedef struct element{
    COLOR color;
    NAME name;
    DIRECTION direction;
    ALIGN align;
    ALIGN justify;
    bool em;
    bool i;
    bool u;
    int w;
    int h;
    int contentWidth;
    int contentHeight;
    //int endDiv;
    struct element* endDiv;
    const char* content;
    size_t length;
    ImageInfo imgaeInfo;
}element;
bool checkEnd(const char* startStr,const char* endStr);

int parseBracket(const char* startStr,const char* endStr,struct element* attribute);
//解析括号里的字符、属性
//传入参数为<后第一个字符和>位置的指针，一样是左闭右开
void inheritAttribute(element* dest,const element* src);
//更新Div中元素的属性。
//包含Div本身，区间为start-end的闭区间
void updateDiv(element* el,int start,int end);

#endif