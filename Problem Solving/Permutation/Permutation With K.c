#include <stdio.h>
#include <stdlib.h>

void combinations (int v[], int start, int n, int k, int maxk) {
        int     i;

        /* k here counts through positions in the maxk-element v.
         * if k > maxk, then the v is complete and we can use it.
         */
        if (k > maxk) {
                /* insert code here to use combinations as you please */
                for (i=1; i<=maxk; i++) printf ("%i ", v[i]);
                printf ("\n");
                return;
        }

        /* for this k'th element of the v, try all start..n
         * elements in that position
         */
        for (i=start; i<=n; i++) {

                v[k] = i;

                /* recursively generate combinations of integers
                 * from i+1..n
                 */
                combinations (v, i+1, n, k+1, maxk);
        }
}

int main (int argc, char *argv[]) {
        int     v[100], n, k;


        n = atoi ("10");
        k = atoi ("3");

        /* generate all combinations of n elements taken
         * k at a time, starting with combinations containing 1
         * in the first position.
         */
        combinations (v, 1, n, 1, k);
        exit (0);
}
