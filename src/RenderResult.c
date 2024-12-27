/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 18:06:43
 * @LastEditTime : 2024-12-28 00:44:02
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
        int printLocX=x;//这个是开始打印的横、纵坐标
        int printLocY=y;
        //按照行排列，考虑单个元素如何在横向对齐。
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
        //打印元素
        if(cur->name==DIV)
        {
            renderDiv(cur,outputArray,printLocX,printLocY);
        }
        else
        {
            renderContens(cur,outputArray,printLocX,printLocY);
        }
        //如果是按列排列，则更新x坐标
        if(el->direction==COLUMN)
        {
            x+=cur->w;
            //注意等间距对齐时的特殊处理
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
        //如果是一个Div，则跳过其中的元素，避免重复渲染
        if(cur->name==DIV)
        {
            cur=cur->endDiv;
        }
        cur++;
    }
}
//渲染函数，
void renderContens(element* el,OutputArray** outputArray,int x,int y)
{
    for(int j=0;j<el->h;j++)
    {
        for (int i = 0; i < el->w; i++)
        {
            outputArray[x + i][y + j].c = *((el->content) + i + j * el->w);
            //特判Heading的大写情况
            if(el->name==HEADING&&outputArray[x + i][y + j].c>='a'&&outputArray[x + i][y + j].c<='z')
            {
                outputArray[x + i][y + j].c=outputArray[x + i][y + j].c-'a'+'A';
            }
            outputArray[x + i][y + j].el = el; // 方便访问元素的属性
        }
    }
}