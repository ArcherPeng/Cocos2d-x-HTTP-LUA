#include "DataUtil.h"
DataInputUtil * DataUtil::input = nullptr;

DataInputUtil * DataUtil::getDataInputUtil()
{
    return DataUtil::input;
}
void DataUtil::setDataInputUtil(DataInputUtil *  inp)
{
     DataUtil::input = inp;
}