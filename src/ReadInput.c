/*
 * @Author       : FeiYehua
 * @Date         : 2024-12-26 00:09:57
 * @LastEditTime : 2024-12-26 00:27:22
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : ReadInput.c
 *      © 2024 FeiYehua
 */
#include"ReadInput.h"
int readInput(int* length,char** inputData)
{
    char *curloc=(char*)malloc(sizeof(char)*(1e4+10));
    memset(curloc,0,sizeof(char)*(1e4+10));
    *inputData=curloc;
    char ch=getchar();
    while(ch!=EOF)
    {
        if(ch=='\t'||ch=='\n')
        {
            ch=getchar();
            continue;
        }
        if(ch=='>')
        {
            *curloc=' ';
            curloc++;
        }
        *curloc=ch;
        curloc++;
        ch=getchar();
    }
    *length=strlen(*inputData);
    return 0;
}