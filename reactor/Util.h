#ifndef _UTIL_H_
#define _UTL_H_
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <sstream>
using namespace std;
namespace Util
{
string ConstructPath(const string &path);
string GetExtent(const string &path);
void GetContentType(const string &tmpExtension, string &contentType);
string GetContent(const string &);
string GetImage(const string &);
}

#endif
