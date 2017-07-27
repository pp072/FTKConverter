
#include "utils.h"
#include <iostream>
#include <windows.h>
using namespace std;

#define stop __asm nop

void log( const wstring &msg )
{
	char buff1[260];

	CharToOem(msg.c_str(), (LPSTR)buff1); 
	//SetConsoleOutputCP(1251);

	printf(buff1);
	printf("\n");

	OutputDebugString(msg.c_str());
	OutputDebugString( L"\n" );

	stop
}
void log( const string &msg )
{
	cout<<msg<<endl;
	OutputDebugStringW((LPCWSTR)msg.c_str());
	OutputDebugString( (LPCWSTR)"\n" );
	stop
}
wstring extractFileName( const wstring &fullPath, bool extension )
{
	int first = 0, last = (int)fullPath.length() - 1;

	for( int i = last; i >= 0; --i )
	{
		if( fullPath[i] == '.' )
		{
			last = i;
		}
		else if( fullPath[i] == '\\' || fullPath[i] == '/' )
		{
			first = i + 1;
			break;
		}
	}

	if( extension )
		return fullPath.substr( first, fullPath.length() - first );
	else
		return fullPath.substr( first, last - first );
}
string extractFileName( const string &fullPath, bool extension )
{
	int first = 0, last = (int)fullPath.length() - 1;

	for( int i = last; i >= 0; --i )
	{
		if( fullPath[i] == '.' )
		{
			last = i;
		}
		else if( fullPath[i] == '\\' || fullPath[i] == '/' )
		{
			first = i + 1;
			break;
		}
	}

	if( extension )
		return fullPath.substr( first, fullPath.length() - first );
	else
		return fullPath.substr( first, last - first );
}

string extractFilePath( const string &fullPath )
{
	int first = 0;
	int last = (int)fullPath.length() - 1;

	for( int i = last; i >= 0; --i )
	{
		if( fullPath[i] == '\\' || fullPath[i] == '/' )
		{
			last = i;
			break;
		}
	}

	return fullPath.substr( first, last );
}

/* wchar_t to char  */
char* wtoc(const wchar_t* w, size_t max)
{
	char* c = new char[max];
	wcstombs(c,w,max);
	return c;
}

/* char to wchar_t */
wchar_t* ctow(const char* c, size_t max)
{
	wchar_t* w = new wchar_t[max];
	mbstowcs(w,c,max);
	return w;
}

void removeGate( string &s )
{
	if( s.length() == 0 ) return;

	if( s[0] == '#' ) s = s.substr( 1, s.length() - 1 );
}
bool parseString( char *s, unsigned int &pos, string &token )
{
	token = "";
	token.reserve( 16 );

	s += pos;

	// End of string?
	if( *s == 0x0 ) return false;

	// Skip whitespaces
	while( *s != 0x0 )
	{
		if (strchr(" \t\n\r", *s) == 0x0) break;
		++s; ++pos;
	}

	// End of string?
	if( *s == 0x0 ) return false;

	// Copy token
	while (*s != 0x0)
	{
		if (strchr(" \t\n\r", *s) != 0x0) break;

		token += *s++; ++pos;
	}

	return true;
}


bool parseFloat( char *s, unsigned int &pos, float &value )
{
	string token;

	if( !parseString( s, pos, token ) ) return false;

	value = (float)atof( token.c_str() );

	return true;
}
bool parseUInt( char *s, unsigned int &pos, unsigned int &value )
{
	string token;

	if( !parseString( s, pos, token ) ) return false;

	value = (unsigned int)atoi( token.c_str() );

	return true;
}
//Matrix4f makeMatrix4f( float *floatArray16, bool y_up )
//{
//
//	Matrix4f mat( floatArray16 );
//	mat = mat.transposed();
//
//	// Flip matrix if necessary
//	if( !y_up )
//	{
//		// Swap y/z rows
//		swap( mat.c[0][1], mat.c[0][2] );
//		swap( mat.c[1][1], mat.c[1][2] );
//		swap( mat.c[2][1], mat.c[2][2] );
//		swap( mat.c[3][1], mat.c[3][2] );
//
//		// Swap y/z columns
//		swap( mat.c[1][0], mat.c[2][0] );
//		swap( mat.c[1][1], mat.c[2][1] );
//		swap( mat.c[1][2], mat.c[2][2] );
//		swap( mat.c[1][3], mat.c[2][3] );
//
//		// Invert z-axis to make system right-handed again
//		// (The swapping above results in a left-handed system)
//		mat.c[0][2] *= -1;
//		mat.c[1][2] *= -1;
//		mat.c[3][2] *= -1;
//		mat.c[2][0] *= -1;
//		mat.c[2][1] *= -1;
//		mat.c[2][3] *= -1;
//	}
//
//	return mat;
//}
int StrCompare(char* a, char* b)  
{
	while (1)
	{
		if (*a==0) return 5;  // 5 если равны и первая строка закончилась
		if (*b==0) return 7;  // 7 если равны и вторая строка закончилась
		if (*a!=*b)
		{
			// 0 если строки не равны
			if (    ((*a)>='a')&&((*a)<='z')&&(*a!=((*b)+('a'-'A'))) ||
				((*a)>='A')&&((*a)<='Z')&&(*a!=((*b)-('a'-'A'))) )  return 0;            
		}
		a++; b++;
	}
}

bool StrFind(char* a, char* b)
{
	int i,cnt;
	char *tmp;
	if (strlen(a)<strlen(b));
	else {tmp=a;a=b;b=tmp; };
	i=strlen(b)-strlen(a);
	for (cnt=0;cnt<=i;cnt++)
	{
		if (StrCompare(a,b)>0) return true; //содержит
		b++;
	}
	return false;  // не содержит
}