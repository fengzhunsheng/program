#define INT_MIN -2147483648
#define INT_MAX 2147483647

int myAtoi(char * str){
    int index = 0;
    int minus = false;
    int res = 0;

    while(str[index] != '\0' && str[index] == ' ')
    {
        index++;
    }

    if(str[index] == '-')
    {
        minus = true;
        index++;
    }
    else if(str[index] == '+')
    {
        index++;
    }
    else if(str[index] < '0' || str[index] > '9')
    {
        return 0;
    }

    while(str[index] != '\0')
    {
        if(str[index] < '0' || str[index] > '9')
        {
            break;
        }
        if(res > (INT_MAX - (str[index] - '0'))/10)
        {
            return minus ? INT_MIN : INT_MAX;
        }

        res = res*10 + (str[index] - '0');
        index++;
    }

    return minus ? -res : res;
}