#include "../src/test.h"
#include <string.h>
#include <iostream>
using namespace std;
test::test()
{

}


void test::onMessage(char* topic, char* msgContent, int msgLen ){
    char message[1000]="";
    strncpy(message,msgContent,msgLen);
    cout << "onMQTTMessage: " << message << endl;
}
