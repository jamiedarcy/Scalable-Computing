/*
 *   A small college is thinking of instituting a six-digit student ID
 *   number. It wants to know how many "acceptable" ID numbers there
 *   are. An ID number is "acceptable" if it has no two consecutive 
 *   identical digits and the sum of the digits is not 7, 11, or 13.
 *
 *   024332 is not acceptable because of the repeated 3s.
 *   204124 is not acceptable because the digits add up to 13.
 *   304530 is acceptable.
 */

/*
 *   Function "no_problem_with_digits" extracts the digits from
 *   the ID number from right to left, making sure that there are
 *   no repeated digits and that the sum of the digits is not 7,
 *   11, or 13.
 */

#include <stdio.h>
#include <omp.h>

int no_problem_with_digits (int i)
{
   int j;
   int latest;   /* Digit currently being examined */
   int prior;    /* Digit to the right of "latest" */
   int sum;      /* Sum of the digits */

   prior = -1;
   sum = 0;

   //#pragma omp parallel for
   for (j = 0; j < 6; j++) {
      latest = i % 10;
      if (latest == prior) return 0;
      sum += latest;
      prior = latest;
      i /= 10;
   }
   if ((sum == 7) || (sum == 11) || (sum == 13)) return 0;
   return 1;
}

/*
 *   Function "main" iterates through all possible six-digit ID
 *   numbers (integers from 0 to 999999), counting the ones that
 *   meet the college's definition of "acceptable."
 */

int main (void)
{
   int count;   /* Count of acceptable ID numbers */
   int i;


   count = 0; 
   #pragma omp parallel
{

   //printf("There are %d \n", omp_get_thread_num());
  if (omp_get_thread_num() == 0) {
	   printf("There are %d \n", omp_get_num_threads());
  }
} 
  #pragma omp parallel for reduction(+:count)
   for (i = 0; i < 1000000; i++)
      if (no_problem_with_digits (i)) {
        count++;
      }
   printf ("There are %d acceptable ID numbers\n", count);
   return 0;
}
