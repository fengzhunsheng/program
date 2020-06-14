bool match(char * s, char * p);

bool isMatch(char * s, char * p){
    return match(s, p);
}

bool match(char * s, char * p)
{
    // 字符规律p为空，返回
    if(*p == 0) return *s == 0;
        
    // 当前s和p的第一个字符是否匹配
    auto first_match = *s && (*p == *s || *p == '.');
    
    // p的第二个字符是否为'*'
    if(*(p+1) == '*')
    {
        // 如果是，则分两种情况；
        // 这个'*'匹配零个前面的那一个元素，则p+2
        // 这个'*'匹配1个或多个前面的那一个元素，则s+1
        return match(s, p+2) || (first_match && match(++s, p));
    }
    else
    {
        // 如果不是，则s+1,p+1
        return first_match && match(++s, ++p);
    } 
}