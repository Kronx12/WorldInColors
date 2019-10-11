/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   enum_color.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 22:42:31 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 23:09:48 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

typedef enum 	{ fGREY=30, fRED=31, fGREEN=32, fYELLOW=33, fBLUE=34, fPURPLE=35, fCYAN=36, fWHITE=37 } fgColor;
typedef enum	{ bGREY=100, bRED=101, bGREEN=102, bYELLOW=103, bBLUE=104, bPURPLE=105, bCYAN=106, bWHITE=107 } bgColor;
typedef enum	{ NORMAL=0, BOLD=1 } weight;

void printTitle(bgColor bc, fgColor fc, weight w, char *str)
{
	printf("\033[%d;%dm", w, fc);
	printf("\e[%dm", bc);
	printf("%s", str);
	printf("\033[0;37m");
}

void printOK()
{
	printTitle(bGREY, fWHITE, BOLD, "[");
	printTitle(bGREY, fGREEN, BOLD, "OK");
	printTitle(bGREY, fWHITE, BOLD, "]");	
}

void printNO()
{
	printTitle(bGREY, fWHITE, BOLD, "[");
	printTitle(bGREY, fRED, BOLD, "OK");
	printTitle(bGREY, fWHITE, BOLD, "]");	
}

int main()
{
	printOK();
	printOK();
	printNO();
	printOK();
	printf("\n");
	return 0;
}
