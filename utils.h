#pragma once
#include <string>
#include "CMathE.h"
using namespace std;


void log( const wstring &msg );
void log( const string &msg );
wstring extractFileName( const wstring &fullPath, bool extension );
string extractFileName( const string &fullPath, bool extension );
string extractFilePath( const string &fullPath );
char* wtoc(const wchar_t* w, size_t max);
wchar_t* ctow(const char* c, size_t max);
void removeGate( string &s );
bool parseString( char *s, unsigned int &pos, string &token );
bool parseFloat( char *s, unsigned int &pos, float &value );
bool parseUInt( char *s, unsigned int &pos, unsigned int &value );
Matrix4f makeMatrix4f( float *floatArray16, bool y_up );
int StrCompare(char* a, char* b) ;
bool StrFind(char* a, char* b);


