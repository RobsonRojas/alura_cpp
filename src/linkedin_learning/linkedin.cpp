#include "linkedin.h"

#include <iostream>
#include <iomanip>

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