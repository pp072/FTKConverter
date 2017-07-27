//***************************************************************************************
//
// File supervisor: Robert Belanger
//
// (c) Copyright 2003 Avid Technology, Inc. . All rights reserved.
//
//
// @doc
//
// @module      MemoryFilter.h | Main header file for MemoryFilter implementation
//***************************************************************************************

/****************************************************************************************
THIS CODE IS PUBLISHED AS A SAMPLE ONLY AND IS PROVIDED "AS IS".
IN NO EVENT SHALL SOFTIMAGE, AVID TECHNOLOGY, INC. AND/OR THEIR RESPECTIVE 
SUPPLIERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS CODE . 
 
COPYRIGHT NOTICE. Copyright © 1999-2003 Avid Technology Inc. . All rights reserved. 

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries 
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners. 
****************************************************************************************/

#ifndef _MEMORYFILTER_H_
#define _MEMORYFILTER_H_

#include <SIBCUtil.h>
#include <SIBCString.h>
#include "SIBCArray.h"

#include "CXSIFilter.h"

#define MEMORY_FILTER_NAME		"MEMORY"
#define MEMORY_FILTER_ID		"mem"

#define	BUFFER_SIZE				(128 * 1024)

//! Memory filter.
/* 
* This class will gather up to a certain size of data until it calls its subfilter to
* write or it will read up to a certain size in one go and answer to request until it
* has exhausted the data at which point it will ask its subfilter for more data.
*/
class CMemoryFilter : public CXSIFilter
{
public:
	/*!
	 * Constructor
	*/
	CMemoryFilter();
	/*!
	 * Destructor
	*/
	virtual ~CMemoryFilter();

	/*! Opens the file for either reading or writing
	 * \param in_szFilename	Filename
	 * \param in_Mode	mode
	*/
	int	Open ( CSIBCString in_szFilename,  _SI_FILE_MODE in_Mode );
	/*! Closes the file when finished
	*/
	int	Close ();
	
	/*! Reads a number of bytes into the buffer passed in.
	 * \param out_pBuffer	output buffer
	 * \param in_lSize	number of bytes to read
	 * \return	int		number of bytes read.
	*/
	int Read ( SI_Char * out_pBuffer, SI_Long in_lSize );
	/*! Writes a number of bytes to the file
	 * \param in_pBuffer	input buffer
	 * \param in_lSize	number of bytes to write
	 * \return int		number of bytes written
	*/
	int Write( SI_Char * in_pBuffer,  SI_Long in_lSize );


	/*! Tests whether we have reached the end of file
	 * \return int	flag for end of file (1 - end of file, 0 - not end of file)
	*/
	int Eof();
	/*! Returns the current position in the file.
	 * \returns int	position in the file (0 - beginning)
	*/
	int Tell();

	void WriteHeader();
	void			SetHeader ( CSIBCString in_szHeader );
	CSIBCString		GetHeader () { return GetLastHeader(); }
static				CSIBCString GetLastHeader();
private:
	void	Flush();
	void	FillBuffer();

	char	*m_pBuffer;
	int	m_lPosition;
	SI_Long	m_lSizeRead;
	bool	m_bHeaderSkipped;
	bool	m_bReadMode;
static		SI_Char					m_cHeader[17];
static		CSIBCArray<SI_Char*>	m_blocks;
static		CSIBCArray<SI_Int>		m_blockSize;
	SI_Long	m_lBufIndex;
};

#endif
