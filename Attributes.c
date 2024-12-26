/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 11:01:27
 * @LastEditTime : 2024-12-26 18:53:36
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Attributes.c
 *      © 2024 FeiYehua
 */

#include"Attributes.h"
#define bool short
int checkEnd(char* startStr,char* endStr)
{
    for(;startStr<=endStr;startStr++)
    {
        if(*startStr=='/')
        {
            return 1;
        }
    }
    return 0;
}
// void jumpToNextWord(char** strPtr,const char* endPtr)
// {
//     while(**strPtr!=' '&&*strPtr<endPtr)
//     {
//         (*strPtr)++;
//     }
//     (*strPtr)++;
//     //找下一个单词，如果没有找到，则将*strPtr修改为endPtr+1.
// }
//这个函数用strchr函数替代。
int editStrPtr(char** strPtr)//修改下一次搜索的起始位置
{
    if(strchr(*strPtr,' ')==NULL)
    {
        *strPtr=strchr(*strPtr,'>')+1;//没有其他属性
        return 1;
    }
    else
    {
        *strPtr=strchr(*strPtr,' ')+1;
        return 0;
    }
}
int getElementName(char** strPtr,const char* endPtr,NAME* name)
{
    switch(**strPtr)
    {
        case 'h':
        {
            *name=HEADING;
            break;
        }
        case 'p':
        {
            *name=PARAGARPH;
            break;
        }
        case 'i':
        {
            *name=IMAGE;
            break;
        }
        case 'd':
        {
            *name=DIV;
            break;
        }
        default:
        {
            break;
        }
    }
    //jumpToNextWord(strPtr,endPtr);
    return editStrPtr(strPtr);
}
int getAttribute(char** strPtr,const char* endPtr,struct element* element)
{
    
    return editStrPtr(strPtr);
}
int parseBracket(char* startStr,const char* endStr,struct element* element)
{
    //属性名：h，p，img，div
    getElementName(&startStr,endStr,&(element->name));//修改attribute的element值
    while(startStr<=endStr)
    {
        if(getAttribute(&startStr,endStr,element)==1)
        {
            break;
        }
    }
    return 0;
}

#undef bool