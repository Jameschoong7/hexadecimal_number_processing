#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

//template class
template<typename T>
class DocumentHandler{
    private:
        vector<T> documents; //container

    public:
        DocumentHandler(){}

        ~DocumentHandler(){
            documents.clear();
        }

        //add a document to container
        void addDocument(const T& doc){
            documents.push_back(doc);
        }

        //display all document from container
        void displayAll(){
            for(int i =0; i<documents.size();i++){
                cout<<"Certificate "<<(i+1)<<": ";
                documents[i].display();
            }
        }

        //Calculate minimum number of similarity
        void minSimilarity(){
            if(documents.size()<2){
                cout<<"Minimum 2 record for comparison\n";
                return;
            }

            //start with high number to dertermine lowest easier
            int minSim = INT32_MAX; 

            //compare every doc
            for(size_t i =0; i<documents.size();i++){
                for(size_t j= i+1;j<documents.size();j++){

                    //call similarity function
                    int sim = documents[i].similarity(documents[j]);
                    if(sim<minSim){
                        minSim = sim;
                    }
                        
                }
                
            }
            cout<<"Minimum Similarity: "<<minSim<<endl;
        }

        //digit statistics
        void digitStatistics() const{
            map<char,int> frequency;
            const char hexDigit[]="0123456789ABCDEF";

            //initialize each digit map
            for(int i=0;i<16;i++){
                frequency[hexDigit[i]]=0;
            }

            //iterate all documents
            for(const T& doc:documents){
                //docuement must have getContent() that return vector<string>
                for(const string& word:doc.getContent()){
                    for(char digit:word){
                        frequency[toupper(digit)]++;
                    }
                }
            }

            //find max and min
            int minCount = INT32_MAX;
            int maxCount = INT32_MIN;

            for(auto const& [key,val] : frequency){
                if(val<minCount)
                    minCount = val;
                if(val>maxCount)
                    maxCount = val;
            }

            //less frequent
            cout<<"Less frequent digits with count: "<<endl;
            for(auto const& [key,val]:frequency){
                if(val == minCount && val>0){
                    cout<<key<<" : "<<val<<endl;
                }
            }

            //most frequent
            cout<<"Most frequent digits with count: "<<endl;
            for(auto const& [key,val]:frequency){
                if(val == maxCount){
                    cout<<key<<" : "<<val<<endl;
                }
            }

        }
    



};