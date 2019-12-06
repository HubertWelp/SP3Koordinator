#ifndef KIS_H
#define KIS_H
#include <mysql/mysql.h>
#include "patient.h"

class KIS
{
public:
    KIS();
    ~KIS();
    /* @brief Rückabe eines object der Klasse Patient
     *        über RFID
     * @param [in] RFID
     * @return [out] Objekt der Klasse Patient
     */
   Patient getPatientByRFID(unsigned long long RFID);

private:
   void finish_with_error(MYSQL *con);
   Behandlung getBehandlungByID(unsigned int id);
   MYSQL* m_connection;
};

#endif // KIS_H
