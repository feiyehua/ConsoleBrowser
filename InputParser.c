/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 08:53:03
 * @LastEditTime : 2024-12-27 15:26:46
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : InputParser.c
 *      © 2024 FeiYehua
 */
#include"InputParser.h"

void parseInput(const char* startPtr,element* el,Stack* stack)
{
    int cnt=1;
    while(*startPtr!='\0')
    {
        if(*startPtr=='<')
        {
            const char* endPtr=strchr(startPtr,'>');
            if(checkEnd(startPtr+1,endPtr))
            {
                if(*(startPtr+2)=='d')//是一个div结束了，更改栈上Div，返回更新Div的属性
                {
                    int startDiv=stackTop(stack);
                    stackPop(stack);
                    el[startDiv].endDiv=cnt-1;
                    updateDiv(el,startDiv,cnt-1);
                    const char* _t=strchr(endPtr, '<');
                    if(_t!=NULL)
                    {
                        endPtr = _t-1;
                    }
                }
            }
            else
            {
                inheritAttribute(&el[cnt],&el[stackTop(stack)]);
                parseBracket(startPtr+1,endPtr,&el[cnt]);
                if(el[cnt].name==DIV)
                {
                    stackPush(stack,cnt);
                    endPtr = strchr(endPtr, '<') - 1;
                }
                else if(el[cnt].name==HEADING||el[cnt].name==PARAGARPH)
                {
                    el[cnt].content = endPtr+1;
                    el[cnt].length = strchr(el[cnt].content, '<') - el[cnt].content;
                    el[cnt].w = el[cnt].length;
                    endPtr = strchr(el[cnt].content, '<') - 1;
                }
                else if(el[cnt].name==IMAGE)
                {
                    el[cnt].w=el[cnt].imgaeInfo.width;
                    el[cnt].h=el[cnt].imgaeInfo.length/el[cnt].imgaeInfo.width;
                }
                cnt++;
            }
            startPtr=endPtr;
        }
        startPtr++;
    }
    int startDiv=stackTop(stack);
    stackPop(stack);
    el[startDiv].endDiv=cnt-1;
    updateDiv(el,startDiv,cnt-1);
}