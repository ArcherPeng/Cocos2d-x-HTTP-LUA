#ifndef __DATA_UTIL_H__
#define __DATA_UTIL_H__

#include "DataInputUtil.h"
#include "DataOutputUtil.h"

class DataUtil
{
protected:
    static DataInputUtil * input;
public:
    static DataInputUtil * getDataInputUtil();
    static void setDataInputUtil( DataInputUtil * inp);
};


#endif