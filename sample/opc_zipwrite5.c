/**
 Copyright (c) 2010, Florian Reuter
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without 
 modification, are permitted provided that the following conditions 
 are met:
 
 * Redistributions of source code must retain the above copyright 
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright 
 notice, this list of conditions and the following disclaimer in 
 the documentation and/or other materials provided with the 
 distribution.
 * Neither the name of Florian Reuter nor the names of its contributors 
 may be used to endorse or promote products derived from this 
 software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
 OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <opc/opc.h>
#include <stdio.h>
#include <string.h>

int main( int argc, const char* argv[] )
{
	if (opcInitLibrary()) {
		char buf[500];
		memset(buf, 'X', sizeof(buf));
		opcZip *zip=opcZipOpenFile(_X("sample5.zip"), OPC_ZIP_WRITE);
		opcZipWriteStart(zip);
		opcZipPartInfo spinePart1;
		opcZipWriteOpenPart(zip, &spinePart1, _X("spine.xml/[0].last.piece"), 500);
		opcZipWritePartData(zip, &spinePart1, buf, 100);
		
		opcZipPartInfo page0Part;
		opcZipWriteOpenPart(zip, &page0Part, _X("pages/page0.xml/[0].last.piece"), 500);
		opcZipWritePartData(zip, &page0Part, buf, 100);
		opcZipWriteClosePart(zip, &page0Part, _X("pages/page0.xml"));

		opcZipWritePartData(zip, &spinePart1, buf, 400);
		opcZipWriteClosePart(zip, &spinePart1, _X("spine.xml/[0].piece"));
		
		opcZipPartInfo spinePart2;
		opcZipWriteOpenPart(zip, &spinePart2, _X("spine.xml/[1].last.piece"), 500);
		opcZipWritePartData(zip, &spinePart2, buf, 100);

		opcZipPartInfo page1Part;
		opcZipWriteOpenPart(zip, &page1Part, _X("pages/page1.xml/[0].last.piece"), 500);
		opcZipWritePartData(zip, &page1Part, buf, 100);
		opcZipWriteClosePart(zip, &page1Part, _X("pages/page1.xml"));
		
		opcZipWritePartData(zip, &spinePart2, buf, 400);		
		opcZipWriteClosePart(zip, &spinePart2, _X("spine.xml/[1].piece"));

		opcZipPartInfo spinePart3;
		opcZipWriteOpenPart(zip, &spinePart3, _X("spine.xml/[2].last.piece"), 500);
		opcZipWritePartData(zip, &spinePart3, buf, 100);
		opcZipWriteClosePart(zip, &spinePart3, NULL);
		
		opcZipWriteStartDirectory(zip);
		opcZipWriteDirectoryEntry(zip, &spinePart1);
		opcZipWriteDirectoryEntry(zip, &page0Part);
		opcZipWriteDirectoryEntry(zip, &spinePart1);							 
		opcZipWriteDirectoryEntry(zip, &page1Part);
		opcZipWriteDirectoryEntry(zip, &spinePart2);							 
		opcZipWriteEndDirectory(zip);
		opcZipClose(zip);
		opcZipCleanupPartInfo(&spinePart1);
		opcZipCleanupPartInfo(&page0Part);		
		opcZipCleanupPartInfo(&spinePart1);		
		opcZipCleanupPartInfo(&page1Part);		
		opcZipCleanupPartInfo(&spinePart2);		
		opcFreeLibrary();
	}
	return 0;	
}

