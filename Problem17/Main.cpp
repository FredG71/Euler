#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdint>

/*  Uses a table that contains the words used for the numbers, the GetNumberDigit stores an array of indices that contains the index into the 
    consecutive words, by extracting each digit using the modulo operation, i.e. n mod nx10^y where y is the unit, we can combine the needed
    words together, note that no explicit string concatenation occurs, i.e. the strings are never concatenated, 0xFFFFFFFF denotes the end of the
    array of indices. */
char* NumberLetterTable[]{
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
        "hundred",
        "thousand",
        "and",
};

void GetNumberDigit(uint32_t nIndex, /*__out__*/ uint32_t* IndexArray)
{
    if (nIndex < 0 || nIndex > 1000)
        __asm int 1;
    if (nIndex <= 10)
    {
        IndexArray[0] = nIndex - 1;
        IndexArray[1] = 0xFFFFFFFF;
    }
    else if (nIndex > 10)
    {
        if (nIndex % 10 != 0 && nIndex < 20)
        {
            IndexArray[0] = ( ( nIndex % 10 ) + 10 ) - 1;
            IndexArray[1] = 0xFFFFFFFF;
        }
        else if (nIndex % 10 == 0 && nIndex >= 20)
        {
            IndexArray[0] = ((nIndex / 10) + 17);
            IndexArray[1] = 0xFFFFFFFF;
        }
        else if (nIndex % 10 != 0 && nIndex >= 20)
        {
            IndexArray[0] = (( nIndex / 10 ) + 17);
            IndexArray[1] = ( nIndex % 10 ) - 1;
            IndexArray[2] = 0xFFFFFFFF;
        }
        if (nIndex >= 100)
        {
            if (nIndex % 100 == 0)
            {
                IndexArray[0] = (nIndex / 100) - 1;
                IndexArray[1] = 27;
                IndexArray[2] = 0xFFFFFFFF;
            }
            else if (nIndex % 100 > 0)
            {
                IndexArray[0] = ( nIndex / 100 ) - 1;
                IndexArray[1] = 27;
                IndexArray[2] = 29;
                if (nIndex % 100 < 10)
                {
                    IndexArray[3] = ( nIndex % 100 ) - 1;
                    IndexArray[4] = 0xFFFFFFFF;
                }
                else if (nIndex % 100 >= 10)
                {
                    if ((nIndex % 100) % 10 == 0)
                    {
                        if ((nIndex % 100) / 10 == 1)
                        {
                            IndexArray[3] = ((nIndex % 100) / 10) + 8;
                            IndexArray[4] = 0xFFFFFFFF;
                        }
                        else if ((nIndex % 100) / 10 > 1)
                        {
                            IndexArray[3] = ((nIndex % 100) / 10) + 17;
                            IndexArray[4] = 0xFFFFFFFF;
                        }
                    }
                    else if ((nIndex % 100) % 10 > 0)
                    {
                        if ((nIndex % 100) / 10 == 1)
                        {
                            IndexArray[3] = ( nIndex % 100 ) - 1;
                            IndexArray[4] = 0xFFFFFFFF;
                        }
                        else if ((nIndex % 100 / 10 > 1))
                        {
                            IndexArray[3] = ( ( nIndex % 100 ) / 10 ) + 17;
                            if ((nIndex % 100) % 10 == 0)
                            {
                                IndexArray[4] = 0xFFFFFFFF;
                            }
                            else if ((nIndex % 100) % 10 > 0)
                            {
                                IndexArray[4] = (( nIndex % 100 ) % 10 ) - 1;
                                IndexArray[5] = 0xFFFFFFFF;
                            }
                        }
                    }
                }
            }
        }
        if (nIndex == 1000)
        {
            IndexArray[0] = 0;
            IndexArray[1] = 28;
            IndexArray[2] = 0xFFFFFFFF;
        }
    }
}

int main()
{
    uint32_t nCounter = 0;
    unsigned int* Array = new uint32_t[25];
    uint32_t j = 0;
    for (uint32_t i = 1; i <= 1000; ++i)
    {
        GetNumberDigit( i, Array );
        while (Array[j] != -1)
        {
            nCounter += strlen(NumberLetterTable[Array[j]]);
            ++j;
        }
        j = 0;
    }
    printf("%i\n", nCounter );
    delete[] Array;
}

