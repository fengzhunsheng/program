bool isPalindrome(int x){
    if(x < 0)
        return false;

    int token[10]={0};
    int index = 0;

    while(x != 0)
    {
        token[index++] = x % 10;
        x /= 10;
    }

    for(int i = 0; i < index; i++)
    {
        if(2*i + 1 > index)
        {
            break;
        }

        if(token[i] != token[index - 1 - i])
        {
            return false;
        }
    }
    return true;
}