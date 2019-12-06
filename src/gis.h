#ifndef GIS_H
#define GIS_H
#include "raum.h"
#include "behandlung.h"
#include <mysql/mysql.h>

class GIS
{
public:
    GIS();
    ~GIS();
    /* @brief Über den zweck/die behandlung wird der dafür vorgesehene Raum
     *        ermittelt und zurückgegeben
     * @param [in] zweck/behandlung
     * @return ein Raum, in dem die Behandlung durchgefuehrt werden kann
     */
    Raum getRaumByBehandlung(Behandlung b);
private:
    void finish_with_error(MYSQL *con);
    Raum getRaumByID(unsigned int id);
    MYSQL* m_connection;
};

#endif // GIS_H
