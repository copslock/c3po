/*
* Copyright 2019-present Open Networking Foundation
* Copyright (c) 2017 Sprint
*
* SPDX-License-Identifier: Apache-2.0
*/

#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <stdint.h>
#include <string>

class Options
{
public:
   static bool parse( int argc, char **argv );

   static const std::string &originHost()             { return singleton().m_originhost; }
   static const std::string &originRealm()            { return singleton().m_originrealm; }
   static const std::string &diameterConfiguration()  { return singleton().m_fdcfg; }

   static const int logMaxSize()                      { return singleton().m_logmaxsize; }
   static const int logNumberFiles()                  { return singleton().m_lognbrfiles; }
   static const std::string &logFilename()            { return singleton().m_logfilename; }
   static const int logQueueSize()                    { return singleton().m_logqueuesize; }

private:
   enum OptionsSelected {
     opt_jsoncfg               = 0x00000001,
     opt_originhost            = 0x00000002,
     opt_originrealm           = 0x00000004,
     opt_fdcfg                 = 0x00000008,
     opt_logmaxsize            = 0x00000040,
     opt_lognbrfiles           = 0x00000080,
     opt_logfilename           = 0x00000100,
     opt_logqueuesize          = 0x00000200
   };

   static Options *m_singleton;
   static Options &singleton() { if ( !m_singleton ) m_singleton = new Options(); return *m_singleton; }
   static void help();

   Options();
   ~Options();

   bool parseInputOptions( int argc, char **argv );
   bool parseJson();
   bool validateOptions();

   int m_options;

   std::string m_jsoncfg;
   std::string m_originhost;
   std::string m_originrealm;
   std::string m_fdcfg;

   int m_logmaxsize;
   int m_lognbrfiles;
   std::string m_logfilename;
   int m_logqueuesize;
};

#endif // #define __OPTIONS_H
