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
#include <mce/textwriter.h>
#include <stdio.h>
#ifdef WIN32
#include <crtdbg.h>
#endif

#include <opc/opc.h>

const char v1_ns[]="http://schemas.openxmlformats.org/Circles/v1";
const char v2_ns[]="http://schemas.openxmlformats.org/Circles/v2";
const char v3_ns[]="http://schemas.openxmlformats.org/Circles/v3";

/*
 Produces sample 10-3 from ISO-IEC-29500 Part 3:
 
 <Circles xmlns="http://schemas.openxmlformats.org/Circles/v1" 
          xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
          xmlns:v2="http://schemas.openxmlformats.org/Circles/v2" 
          mc:Ignorable="v2" 
          mc:ProcessContent="v2:Blink" > 
  <v2:Watermark Opacity="v0.1"> 
   <Circle Center="0,0" Radius="20" Color="Blue" /> 
   <Circle Center="25,0" Radius="20" Color="Black" /> 
   <Circle Center="50,0" Radius="20" Color="Red" /> 
  </v2:Watermark> 
  <v2:Blink> 
   <Circle Center="13,0" Radius="20" Color="Yellow" /> 
   <Circle Center="38,0" Radius="20" Color="Green" /> 
  </v2:Blink> 
 </Circles> 
 
 */

int main( int argc, const char* argv[] )
{
#ifdef WIN32
     _CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    if (OPC_ERROR_NONE==opcInitLibrary()) {
        if (2==argc) {
            opcContainer *c=opcContainerOpen(BAD_CAST(argv[1]), OPC_OPEN_WRITE_ONLY, NULL, NULL);
            opcExtensionRegister(c, BAD_CAST("xml"), BAD_CAST("text/xml"));
            opcPart part=opcPartCreate(c, BAD_CAST("sample.xml"), NULL, 0);
            mceTextWriter *w=mceTextWriterOpen(c, part, OPC_COMPRESSIONOPTION_FAST);
            mceTextWriterStartDocument(w);
            mceTextWriterRegisterNamespace(w, BAD_CAST(v1_ns), NULL, MCE_DEFAULT);
            mceTextWriterRegisterNamespace(w, BAD_CAST(v2_ns), BAD_CAST("v2"), MCE_IGNORABLE);
            mceTextWriterProcessContent(w, BAD_CAST(v2_ns), BAD_CAST("Blink"));
            mceTextWriterStartElement(w, BAD_CAST(v1_ns), BAD_CAST("Circles"));
            mceTextWriterStartElement(w, BAD_CAST(v2_ns), BAD_CAST("Watermark"));
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Opacity"), "v0.1");    
            mceTextWriterStartElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Center"), "0,0");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Radius"), "20");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Color"), "Blue");
            mceTextWriterEndElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterStartElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Center"), "25,0");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Radius"), "20");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Color"), "Black");
            mceTextWriterEndElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterStartElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Center"), "50,0");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Radius"), "20");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Color"), "Red");
            mceTextWriterEndElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterEndElement(w, BAD_CAST(v2_ns), BAD_CAST("Watermark"));

            mceTextWriterStartElement(w, BAD_CAST(v2_ns), BAD_CAST("Blink"));
            mceTextWriterStartElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Center"), "13,0");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Radius"), "20");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Color"), "Yellow");
            mceTextWriterEndElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterStartElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Center"), "38,0");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Radius"), "20");
            mceTextWriterAttributeF(w, BAD_CAST(v1_ns), BAD_CAST("Color"), "Green");
            mceTextWriterEndElement(w, BAD_CAST(v1_ns), BAD_CAST("Circle"));
            mceTextWriterEndElement(w, BAD_CAST(v2_ns), BAD_CAST("Blink")); 
                
            mceTextWriterEndElement(w, BAD_CAST(v1_ns), BAD_CAST("Circles"));
            mceTextWriterEndDocument(w);
            mceTextWriterFree(w);
            opcContainerClose(c, OPC_CLOSE_NOW);
        } else {
            printf("mce_write sample.zip\n");
        }
        opcFreeLibrary();
    }
    return 0;
}
