/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 15:36:49
 * @LastEditTime : 2024-12-27 17:39:12
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : Array.c
 *      © 2024 FeiYehua
 */
#include"Array.h"
OutputArray** allocateArray(int m,int n)
{
    OutputArray** loc=(OutputArray**)malloc(sizeof(OutputArray*)*m);
    for (int i = 0; i < m; i++)
    {
        loc[i]=(OutputArray*)malloc(sizeof(OutputArray)*n);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            loc[i][j].el=NULL;
            loc[i][j].c=0;
        }
    }
    return loc;
}
void freeArray(OutputArray** loc,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        free(loc[i]);
    }
    free(loc);
    return;
}
