#pragma once                 // substitutes header guarding

#include <array>
#include <string>
#include <vector>

/**
  This function opens the ASCII-file named @p file_name and reads the
  int data into the C++ vector @p v.
  If the file  @p file_name does not exist then the code stops with an appropriate message.
  @param[in]    file_name   name of the ASCII-file
  @param[out]   v           C++ vector with edge vertices
*/

void read_edges_from_file(const std::string& file_name, std::vector<std::array<int,2>>& v);


/**
  Determines the neighboring vertices for each node from the edge definition @p edges .
  The node itself is not contained in the neighboring vertices.

  @param[in]    edges   vector[ne][2] with edge vertices
  @return       vector[nn][*] with all neighboring vertices for each node
  
  @warning We assume that the nodes are continuously numbered from 0 to nn-1. 
           Otherwise we have to use map< int, vector<int> > as data structure.
*/
std::vector<std::vector<int>> get_node2nodes(std::vector<std::array<int,2>> const & edges);


