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
/*
    Dump all information about an OPC container.

    Ussage:
    opc_dump FILENAME

    Sample:
    opc_dump OOXMLI1.docx
*/

#include <opc++/opc.hpp>
#include <iostream>
#include <ctime>

int main( int argc, const char* argv[] )
{
  time_t start_time=time(NULL);
  opc::initLibrary();
  if (argc == 2) {
    opc::Container c(argv[1], OPC_OPEN_READ_ONLY);
    if (c.is_open()) {
      c.dump(std::cout);
    }
    else {
      std::cout << "File could not be opened\n";
    }
  }
  else {
    std::cout << "opc_dump FILENAME.\n\n";
    std::cout << "Sample: opc_dump test.docx\n";
  }
  opc::freeLibrary();
  time_t end_time=time(NULL);
  fprintf(stderr, "time %.2lfsec\n", difftime(end_time, start_time));
}

