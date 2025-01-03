/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 18:58:47
 * @LastEditTime : 2024-12-26 23:15:33
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : String.c
 *      © 2024 FeiYehua
 */
//c库函数里面的String操作函数太难用了！
//我要用迭代器思维重写一遍！
#include"StringOperations.h"
const char* strSearch(const char* startPtr,const char* endPtr,const char* target)
{
    const char* cur=startPtr;
    do
    {
        if(*cur==*target)
        {
            if(memcmp(cur,target,strlen(target))==0)
            {
                return cur+strlen(target);
            }
        }
        cur++;
    }while(cur!=endPtr);
    return NULL;
}

const char* getEnd(const char* str)
{
    char *cur=(char*)str;
    while(*cur!='\0')
    {
        cur++;
    }
    return cur;
}
