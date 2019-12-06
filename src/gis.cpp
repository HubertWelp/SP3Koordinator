#include "gis.h"
#include <string.h>
#include <iostream>

GIS::GIS()
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

GIS::~GIS()
{
    // Close connection to Database
    mysql_close(m_connection);
}

Raum GIS::getRaumByBehandlung(Behandlung b)
{
    Raum raum;

    char queryString[1000];
    MYSQL_RES *result;
    MYSQL_ROW row;
    unsigned int num_fields;

    /**** Query Raum-Ids zu einer Behandlung ****/
    sprintf(queryString,"SELECT Raum_idRaum FROM Raum_has_Behandlung WHERE Behandlung_idBehandlung='%u'",b.getID());
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
        unsigned int rID;
        rID=atoi(row[0]);
        raum = getRaumByID(rID);
    }

    mysql_free_result(result);

    raum.setVerwendung(b.getBezeichnung());

    return raum;
}



void GIS::finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

Raum GIS::getRaumByID(unsigned int id)
{

    char queryString[1000];
    MYSQL_RES *result;
    MYSQL_ROW row;
    unsigned int num_fields;
    Raum raum;

    /**** Query Raum ****/
    sprintf(queryString,"SELECT * FROM Raum WHERE idRaum='%u'",id);
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
        if(!row[1])
            raum.setGebaeudeNummer(-1);
        else
            raum.setGebaeudeNummer(atoi(row[1]));
        if(!row[2])
            raum.setRaumNummer(-1);
        else
            raum.setRaumNummer(atoi(row[2]));
        Koordinaten koord;
        setlocale(LC_NUMERIC,"C");
        koord.x = atof(row[3]);
//        setlocale(LC_NUMERIC,"C");
        koord.y = atof(row[4]);
//        printf("x=%f  y=%f\n",koord.x,koord.y);
//        std::cout << "x=" << koord.x << "  y=" << koord.y << std::endl;
        raum.setKoordinaten(koord);
    }

    mysql_free_result(result);

    raum.setVerwendung("");
    return raum;


}
