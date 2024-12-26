/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 11:01:27
 * @LastEditTime : 2024-12-26 11:42:45
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Attributes.c
 *      © 2024 FeiYehua
 */

#include"Attributes.h"
#define bool short
int getAttribute(char* str,struct attribute* attribute)
{
    
    
}
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
void jumpToNextWord(char** strPtr,const char* endPtr)
{
    while(**strPtr!=' '&&*strPtr<endPtr)
    {
        (*strPtr)++;
    }
    (*strPtr)++;
    //找下一个单词，如果没有找到，则将*strPtr修改为endPtr+1.
}

void getElement(char** strPtr,const char* endPtr,ELEMENT* element)
{
    switch(**strPtr)
    {
        case 'h':
        {
            *element=HEADING;
            break;
        }
        case 'p':
        {
            *element=PARAGARPH;
            break;
        }
        case 'i':
        {
            *element=IMAGE;
            break;
        }
        case 'd':
        {
            *element=DIV;
            break;
        }
        default:
        {
            break;
        }
    }
    jumpToNextWord(strPtr,endPtr);
}
int parseBracket(char* startStr,const char* endStr,struct attribute* attribute)
{
    //属性名：h，p，img，div
    getElement(&startStr,endStr,&(attribute->element));//修改attribute的element值
    
}

#undef bool