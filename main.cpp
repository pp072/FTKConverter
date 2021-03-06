#include "utils.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <map>
#include "Convert.h"
using namespace std ;

#define stop __asm nop

int main(int argc, char **argv)
{

	log(L"��������� XSI ASCII-������");
	log(L"������ 0.0.1");
	log(L"");

	if( argc < 2 )
	{
		log( L"����������" );
		log( L"DotXSI converter inputFile [-o outputName] [-s shaderName] [-noopt]" );
		log( L"" );
		log( L"inputFile:      ��� DotXSI �����" );
		log( L"-o outputName:  ��� ���������� �����" );
		log( L"-s shaderName:  ��� �������" );
		log( L"-noopt:         ��������� ����������� ���������" );
		log( L"-anim:          ������� ������ ��������" );
		return 0;
	}


	string inName= argv[1];
	string outName = extractFileName( inName, false );
	string defShader = "standard.shader.xml";
	bool optimize = true, animsOnly = false;


	for( int i = 2; i < argc; ++i )
	{
		if( strcmp( argv[i], "-o" ) == 0 )
		{
			if( argc > i + 1 )
			{	
				outName = argv[++i];
			}
			else
			{
				log( L"������������ ���������" );
				return 0;
			}
		}
		else if( strcmp( argv[i], "-s" ) == 0 )
		{
			if( argc > i + 1 )
			{
				defShader = argv[++i];
			}
			else
			{
				log( L"������������ ���������" );
				return 0;
			}
		}
		else if( strcmp( argv[i], "-noopt" ) == 0 )
		{
			optimize = false;
		}
		else if( strcmp( argv[i], "-anim" ) == 0 )
		{
			animsOnly = true;
		}
		else
		{
			//log( L"������������ ���������" );
			//return 0;
		}
	}

	Convert *ColladaDoc = new Convert();

	if( !ColladaDoc->parse( inName ) )
	{
			return 0;
	}
	else
	{
		log( L"������ ��������" );
	}

	if( !animsOnly )
	{
		stop
			log( L"������ ���������..." );
		ColladaDoc->saveModel(outName);

 		log( L"������ ����������..." );
 		ColladaDoc->writeMaterials(  outName, defShader );
	}
 	if( ColladaDoc->hasAnimation() )
 	{
 		log( L"������ ��������..." );
 		ColladaDoc->writeAnimation( outName );
 		//log( "Done." );
 	}
	log( L"������ ���������" );



 	
	return 0;
}