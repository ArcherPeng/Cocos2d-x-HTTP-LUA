#ifndef __DataInputUtil_H__
#define __DataInputUtil_H__

//#include "StringUtil.h"
#include <list>
#include "cocos2d.h"
USING_NS_CC;
typedef std::list<unsigned char> DATALIST;

class DataInputUtil:public Ref
{
private:
	DATALIST in;
public:
    static DataInputUtil * create()
    {
        DataInputUtil * diu = new DataInputUtil();
        diu->autorelease();
        return diu;
    }
	int readByte();
	int readInt();
	bool readBoolean();
	int readShort();
	unsigned long long readLong();
	std::string readUTF();
	void readFully(char c[], int off, int len);
	DATALIST* getDatas();
	void putDatas(const char c[], int len);
};
#endif