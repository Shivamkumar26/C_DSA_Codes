char* intToRoman(int num) {
    char* ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* thousand[] = {"", "M", "MM", "MMM"};
       
    char* res = (char*)malloc(100000);
    res[0] = '\0';

    strcat(res, thousand[num / 1000]);
    strcat(res, hundred[(num % 1000) / 100]);
    strcat(res, tens[(num % 100) / 10]);
    strcat(res, ones[num % 10]);

    return res;
}