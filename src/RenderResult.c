/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 18:06:43
 * @LastEditTime : 2024-12-27 23:32:55
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : RenderResult.c
 *      © 2024 FeiYehua
 */
#include"RenderResult.h"
void renderDiv(element* el,OutputArray** outputArray,int x,int y)
{
    element* endEle=el->endDiv;
    element* cur=el+1;
    int numOfElement=endEle-el;
    int w;
    if(el->direction==ROW)
    {
        w=el->h-el->contentHeight;
    }
    else
    {
        w=el->w-el->contentWidth;
    }
    if (el->direction == COLUMN)
    {
        if (el->justify == END)
        {
            x += w;
        }
        else if (el->justify == CENTER)
        {
            x += (w / 2);
        }
        else if(el->justify==SPACE_EVENLY)
        {
            x+=(w/(numOfElement+1));
        }
    }
    else if (el->direction == ROW)
    {
        if (el->align == END)
        {
            y += w;
        }
        else if (el->align == CENTER)
        {
            y += (w / 2);
        }
        else if(el->align==SPACE_EVENLY)
        {
            y+=(w/(numOfElement+1));
        }
    }
    while(cur<=endEle)
    {
        if(cur->name==DIV)
        {
            renderDiv(cur,outputArray,x,y);
            cur=cur->endDiv;
        }
        else
        {
            renderContens(cur,outputArray,x,y);
        }
        if(el->direction==COLUMN)
        {
            x+=cur->w;
            if(el->justify==SPACE_EVENLY)
            {
                x+=(w/(numOfElement+1));
            }
        }
        else if(el->direction==ROW)
        {
            y+=cur->h;
            if(el->align==SPACE_EVENLY)
            {
                y+=(w/(numOfElement+1));
            }
        }
        cur++;
    }
}
void renderContens(element* el,OutputArray** outputArray,int x,int y)
{
    for(int j=0;j<el->h;j++)
    {
        for (int i = 0; i < el->w; i++)
        {
            outputArray[x + i][y + j].c = *((el->content) + i + j * el->w);
            outputArray[x + i][y + j].el = el; // 方便访问元素的属性
        }
    }
}