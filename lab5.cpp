#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::sort;


std::int64_t LocToDec(std::string const & loc){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int alphlen = static_cast<int>(alphabet.size());
    int wordlen = static_cast<int>(loc.size());
    std::int64_t value = 0;
    for(int i = 0; i < wordlen; i++){
        for(int z = 0; z < alphlen; z++){
            if(loc[i] == alphabet[z]){
                value += pow(2,z);
            }
        }
       
    }
    return value;
}


std::string Abbreviate(std::string const & loc){
    int wordlen = static_cast<int>(loc.size());
    std::string newnum = "";
    int i = 0;
    if(wordlen == 1){
        return loc;
    }
    if(wordlen == 2) {
        sort(loc.begin(), loc.end());
        return loc;
    }
    while(i < wordlen - 1){
        char first = loc.at(i);
        char sec = loc.at(i+1);
        if(first == sec){
            first++;
            newnum += first;
            i += 2;
        }
        else{
            newnum += first;
            i += 1;
        }
    }
    int newnumlen = static_cast<int>(newnum.size());
    std::string finalnum = "";
    for(int z = 0; z < newnumlen ; z++){
        char inst = newnum.at(z);
        if(z == newnumlen - 1)
        {
            inst++;
            finalnum += inst;
        }
        else{
            finalnum += inst;
        }
    }
    return finalnum;
}


std::string DecToLoc(std::int64_t dec) {
    std::string result = "";
    std::int64_t distance = 0;

    if(dec > 32) {
        distance = dec - 32;
        result.push_back('f');
    } else if(dec > 16) {
        distance = dec - 16;
        result.push_back('e');
    } else if(dec > 8) {
        distance = dec - 8;
        result.push_back('d');
    } else if(dec > 4) {
        distance = dec - 4;
        result.push_back('c');
    } else if(dec > 2) {
        distance = dec - 2;
        result.push_back('a');
        result.push_back('b');
    } else if(dec > 1) {
        result.push_back('b');
    } else if(dec > 0) {
        result.push_back('a');
    } else {
        result = "";
    }

    if(distance > 63) {
        result.insert(1, "f");
    }

    if(distance > 31) {
        result.insert(1, "e");
    }

    if(distance > 15) {
        result.insert(1, "d");
    }

    if(distance < 8) {
        result.insert(0,"c");
    }

    if(distance > 4) {
        result.insert(0,"a");
    }

    
    return result;
}

std::int64_t AddLoc(std::string const & loc1, std::string const & loc2) {
    string combination = loc1 + loc2;
    std::int64_t result = 0;
    combination = Abbreviate(combination);
    result = LocToDec(combination);
    return result;
}

int main() {
    string usr_in1 = "";
    std::int64_t usr_in2 = 0;
    string usr_in3 = "";
    string usr_in4 = "";
    cout << "Give me a location string:" << endl;
    cin >> usr_in1;
    cout << "Give me an integer:" << endl;
    cin >> usr_in2;
    cout << usr_in1 << " to dec: " << LocToDec(usr_in1) << endl;
    cout << usr_in1 << " abbreviated: " << Abbreviate(usr_in1) << endl;
    cout << usr_in2 << " to loc: " << DecToLoc(usr_in2) << endl;
    cout << "Give me two more location strings:" << endl;
    cin >> usr_in3 >> usr_in4;
    cout << "Sum of " << usr_in3 << " and " << usr_in4 << " is: " << AddLoc(usr_in3, usr_in4) << endl;
    return 0;
}