#include "libcolor.h"

int main()
{
	char ch;
	t_color *c = newColor(bGREY, fPURPLE, BOLD);
	t_color *title = newColor(bGREY, fPURPLE, INVERT);
	t_color *o = newColor(bBLUE, fWHITE, BOLD);
	
	printNextLine(c, 2);
	printTitle("test Libft :", title);
	printNextLine(c, 2);
	printNextLine(o, 2);
	autoLine("A) Option A", o, LEFT);
	autoLine("B) Option B", o, LEFT);
	printNextLine(o, 2);
	ch = getc(2);
	if (ch == 'A' || ch == 'a')
		return 1;

	return 0;
}
