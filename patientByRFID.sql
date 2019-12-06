SELECT idPatienten FROM pdsDB.Patient WHERE RFIDUID='12345678';
SELECT * FROM pdsDB.Patient_has_Behandlung WHERE Patient_idPatienten = '21101963';