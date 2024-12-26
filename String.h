/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 18:58:53
 * @LastEditTime : 2024-12-26 21:12:35
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : String.h
 * @     © 2024 FeiYehua
 */
#ifndef __STRING_H__
#define __STRING_H__
#include<string.h>
//查找函数：查找一个字符串中是否有匹配的子串

char* strSearch(const char* startPtr,const char* endPtr,const char* target);
//在start-end这个左闭右开的区间内查找target字符串
//找到返回目标字符串后一个字符的指针，没有找到返回endPtr
//这样设计的话，没有找到和其正好在最后一个位置没有区别。
//还是返回目标字符串第一个字符的指针吧。
const char* getEnd(const char* str);
const char* getValue();
#endif