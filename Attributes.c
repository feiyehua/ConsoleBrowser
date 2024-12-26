/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 11:01:27
 * @LastEditTime : 2024-12-26 23:32:15
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Attributes.c
 *      © 2024 FeiYehua
 */

#include"Attributes.h"
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
int editStrPtr(const char** strPtr)//修改下一次搜索的起始位置
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
int getElementName(const char** strPtr,const char* endPtr,NAME* name)
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
void getCorlor(const char* strPtr,const char* endPtr,struct element* element)
{
    const char* _t;
    if((_t=strSearch(strPtr,endPtr,"color="))!=NULL)//处理颜色
    {
        _t+=strlen("color=");
        char *_startPtr=strchr(_t,'"')+1;
        char *_endPtr=strchr(_startPtr,'"');
        if(strSearch(_startPtr,_endPtr,"red")!=NULL)
        {
            element->color=RED;
        }
        else if(strSearch(_startPtr,_endPtr,"green")!=NULL)
        {
            element->color=GREEN;
        }
        else if(strSearch(_startPtr,_endPtr,"blue")!=NULL)
        {
            element->color=BLUE;
        }
    }
}
void getDirection(const char* strPtr,const char* endPtr,struct element* element)
{
    const char* _t;
    if((_t=strSearch(strPtr,endPtr,"direction="))!=NULL)
    {
        _t+=strlen("direction=");
        char *_startPtr=strchr(_t,'"')+1;
        char *_endPtr=strchr(_startPtr,'"');
        if(strSearch(_startPtr,_endPtr,"row")!=NULL)
        {
            element->direction=ROW;
        }
        else if(strSearch(_startPtr,_endPtr,"column")!=NULL)
        {
            element->direction=COLUMN;
        }
    }
}
void getAlign_Items(const char* strPtr,const char* endPtr,struct element* element)
{
    const char* _t;
    if((_t=strSearch(strPtr,endPtr,"align-items="))!=NULL)
    {
        _t+=strlen("align-items=");
        char *_startPtr=strchr(_t,'"')+1;
        char *_endPtr=strchr(_startPtr,'"');
        if(strSearch(_startPtr,_endPtr,"start")!=NULL)
        {
            element->align=START;
        }
        else if(strSearch(_startPtr,_endPtr,"center")!=NULL)
        {
            element->align=CENTER;
        }
        else if(strSearch(_startPtr,_endPtr,"end")!=NULL)
        {
            element->align=END;
        }
        else if(strSearch(_startPtr,_endPtr,"space-evenly")!=NULL)
        {
            element->align=SPACE_EVENLY;
        }
    }
}
void getJustify_Content(const char* strPtr,const char* endPtr,struct element* element)
{
    const char* _t;
    if((_t=strSearch(strPtr,endPtr,"justify-content="))!=NULL)
    {
        _t+=strlen("justify-content=");
        char *_startPtr=strchr(_t,'"')+1;
        char *_endPtr=strchr(_startPtr,'"');
        if(strSearch(_startPtr,_endPtr,"start")!=NULL)
        {
            element->justify=START;
        }
        else if(strSearch(_startPtr,_endPtr,"center")!=NULL)
        {
            element->justify=CENTER;
        }
        else if(strSearch(_startPtr,_endPtr,"end")!=NULL)
        {
            element->justify=END;
        }
        else if(strSearch(_startPtr,_endPtr,"space-evenly")!=NULL)
        {
            element->justify=SPACE_EVENLY;
        }
    }
}
int getAttribute(const char** strPtr,const char* endPtr,struct element* element)
{
    getCorlor(*strPtr,endPtr,element);
    getDirection(*strPtr,endPtr,element);
    getAlign_Items(*strPtr,endPtr,element);
    getJustify_Content(*strPtr,endPtr,element);
    if(strSearch(*strPtr,endPtr," em ")!=NULL)
    {
        element->em=1;
    }
    if(strSearch(*strPtr,endPtr," i ")!=NULL)
    {
        element->i=1;
    }
    if(strSearch(*strPtr,endPtr," u ")!=NULL)
    {
        element->u=1;
    }
    if(strSearch(*strPtr,endPtr,"w=")!=NULL)
    {
        element->w=atoi(strSearch(*strPtr,endPtr,"w=")+1);
    }
    if(strSearch(*strPtr,endPtr,"h=")!=NULL)
    {
        element->h=atoi(strSearch(*strPtr,endPtr,"h=")+1);
    }
    if(strSearch(*strPtr,endPtr,"width=")!=NULL)
    {
        element->width=atoi(strSearch(*strPtr,endPtr,"width=")+1);
    }
    *strPtr=strchr(*strPtr,'>')+1;
    return 0;//editStrPtr(strPtr);
}
int parseBracket(const char* startStr,const char* endStr,struct element* element)
{
    //属性名：h，p，img，div
    getElementName(&startStr,endStr,&(element->name));//修改attribute的element值
    getAttribute(&startStr,endStr,element);
    return 0;
}
