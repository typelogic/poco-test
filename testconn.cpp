#include <iostream>
#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/Socket.h"
using namespace std;

class newConnection: public Poco::Net::TCPServerConnection {
public:
    
    newConnection(const Poco::Net::StreamSocket& s) : Poco::Net::TCPServerConnection(s) {
        std::cout << "HERE";

    }

    void run() {
        cout << "New connection from: " << socket().peerAddress().host().toString() <<  endl << flush;
        bool isOpen = true;
        Poco::Timespan timeOut(10,0);
        unsigned char incommingBuffer[1000];
        while(isOpen){
            if (socket().poll(timeOut,Poco::Net::Socket::SELECT_READ) == false){
                cout << "TIMEOUT!" << endl << flush;
            }
            else{
                cout << "RX EVENT!!! ---> "   << flush;
                int nBytes = -1;

                try {
                    nBytes = socket().receiveBytes(incommingBuffer, sizeof(incommingBuffer));
                }
                catch (Poco::Exception& exc) {
                    //Handle your network errors.
                    cerr << "Network error: " << exc.displayText() << endl;
                    isOpen = false;
                }


                if (nBytes==0){
                    cout << "Client closes connection!" << endl << flush;
                    isOpen = false;
                }
                else{
                    cout << "Receiving nBytes: " << nBytes << endl << flush;
                }
            }
        }
        cout << "Connection finished!" << endl << flush;
    }
};

int main(int argc, char** argv) {

    //Create a server socket to listen.
    Poco::Net::ServerSocket svs(1234);

    //Configure some server params.
    Poco::Net::TCPServerParams* pParams = new Poco::Net::TCPServerParams();
    pParams->setMaxThreads(4);
    pParams->setMaxQueued(4);
    pParams->setThreadIdleTime(100);

    //Create your server
    Poco::Net::TCPServer myServer(new Poco::Net::TCPServerConnectionFactoryImpl<newConnection>(), svs, pParams);
    myServer.start();

    while(1);

    return 0;
}
