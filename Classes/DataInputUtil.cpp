#include "DataInputUtil.h"
#include "cocos2d.h"

int DataInputUtil::readByte()
{
	char ch = in.front();
	in.pop_front();
	return ch;
}
int DataInputUtil::readInt()
{
	int ch1 = in.front();
	in.pop_front();
    int ch2 = in.front();
	in.pop_front();
    int ch3 = in.front();
	in.pop_front();
    int ch4 = in.front();
	in.pop_front();
    return ((ch1 << 24) + (ch2 << 16) + (ch3 << 8) + (ch4 << 0));
}
bool DataInputUtil::readBoolean()
{
	int ch = in.front();
	in.pop_front();
	return (ch != 0);
}
int DataInputUtil::readShort()
{
	int ch1 = in.front();
	in.pop_front();
    int ch2 = in.front();
	in.pop_front();
    return (ch1 << 8) + (ch2 << 0);
}
unsigned long long DataInputUtil::readLong()
{
	int ch1 = in.front();
	in.pop_front();
	int ch2 = in.front();
	in.pop_front();
	int ch3 = in.front();
	in.pop_front();
	int ch4 = in.front();
	in.pop_front();
	int ch5 = in.front();
	in.pop_front();
	int ch6 = in.front();
	in.pop_front();
	int ch7 = in.front();
	in.pop_front();
	int ch8 = in.front();
	in.pop_front();
	return (((unsigned long long)ch1 << 56)
		+ ((unsigned long long)(ch2 & 255) << 48)
		+ ((unsigned long long)(ch3 & 255) << 40)
		+ ((unsigned long long)(ch4 & 255) << 32)
		+ ((unsigned long long)(ch5 & 255) << 24)
		+ ((ch6 & 255) << 16)
		+ ((ch7 & 255) <<  8)
		+ ((ch8 & 255) <<  0));
}
std::string DataInputUtil::readUTF()
{
	std::string str;
	int utflen = readShort();
	for (int i = 0; i < utflen; i++) {
		str.push_back(in.front());
		in.pop_front();
	}
	return str;
}
void DataInputUtil::readFully(char c[], int off, int len)
{
	int size = off + len;
	for (int i = off; i < size; i++) {
		c[i] = in.front();
		in.pop_front();
	}
}
DATALIST* DataInputUtil::getDatas()
{
	return &in;
}
void DataInputUtil::putDatas(const char c[], int len)
{
	for (int i = 0; i < len; i++) {
		in.push_back(c[i]);
	}
}

