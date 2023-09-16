#include <unistd.h>
#include <string.h>



int output_1(char c)
{
    return (write(1, &c, 1));
}


int output(char *str, int bytes)
{
    return (write(1, str, bytes));
}
