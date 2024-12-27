/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-27 18:05:08
 * @LastEditTime : 2024-12-27 18:16:34
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : RenderResult.h
 * @     © 2024 FeiYehua
 */
#ifndef __RENDERRESULT_H__
#define __RENDERRESULT_H__

#include"Attributes.h"
#include"Array.h"
//在x，y位置渲染Div。
void renderDiv(element* el,OutputArray** outputArray,int x,int y);
//在x，y位置渲染一个Heading，Paragrph，或者img
void renderContens(element* el,OutputArray** outputArray,int x,int y);

#endif // __RENDERRESULT_H__
