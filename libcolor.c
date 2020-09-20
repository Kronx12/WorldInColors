#include "libcolor.h"

t_color	*newColor(bgColor nbc, fgColor nfc, weight nw)
{
	t_color *new = malloc(sizeof(t_color));
	new->bc = nbc;
	new->fc = nfc;
	new->w	= nw;
	return(new);
}

int	print(t_color *color, char *str)
{
	printf("\033[%d;%dm", color->w, color->fc);
	printf("\e[%dm", color->bc);
	printf("%s", str);
	printf("\033[0;37m");
	return (strlen(str)); 
}

int	printOK()
{
	t_color *gw;
	t_color *gg;
       
	gw = newColor(bGREY, fWHITE, BOLD);
	gg = newColor(bGREY, fGREEN, BOLD);
	print(gw, "[");
	print(gg, "OK");
	print(gw, "]");	
	return (3);
}

int	printKO()
{
        t_color *gw;
        t_color *gr;

        gw = newColor(bGREY, fWHITE, BOLD);
        gr = newColor(bGREY, fRED, BOLD);
	print(gw, "[");
	print(gr, "OK");
	print(gw, "]");	
	return (3);
}

void	printNextLine(t_color *c, int h)
{
	struct winsize w;
	int tmp;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	tmp = w.ws_col;
	while (tmp-- > 0)
		print(c, " ");
	if (h-- > 1)
		printNextLine(c, h);
}

int	completeLine(t_color *c, int l)
{
	int i;

	i = l;
	while (l-- > 0)
		print(c, " ");
	return (i);
}

char	*strtoupper(char *str)
{
	char *res = malloc((strlen(str) + 1) * sizeof(char));
	char *dest = res;

	while((*res++ = toupper(*str++)));
	return dest;
}

void	autoLine(char *str, t_color *c, align a)
{
	struct winsize w;
	int width;
	int margin;

	margin = 10;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        width = w.ws_col;

	if (a == 0)
	{
		width -= completeLine(c, margin);
		width -= print(c, (char *)str);
		completeLine(c, width);
	}
	else if (a == 1)
	{
		width -= completeLine(c, (width / 2) - (strlen(str) / 2));
		width -= print(c, (char *)str);	
		completeLine(c, width);
	}
	else if (a == 2)
	{
		width -= completeLine(c, width - strlen(str) - margin);
                width -= print(c, (char *)str);
                completeLine(c, width);
	}
}

void	printTitle(char *str, t_color *c)
{
	autoLine(strtoupper(str), c, CENTER);
}












