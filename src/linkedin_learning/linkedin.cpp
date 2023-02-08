#include "linkedin.h"

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

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

void print_centered(int length, string text) {
    unsigned int offset = (length - text.length()) / 2;
    unsigned int mod = ((length - text.length()) % 2 > 0? 1: 0);
    // cout << length << " " << text.length() << " " << offset << endl;
    cout << "|" << std::string(offset, ' ')
                << text << std::string(offset + mod, ' ') << "|"<< endl;
}

void center_text(int length, string &text) {
    // unsigned int offset = (length - text.length()) / 2;
    // unsigned int mod = ((length - text.length()) % 2 > 0? 1: 0);
    // cout << length << " " << text.length() << " " << offset << endl;

    if (text.length() > length) {
        for (size_t i = 0; i < text.length(); i+=length) {
            // cout << "|"<< text.substr(i, length) << "|" << endl;
            print_centered(length, text.substr(i, length));

        }
    } else {
        // cout << "|" << std::string(offset, ' ')
        //             << text << std::string(offset + mod, ' ') << "|"<< endl;
        print_centered(length, text);
    }
}

void centered_text() {

    string titles[] = {
        "March Sales",
        "My First Project",
        "Centering output is so much fun!",
        "This title is very long, just to see whether the code can handle such a long title"
    };

    for (auto &&title : titles)
    {
        center_text(80, title);
        
    }
    

}


static const unsigned int kPenny = 1; // "1 (one) cent = 1 centavo - penny
static const unsigned int kNickel = 5; // 5 (five) cents = 5 centavos -"a nickel"
static const unsigned int kDime = 10; // 10 (ten) cents = 10 centavos - dime
static const unsigned int kQuarter = 25; // 25 (twenty-five) cents = 25 centavos - quarter

void change_coins(float amount) {
    unsigned int dimes = 0;
    unsigned int nickels = 0;
    unsigned int pennies = 0;

    unsigned int quarters = amount*100 / kQuarter;    
    double remaind =  (amount*100 - (kQuarter * quarters));

    dimes = remaind / kDime;
    remaind = (remaind - (kDime * dimes));

    nickels = remaind / kNickel;
    remaind = (remaind - (kNickel * nickels));

    pennies = remaind / kPenny;
    remaind = (remaind - (kPenny * pennies));
    cout << amount << " = " << quarters << " quarters " 
                            << dimes << " dimes "
                            << nickels << " nickels "
                            << pennies << " pennies " << endl << endl;


}

void change_coins(){
    change_coins(0.49);
    change_coins(1.27);
    change_coins(0.75);
    change_coins(1.31);
    change_coins(0.83);
}


void halistone_sequence(int n) {
    cout << n << " ";
    if (n == 1) {
        cout << endl;
        return;
    }

    if (n % 2 == 0) {
        halistone_sequence(n / 2);
    } else {
        halistone_sequence((n*3) + 1);
    }
}

array<char, 13> copy_half(array<char, 26> arr, int from_idx) {
    array<char, 13> part1;
    for (size_t i = 0; i < 13; i++) {
        part1[i] = arr[i + from_idx];
    }

    return part1;
}

void print_half(array<char, 13> arr) {
    for (auto &&i : arr) {
        cout << i << " ";
    }
}

void perfect_sufle() {
    array<char, 26> cards = {{'A','B','C','D','E','F','G',
                                'H','I','J','K','L','M','N',
                                'O','P','Q','R','S','T','U',
                                'V','W','X','Y','Z'}};
    array<char, 26> original = cards;

    array<char, 13> part1 = copy_half(cards, 0);
    array<char, 13> part2 = copy_half(cards, 13);

    cout << "part 1: ";
    print_half(part1);
    // for (auto &&i : part1)
    // {
    //     cout << i << " ";
    // }
    cout << endl << "part 2: ";
    print_half(part2);
    // for (auto &&j : part2)
    // {
    //     cout << j << " ";
    // }

    cout << endl;





    


    


}