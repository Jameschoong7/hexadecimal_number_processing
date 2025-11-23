#include <iostream>
#include <ctime>
#include "Certificate.h"
#include "DocumentHandler.h"

using namespace std;

int main(){

    int numCertificates, numWords;

    cout << "Enter the number of certificates: ";
    cin >> numCertificates;
    cout << "Enter the words per certificate: ";
    cin >> numWords;

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