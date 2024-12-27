/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 08:53:03
 * @LastEditTime : 2024-12-27 09:32:41
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : InputParser.c
 *      © 2024 FeiYehua
 */
#include"InputParser.h"

void parseInput(const char* startPtr,element* el)
{
    int cnt=1;
    while(*startPtr!='\0')
    {
        if(*startPtr=='<')
        {
            const char* endPtr=strchr(startPtr,'>');
            if(checkEnd(startPtr+1,endPtr))
            {
                if(*(startPtr+2)=='d')
                {
                    int cur=cnt-1;//当前元素
                    while(el[cnt-1].name!=DIV)
                    {
                        cnt--;
                    }
                    cnt--;//div元素下标为cnt
                    
                }
            }
            else
            {
                inheritAttribute(&el[cnt],&el[cnt-1]);
                parseBracket(startPtr+1,endPtr,&el[cnt]);
                cnt++;
            }
            startPtr=endPtr;
        }
        else
        {
            el[cnt-1].content=startPtr;
            el[cnt-1].length=strchr(startPtr,'<')-startPtr;
            el[cnt-1].w=el[cnt-1].length;
            startPtr=strchr(startPtr,'<')-1;
        }
        startPtr++;
    }
}