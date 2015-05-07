#include "DataOutputUtil.h"
#include "cocos2d.h"



void DataOutputUtil::write(unsigned char* v, unsigned long size)
{
	for (unsigned long i = 0; i < size; i++) {
		out.push_back(v[i]);
	}
}
void DataOutputUtil::writeByte(const int v)
{
	out.push_back(v);
}
void DataOutputUtil::writeInt(const int v)
{
	out.push_back((v >> 24) & 0xFF);
	out.push_back((v >> 16) & 0xFF);
	out.push_back((v >>  8) & 0xFF);
	out.push_back((v >>  0) & 0xFF);
}
void DataOutputUtil::writeBoolean(const bool v)
{
	out.push_back(v ? 1 : 0);
}
void DataOutputUtil::writeShort(const int v)
{
	out.push_back((v >> 8) & 0xFF);
    out.push_back((v >> 0) & 0xFF);
}
void DataOutputUtil::writeLong(const unsigned long long v)
{
	out.push_back((v >> 56) & 0xFF);
	out.push_back((v >> 48) & 0xFF);
	out.push_back((v >> 40) & 0xFF);
	out.push_back((v >> 32) & 0xFF);
	out.push_back((v >> 24) & 0xFF);
	out.push_back((v >> 16) & 0xFF);
	out.push_back((v >>  8) & 0xFF);
	out.push_back((v >>  0) & 0xFF);
}
void DataOutputUtil::writeUTF(const std::string &v, bool c)
{
	std::string str = v;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	 if (c)
		str = StringUtil::string2UTF8(v);
#endif
	const char *arr = str.c_str();
	int utflen = static_cast<int>(strlen(arr));

	writeShort(utflen);
	for (int i = 0; i < utflen; i++) {
		out.push_back(arr[i]);
	}

}
DATALIST* DataOutputUtil::getDatas()
{
	return &out;
}
void DataOutputUtil::clear()
{
//	return out.clear();
}