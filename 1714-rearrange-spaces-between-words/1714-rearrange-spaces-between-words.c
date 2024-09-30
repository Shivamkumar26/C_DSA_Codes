char* reorderSpaces(char* st) {
    int n = strlen(st);
    int words = 0, spaces = 0;

    int i = 0;
    while(i < n) {
        if(st[i] == ' ') spaces++, i++;
        else {
            while(i < n && st[i]!=' ') {
                i++;
            }
            words++;
        }
    }
    // printf("%d %d\n", words, spaces);

    i = 0;
    int idx = 0;
    char* ans = (char *)malloc(sizeof(char)*(n+1));

    // handling edge case : if only 1 word is present 
    int spaceBetween = ((words == 1) ? 0 : spaces/(words-1));
    int extraSpace = ((words == 1) ? spaces : spaces % (words-1));

    while(idx < n) {
        // if(idx == 0 || st[i] == ' ') { //first word

            while(i < n && st[i] == ' ') i++; //initial space
            while(i < n && st[i] != ' ') { // adding  word
                ans[idx++] = st[i++];
            }
            //spaces after 
            words--;
            if(words) {
                for(int k = 0; k < spaceBetween; k ++)
                    ans[idx++] = ' ';
            }

            if(!words) {
                for(int k = 0; k < extraSpace; k ++)
                    ans[idx++] = ' ';
            }
        // }
    }
    ans[n] = '\0';
    return ans;

}