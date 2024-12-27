/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 18:58:53
 * @LastEditTime : 2024-12-27 17:45:30
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : StringOperations.h
 * @     © 2024 FeiYehua
 */
#ifndef __STRINGOPERATIONS_H__
#define __STRINGOPERATIONS_H__
#include<string.h>
//查找函数：查找一个字符串中是否有匹配的子串
//在start-end这个左闭右开的区间内查找target字符串
//找到返回目标字符串后一个字符的指针，没有找到返回NULL
const char* strSearch(const char* startPtr,const char* endPtr,const char* target);
//返回\0字符的指针
const char* getEnd(const char* str);
const char* getValue();
#endif