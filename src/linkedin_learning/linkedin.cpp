#include "linkedin.h"

#include <iostream>

string number_to_ordinal_sufix(int num) {
    if (num == 11 || num == 12) {
        return "th";
    }

    num %= 10;
    if (num == 1) {
        return "st";
    } else if (num == 2) {
        return "nd";
    } else if (num == 3) {
        return "rd";
    }

    return "th";
}

void print_number_sufix() {
    for (int i = 1; i <= 20; i++) {
        cout << i << number_to_ordinal_sufix(i) 
        << "\t" << i+20 << number_to_ordinal_sufix(i+20) 
        << "\t" << i+40 << number_to_ordinal_sufix(i+40) 
        << "\t" << i+60 << number_to_ordinal_sufix(i+60) 
        << "\t" << i+80 << number_to_ordinal_sufix(i+80)
        << endl;
    }
}