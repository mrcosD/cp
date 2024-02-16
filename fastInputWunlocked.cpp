void fastscan(int &number) {
    /* Variable to indicate sign of the number */
    bool negative = false;
    int c;
 
    number = 0;
 
    /* Extract current char from the buffer */
    c = getchar();
    if (c=='-') {
        // number is negative
        negative = true;
 
        /* Extract the char from the buffer */
        c = getchar();
    }
 
    /* Keep on extracting characters if they are integers
     * i.e ASCII Value lies from '0'(48) to '9' (57) */
    for (; (c > 47 && c < 58); c = getchar())
        number = (number << 3) + (number << 1) + c - 48;
        
    /* If the input number is negative, negate its value */
    if (negative)
        number *= -1;
}