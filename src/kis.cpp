#include "kis.h"
#include <iostream>
using namespace std;
KIS::KIS()
{
    // Initialize Connection to Database
    m_connection = mysql_init(nullptr);

    if (m_connection == nullptr)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(m_connection, "localhost", "user12", "user12@thga",
            "pdsDB", 0, nullptr, 0) == nullptr)
    {
        finish_with_error(m_connection);
    }

}

KIS::~KIS()
{
    // Close connection to Database
    mysql_close(m_connection);
}

Patient KIS::getPatientByRFID(unsigned long long RFID)
{
    Patient patient;//Dummy

    char queryString[1000];
    MYSQL_RES *result;
    MYSQL_ROW row;
    unsigned int num_fields;
    int j;

    /**** Query Patient by RFID ****/
    sprintf(queryString,"SELECT * FROM Patient WHERE RFIDUID='%llu'",RFID);
    printf("%s\n",queryString);
    if (mysql_query(m_connection, queryString))
    {
        finish_with_error(m_connection);
    }

    result = mysql_store_result(m_connection);

    if (result == nullptr)
    {
        finish_with_error(m_connection);
    }

    num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)))
    {
        for(unsigned int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
        patient.setID(atoi(row[0]));
        patient.setVorName(string(row[1]));
        patient.setNachName(string(row[2]));
        patient.setRFID(atoll(row[3]));
    }
    mysql_free_result(result);

    /**** Query Behandlungen eines Patienten ****/
    sprintf(queryString,"SELECT * FROM Patient_has_Behandlung WHERE Patient_idPatienten='%u'",patient.getID());
    printf("%s\n",queryString);
    if (mysql_query(m_connection, queryString))
    {
        finish_with_error(m_connection);
    }

    result = mysql_store_result(m_connection);

    if (result == nullptr)
    {
        finish_with_error(m_connection);
    }

    num_fields = mysql_num_fields(result);


    while ((row = mysql_fetch_row(result)))
    {
        for(unsigned int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");

        patient.addBehandlung(getBehandlungByID(atoi(row[1])));
    }

    mysql_free_result(result);

    return patient;
}

void KIS::finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

Behandlung KIS::getBehandlungByID(unsigned int id)
{
    char queryString[1000];
    MYSQL_RES *result;
    MYSQL_ROW row;
    unsigned int num_fields;
    Behandlung behandlung;

    /**** Query Behandlungsbezeichnungen ****/
    sprintf(queryString,"SELECT * FROM Behandlung WHERE idBehandlung='%u'",id);
    printf("%s\n",queryString);
    if (mysql_query(m_connection, queryString))
    {
        finish_with_error(m_connection);
    }

    result = mysql_store_result(m_connection);

    if (result == nullptr)
    {
        finish_with_error(m_connection);
    }

    num_fields = mysql_num_fields(result);



    while ((row = mysql_fetch_row(result)))
    {
        for(unsigned int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
        behandlung.setID(atoi(row[0]));
        behandlung.setBezeichnung(row[1]);
    }

    mysql_free_result(result);

    return behandlung;
}
