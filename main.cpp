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

	log(L"Конвертер XSI ASCII-файлов");
	log(L"Версия 0.0.1");
	log(L"");

	if( argc < 2 )
	{
		log( L"Инструкция" );
		log( L"DotXSI converter inputFile [-o outputName] [-s shaderName] [-noopt]" );
		log( L"" );
		log( L"inputFile:      имя DotXSI файла" );
		log( L"-o outputName:  имя выходящего файла" );
		log( L"-s shaderName:  имя шейдера" );
		log( L"-noopt:         отключить оптимизацию геометрии" );
		log( L"-anim:          экспорт только анимации" );
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
				log( L"Неправильные аргументы" );
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
				log( L"Неправильные аргументы" );
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
			//log( L"Неправильные аргументы" );
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
		log( L"Импорт закончен" );
	}

	if( !animsOnly )
	{
		stop
			log( L"Запись геометрии..." );
		ColladaDoc->saveModel(outName);

 		log( L"Запись материалов..." );
 		ColladaDoc->writeMaterials(  outName, defShader );
	}
 	if( ColladaDoc->hasAnimation() )
 	{
 		log( L"Запись анимации..." );
 		ColladaDoc->writeAnimation( outName );
 		//log( "Done." );
 	}
	log( L"Запись завершена" );



 	
	return 0;
}