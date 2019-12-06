#ifndef TEST_H
#define TEST_H


class test
{
public:
    test();
    static void onMessage(char* topic, char* msgContent, int msgLen );
};

#endif // TEST_H
