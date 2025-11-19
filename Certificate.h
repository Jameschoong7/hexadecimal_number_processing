#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Certificate{
    private:
        vector<string> content;
        int length;


    public:
        Certificate();

        Certificate(int len);
        
        ~Certificate();

        //display function
        void display() const;
        
        //similarity function
        int similarity(const Certificate& other)const;

        const vector<string>& getContent()const;

};