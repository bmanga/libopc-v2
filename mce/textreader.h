/*
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
/** @file mce/textreader.h
 
 */
#ifndef MCE_TEXTREADER_H
#define MCE_TEXTREADER_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct MCE_TEXTREADER mceTextReader_t;

#ifdef __cplusplus
} /* extern "C" */
#endif


#include <mce/config.h>
#include <opc/opc.h>
#include <mce/helper.h>
#include <libxml/xmlwriter.h>


#ifdef __cplusplus
extern "C" {
#endif

    struct MCE_TEXTREADER {
        xmlTextReaderPtr reader;
        mceCtx_t mceCtx;
    };

    int mceTextReaderRead(mceTextReader_t *mceTextReader);
    int mceTextReaderNext(mceTextReader_t *mceTextReader);
    int mceTextReaderInit(mceTextReader_t *mceTextReader, xmlTextReaderPtr reader);
    int mceTextReaderCleanup(mceTextReader_t *mceTextReader);

    int mceTextReaderDump(mceTextReader_t *mceTextReader, xmlTextWriter *writer);
    int mceTextReaderUnderstandsNamespace(mceTextReader_t *mceTextReader, const xmlChar *ns);
    int mceTextReaderPostprocess(xmlTextReader *reader, mceCtx_t *ctx, int ret);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCE_TEXTREADER_H */
