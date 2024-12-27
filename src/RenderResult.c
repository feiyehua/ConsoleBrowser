/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 18:06:43
 * @LastEditTime : 2024-12-28 00:34:59
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : RenderResult.c
 *      © 2024 FeiYehua
 */
#include"RenderResult.h"
int getNumberOfElement(element* startElement,element* endElement)
{
    int cnt=0;
    while(startElement<=endElement)
    {
        cnt++;
        if(startElement->name==DIV)
        {
            startElement=startElement->endDiv;
        }
        startElement++;
    }
    return cnt;
}
void renderDiv(element* el,OutputArray** outputArray,int x,int y)
{
    element* endEle=el->endDiv;
    element* cur=el+1;
    int numOfElement=getNumberOfElement(cur,endEle);
    int wHeight = el->h - el->contentHeight;
    int wWidth = el->w - el->contentWidth;
    if (el->direction == COLUMN)
    {
        if (el->justify == END)
        {
            x += wWidth;
        }
        else if (el->justify == CENTER)
        {
            x += (wWidth / 2);
        }
        else if(el->justify==SPACE_EVENLY)
        {
            x+=(wWidth/(numOfElement+1));
        }
    }
    else if (el->direction == ROW)
    {
        if (el->align == END)
        {
            y += wHeight;
        }
        else if (el->align == CENTER)
        {
            y += (wHeight / 2);
        }
        else if(el->align==SPACE_EVENLY)
        {
            y+=(wHeight/(numOfElement+1));
        }
    }
    while(cur<=endEle)
    {
        int printLocX=x;
        int printLocY=y;
        if(el->direction==ROW)
        {
            int white=el->w-cur->w;
            if (el->justify == END)
            {
                printLocX += white;
            }
            else if (el->justify == CENTER)
            {
                printLocX += (white / 2);
            }
            else if (el->justify == SPACE_EVENLY)
            {
                printLocX += (white / (1 + 1));
            }
        }
        if(el->direction==COLUMN)
        {
            int white=el->h-cur->h;
            if (el->align == END)
            {
                printLocY += white;
            }
            else if (el->align == CENTER)
            {
                printLocY += (white / 2);
            }
            else if (el->align == SPACE_EVENLY)
            {
                printLocY += (white / (1 + 1));
            }
        }
        if(cur->name==DIV)
        {
            renderDiv(cur,outputArray,printLocX,printLocY);
        }
        else
        {
            renderContens(cur,outputArray,printLocX,printLocY);
        }
        if(el->direction==COLUMN)
        {
            x+=cur->w;
            if(el->justify==SPACE_EVENLY)
            {
                x+=(wWidth/(numOfElement+1));
            }
        }
        else if(el->direction==ROW)
        {
            y+=cur->h;
            if(el->align==SPACE_EVENLY)
            {
                y+=(wHeight/(numOfElement+1));
            }
        }
        if(cur->name==DIV)
        {
            cur=cur->endDiv;
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
            if(el->name==HEADING&&outputArray[x + i][y + j].c>='a'&&outputArray[x + i][y + j].c<='z')
            {
                outputArray[x + i][y + j].c=outputArray[x + i][y + j].c-'a'+'A';
            }
            outputArray[x + i][y + j].el = el; // 方便访问元素的属性
        }
    }
}