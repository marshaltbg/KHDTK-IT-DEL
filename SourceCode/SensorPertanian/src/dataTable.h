#ifndef _DATA_TABLE_H_
#define _DATA_TABLE_H_

#include <Arduino.h>

#include "soil_data.h"

struct SoilReading {
    unsigned long epoch;
    SoilData soilData;
};


class SoilDataTable {
private:
    static const int MAX_SIZE = 235;

    SoilReading readings[MAX_SIZE];
    int idx_in;
    int idx_out;
    int count;

public:
    SoilDataTable();
    // TODO: NTP server, pengambilan timestamp
    bool push(const SoilData& soilData, const unsigned long epoch);
    bool push(const SoilReading& soilReading);
    bool pop(SoilData& soilData, unsigned long& epoch);
    bool pop(SoilReading& soilReading);
    bool is_empty();
    bool is_full();
    int get_count();
    void clear();
    void inc_idx(int& idx);
    void dec_idx(int& idx);
};


#endif