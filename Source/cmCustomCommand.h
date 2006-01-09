/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmCustomCommand_h
#define cmCustomCommand_h

#include "cmStandardIncludes.h"

/** \class cmCustomCommand
 * \brief A class to encapsulate a custom command
 *
 * cmCustomCommand encapsulates the properties of a custom command
 */
class cmCustomCommand
{
public:
  /** Default and copy constructors for STL containers.  */
  cmCustomCommand();
  cmCustomCommand(const cmCustomCommand& r);

  /** Main constructor specifies all information for the command.  */
  cmCustomCommand(const char* output,
                  const std::vector<std::string>& depends,
                  const cmCustomCommandLines& commandLines,
                  const char* comment);

  /** Get the output file produced by the command.  */
  const char* GetOutput() const;

  /** Get the vector that holds the list of dependencies.  */
  const std::vector<std::string>& GetDepends() const;

  /** Get the list of command lines.  */
  const cmCustomCommandLines& GetCommandLines() const;

  /** Get the comment string for the command.  */
  const char* GetComment() const;

  /** set get the used status of the command */ 
  void Used() { m_Used = true;}; 
  bool IsUsed() { return m_Used;};
 
private:
  std::string m_Output;
  std::vector<std::string> m_Depends;
  cmCustomCommandLines m_CommandLines;
  std::string m_Comment;
  bool m_Used;
};

#endif
