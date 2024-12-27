/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 20:18:11
 * @LastEditTime : 2024-12-27 23:31:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : PrintResult.c
 *      © 2024 FeiYehua
 */
#include"PrintResult.h"
#include"Attributes.h"
void printEmphasis()
{
    printf("\033[1m");
}
void printColor(COLOR color)
{
    switch (color)
    {
    case RED:
        printf("\033[31m");
        break;
    case BLUE:
        printf("\033[34m");
        break;
    case GREEN:
        printf("\033[32m");
    default:
        break;
    }
}
void printItalic()
{
    printf("\033[3m");
}
void printUnderline()
{
    printf("\033[4m");
}
void printNormal()
{
    printf("\033[0m");
}
void printFormat(element* element)
{
    if(element==NULL) 
    {
        return;
    }
    if(element->color!=BLACK)
    {
        printColor(element->color);
    }
    if(element->em)
    {
        printEmphasis();
    }
    if(element->i)
    {
        printItalic();
    }
    if(element->u)
    {
        printUnderline();
    }
}
void printResult(OutputArray** loc,int screenWidth,int screenHeight)
{
    element* lastElement=NULL;
    for(int i=0;i<screenHeight;i++)
    {
        for(int j=0;j<screenWidth;j++)
        {
            if(lastElement!=loc[j][i].el)
            {
                printNormal();
                printFormat(loc[j][i].el);
                lastElement=loc[j][i].el;
            }
            printf("%c",loc[j][i].c);
        }
        printf("\n");
    }
}