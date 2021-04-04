#include <iostream>
#include <string>

void isUnique(std::string str){
    int strLen = str.length(); // length of the string
    int str_dup_count = 0;
    // for each character in the string check if there is any duplicate
    for (int i=0; i<strLen; i++){
        int char_dup = 0;
        for(int j=0; j<strLen; j++){ // traverse with all the char in the string
            if(str[j] == str[i]){ // compare the str[i] with all the other char in the string
                //if(i != j){ // avoid comparing a char with itself
                    char_dup += 1;
                //}

            }
        }
        if (char_dup > 1){
            std::cout << str[i] << " appers " << char_dup << " times in " << str << std::endl;
            str_dup_count += 1;
        }

    }
    if (str_dup_count > 0)
        std::cout << "The string does not have all unique characters." << std::endl;
    else
        std::cout << "The string has all unique characters." << std::endl;

}

int main(){
    std::string str1 = "hello";
    std::string str2 = "world";
    std::string result = str1 + " "+ str2;

    std::cout << result << std::endl;
    std::cout << "length of str1: " << str1.length() << std::endl;

    std::cout <<str1[4] << std::endl;
    //int len = str1.length();

    // reverse the string
    for (int i = result.length(); i > 0; i--){
        //std::cout << "inside for loop" << std::endl;
        std::cout <<result[i-1] << " ";
    }
    std::cout << std::endl;

    std::cout << "does " << result << " have all unique characters?" << std::endl;
    isUnique(result);

    return 0;
}
