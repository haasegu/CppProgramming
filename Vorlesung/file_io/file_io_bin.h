#pragma once

#include <cstdio>          // FILE
#include <string>
#include <vector>
//using namespace std;


/**
  This function opens the binary file named @p file_name and reads the
  double data into the C++ vector @p v.
  If the file  @p file_name does not exist then the code stops with an appropriate message.
  @param[in]    file_name   name of the binary file
  @param[out]   v           C++ vector with double values
*/

void read_vector_from_binfile(const std::string& file_name, std::vector<double>& v);
void read_vector_from_binfile_C(const std::string& file_name, std::vector<double>& v);


/**
  This function opens the binary file named @p file_name and rewrites its with the
  double data from the C++ vector @p v.
  If there are problems in opening/generating file  @p file_name
  then the code stops with an appropriate message.
  @param[in]    file_name   name of the binary file
  @param[in]    v           C++ vector with double values
*/

void write_vector_to_binfile(const std::string& file_name, const std::vector<double>& v);
void write_vector_to_binfile_C(const std::string& file_name, const std::vector<double>& v);

/**
  Fills the double-vector @p v with data from an input stream @p istr until this input stream
  ends regularily. The vector is cleared and its memory is automatically allocated.
  @param[in]    istr        input stream
  @param[out]    v           C++ vector with double values
  @warning     An exception is thrown in case of wrong data format or corrupted data.
*/
void binfill_vector(std::istream& istr, std::vector<double>& v);
void binfill_vector_C(FILE* istr, std::vector<double>& v);
