#include <iostream>
#include <ctime>
#include "Certificate.h"
#include "DocumentHandler.h"

using namespace std;
int getValidInput(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value) || value <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(); 
    }
    return value;
}
int main(){
    srand(static_cast<unsigned>(time(0)));
    int numCertificates, numWords;

    numCertificates = getValidInput("Enter the number of certificates: ");
    numWords = getValidInput("Enter the words per certificate: ");
    

    DocumentHandler<Certificate> handler;

    // Generate Certificates
    for (int i = 0; i < numCertificates; ++i) {
        Certificate cert(numWords);
        handler.addDocument(cert);
    }

    handler.displayAll();
    handler.minSimilarity();
    handler.digitStatistics();

    return 0;
}