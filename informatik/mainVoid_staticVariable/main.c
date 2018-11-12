/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 4. Nov 2018 *
 * int main(void) & static int
******************************/

#include <stdio.h>
int main()              /* Würde mit main(void) in diesem Fall nicht gehen, da später main(10) zurück kommt. */
{
    static int i = 5;   /* Variable wird nicht jedes Mal neu gesetzt. */
    if (--i){           /* Bedeutet so viel wie if(--i != false) - wird bei 0 beendet. */
        printf("%d ", i);
        main(10);
    }
}
/* Output: 4 3 2 1 */