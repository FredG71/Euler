#include <cstdio>
#include <cstdint>

/*  To solve this problem, we'll simply reverse what's being asked. By making use of the LCM we can easily solve
    this simple problem, given the fact that 2520 is the smallest number that can by divided by 1 to 10 without any 
    remainder this implies that 2520 = "1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10", note that this is in quotes to emphasise
    that this isn't actually true, as noted on the first problem, for a number j there exists a number i that evenly divides
    j, we do not want to include this number, thus for 2520 we note this can also be represented as
    9 * 8 * 7 * 5. By making use of the same process for the number x, we seek a number x, such that
    { 1 ... 20 | x }

    Solving for x, we arrive at x = 19 * 17 * 16 * 13 * 11 * 9 * 7 * 5
    x = 232 792 560
*/

uint32_t FifthProblem()
{
    return (19 * 17 * 16 * 13 * 11 * 9 * 7 * 5);
}

int main(int argc, char** argv)
{
    printf("%i\n", FifthProblem());
}