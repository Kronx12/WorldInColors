#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

typedef enum    { fGREY=30, fRED=31, fGREEN=32, fYELLOW=33, fBLUE=34, fPURPLE=35, fCYAN=36, fWHITE=37 } fgColor;
typedef enum    { bGREY=40, bRED=101, bGREEN=102, bYELLOW=103, bBLUE=44, bPURPLE=105, bCYAN=106, bWHITE=107 } bgColor;
typedef enum    { NORMAL=0, BOLD=1, DIM=2, ITALIC=3, UNDERLINE=4, INVERT=7, HIDDEN=8 } weight;
typedef enum    { LEFT=0, CENTER=1, RIGHT=2 } align;

typedef struct		s_color
{
	bgColor		bc;
	fgColor		fc;
	weight		w;
}			t_color;

t_color	*newColor(bgColor bc, fgColor fc, weight w);
char	*strtoupper(char *str);
int	print(t_color *c, char *str);
int	printOK();
int	printKO();
void	printNextLine(t_color *c, int h);
void	printTitle(char *str, t_color *c);
int	completeLine(t_color *c, int l);
void	autoLine(char *str, t_color *c, align a);
