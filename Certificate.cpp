#include "Certificate.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

//function to generate random hex digit
char getRandomHex(){
    const char hexDigit[]="0123456789ABCDEF";
    //get random 0-15
    return hexDigit[rand() %16];
}

Certificate::Certificate():length(0){}

Certificate::Certificate(int len):length(len){
    //generate random words
    for (int i =0;i<len;i++){
        string word="";
        //sum two word to form two digit words
        word+=getRandomHex();
        word+=getRandomHex();
        content.push_back(word);
    }


}

Certificate::~Certificate(){
    content.clear();
}

void Certificate::display()const{
    for(const string& word:content){
        cout<<word<<" ";
    }
    cout<<endl;
}

int Certificate::similarity(const Certificate& other)const{
    int score=0;
    const vector<string>& otherContent = other.content;

    //loop own word
    for(const string&  ownWord:content){
        for(const string& otherWord:other.content){
            //check if both first word matches
            if(ownWord[0]==otherWord[0]){
                score++;
            }
        }
    }
    return score;
}

const vector<string>& Certificate::getContent() const{
    return content;
}