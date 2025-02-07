#include "file_io_bin.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

//----------------------------------------------------------------------
// C++ interface: 
//   https://stackoverflow.com/questions/11249859/how-to-save-a-byte-type-char-array-data-to-a-file-in-c
//

// [Str10, p.364]
void binfill_vector(istream& istr, vector<double>& v)
{
    double d=0;
    char* const pbuffer= reinterpret_cast<char*>(&d);     // memory address of d
    while ( istr.read(pbuffer,sizeof(d))) {v.push_back(d);} // Einlesen
    if (!istr.eof())
    { // Fehlerbehandlung
        cout << " Error handling \n";
        if ( istr.bad() )  {throw runtime_error("Schwerer Fehler in istr");}
        if ( istr.fail() )   // Versuch des Aufraeumens
        {
            cout << " Failed in reading all data.\n";
            istr.clear();
        }
    }
    v.shrink_to_fit();                 // C++11
}


void read_vector_from_binfile(const string& file_name, vector<double>& v)
{
    ifstream fin(file_name,std::ios::binary);           // Oeffne das File im binary-Modus
    if( fin.is_open() )                // File gefunden:
    {
       v.clear();                      // Vektor leeren
       binfill_vector(fin, v);
    }
    else                               // File nicht gefunden:
    {
        cout << "\nFile " << file_name << " has not been found.\n\n" ;
        assert( fin.is_open() && "File not found." );       // exeption handling for the poor programmer
    }
}

void write_vector_to_binfile(const string& file_name, const vector<double>& v)
{
    ofstream fout(file_name,std::ios::binary);          // Oeffne das File im binary-Modus
    if( fout.is_open() )
    {
       size_t const nByte = v.size()*sizeof(v[0]);     // Wieviele Byte will ich schreiben?
       fout.write(reinterpret_cast<const char*>(v.data()),nByte);
    }
    else
    {
        cout << "\nFile " << file_name << " has not been opened.\n\n" ;
        assert( fout.is_open() && "File not opened."  );         // exeption handling for the poor programmer
    }
}

// ---------------------------------------------------------------------
//  C-Interface: https://en.cppreference.com/w/cpp/io/c/fwrite
//
#include <cstdio>          // fwrite

// [Str10, p.364]
void binfill_vector_C(FILE* istr, vector<double>& v)
{
    double d=0;
    char* const pbuffer= reinterpret_cast<char*>(&d);     // memory address of d
    while ( 0!=std::fread(pbuffer, sizeof(d), 1, istr) ) {v.push_back(d);} // Einlesen
    if (0==feof(istr))
    { // Fehlerbehandlung
        cout << " Error handling \n";
        if ( ferror(istr) !=0 ) {throw runtime_error("Schwerer Fehler in istr");}
           // Versuch des Aufraeumens
        {
            cout << " Failed in reading all data.\n";
            clearerr(istr);
        }
    }
    v.shrink_to_fit();                 // C++11
}


void read_vector_from_binfile_C(const string& file_name, vector<double>& v)
{
    std::FILE* fin = std::fopen(file_name.c_str(), "rb");         // Oeffne das File im binary-Modus
    if( fin != nullptr )                // File gefunden:
    {
       v.clear();                      // Vektor leeren
       binfill_vector_C(fin, v);
    }
    else                               // File nicht gefunden:
    {
        cout << "\nFile " << file_name << " has not been found.\n\n" ;
        assert( fin && "File not found." );       // exeption handling for the poor programmer
    }
}

void write_vector_to_binfile_C(const string& file_name, const vector<double>& v)
{
    std::FILE* fout = std::fopen(file_name.c_str(), "wb");         // Oeffne das File im binary-Modus
    if( fout != nullptr)
    {
        std::fwrite(v.data(), sizeof(v[0]), v.size(), fout);
    }
    else
    {
        cout << "\nFile " << file_name << " has not been opened.\n\n" ;
        assert( fout && "File not opened."  );         // exeption handling for the poor programmer
    }
    std::fclose(fout);                                 // don't forget because no desctructor available
}
