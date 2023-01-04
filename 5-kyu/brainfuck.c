void seek(const char **tape, int n) {
    int balancer = n;
    
    while (balancer) {
        *tape += n;
        
        if (**tape == '[') balancer++;
        else if (**tape == ']') balancer--;
    }
}

void brainfuck(const char *tape, const char *input, char *output) {
    unsigned char registers[30000] = { 0 };
    unsigned char op, *r = registers;
    
    while (*tape) {
      switch ((op = *tape)) {
        case '>': ++r; break;
        case '<': --r; break;
        case '+': ++*r; break;
        case '-': --*r; break;
        case ',': *r = *input++; break;
        case '.': *output++ = *r; break;
        case '[': if (!*r) seek(&tape, 1); break;
        case ']': if (*r) seek(&tape, -1); break;
      }
      tape++;
    }
    
    *output = '\0';
}