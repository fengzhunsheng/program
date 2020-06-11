#define INT_MIN -2147483648
#define INT_MAX 2147483647

int myAtoi(char * str){
    int str_index = 0;
    int token_index = 0;
    int res = 0;
    int *token = (int *)malloc(strlen(str)*sizeof(int));
    bool minus = false;
    bool overBound = false;

    char character = str[str_index++];
    while(character == ' ') 
    {
        character = str[str_index++];
    }

    while(character == '0')
    {
        character = str[str_index++];
        if(character < 48 || character > 57)
            return 0;
    }

    switch(character)
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        token[token_index++] = character - 48;
        character = str[str_index++];
        while(character >=48 && character <= 57)
        {
            token[token_index++] = character - 48;
            character = str[str_index++];
        }
        break;

    case '+':
        character = str[str_index++];
        while(character == '0')
        {
            character = str[str_index++];
        }

        while(character >=48 && character <= 57)
        {
            token[token_index++] = character - 48;
            character = str[str_index++];
        }
        break;

    case '-':
        minus = true;

        character = str[str_index++];
        while(character == '0')
        {
            character = str[str_index++];
        }
        
        while(character >=48 && character <= 57)
        {
            token[token_index++] = character - 48;
            character = str[str_index++];
        }
        break;
    
    default:
        return 0;
    }

    int C = 1;
    for(int i = token_index - 1; i >=0; i--)
    {
        if(token_index > 10 || (token_index == 10 && token[i] > 2 && i == 0) 
            || INT_MAX - token[i]*C < res)
        {
            overBound = true;
            break;
        }
        res += token[i]*C;

        if(i != 0)
        {
            C *= 10;
        }    
    }

    if(minus)
    {
        if(overBound)
        {
            return INT_MIN;
        }      
        else
        {
            res = -res;
        }
    }
    else
    {
        if(overBound)
        {
            return INT_MAX;
        }      
    }

    return res;
}