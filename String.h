/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 18:58:53
 * @LastEditTime : 2024-12-26 19:16:27
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : String.h
 * @     © 2024 FeiYehua
 */
#ifndef __STRING_H__
#define __STRING_H__
#include<string.h>
//查找函数：查找一个字符串中是否有匹配的子串
#define bool short

const char* strSearch(const char* startPtr,const char* endPtr,const char* target);
//在start-end这个左闭右开的区间内查找target字符串
//找到返回目标字符串后一个字符的指针，没有找到返回endPtr
const char* getEnd(const char* str);

#undef bool
#endif