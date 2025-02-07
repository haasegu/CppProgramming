#pragma once

#include <array>
#include <iostream>
#include <set>                // graph_2
#include <string>
#include <vector>


/**
 * Directed graph class.
 * A better graph class that doesn't requires a consecutive numbering of the vertices.
*/
class graph {
    using Edge=std::array<unsigned int,2>;            // graph_3
public:
    /** \brief Reads edges for graph from file.
     *
     *  If the file  @p file_name does not exist then the code stops with an appropriate message.
     *
     *  A consecutive numbering of the vertices is required.
     *
     * @param[in]    file_name   name of the ASCII-file
     */
    [[maybe_unused]] explicit graph(const std::string &file_name);

    // Rule of five
    graph(graph const & org) = default;
    graph(graph      && org) = default;
    graph& operator=(graph const & rhs) = default;
    graph& operator=(graph      && rhs) = default;
    ~graph()                            = default;

    /**
      Determines the neighboring vertices for each node from the edge definition.
      The node itself is not contained in the neighboring vertices.

      @return       vector[nn][*] with all neighboring vertices for each node
    */
    [[nodiscard]] std::vector<std::vector<unsigned int>> get_node2nodes() const;

    /**
      @return       number of edges
    */
    [[nodiscard]] size_t Nedges() const
    {
        return _edges.size();
    }

    /**
      @return       number of vertices
    */
    [[nodiscard]] size_t Nvertices() const
    {
        return _vertices.size();          // graph_2
    }

     /**
      @return       largest vertex index
    */
    [[nodiscard]] size_t Max_vertex() const             // graph_2
    {
        return _maxvert;
    }

    /** \brief Appends one directed edge to the graph.
     *    The method add only edges that not already contained in the graph.
     *
     * @param[in]    v1   start vertex
     * @param[in]    v2   end vertex
     */
    [[maybe_unused]] bool Append(unsigned int v1, unsigned int v2);     // graph_3
    
     /** \brief Removes one directed edge (@p v1, @p v2) from the graph.
     *    The method add only edges that not already contained in the graph.
     *
     * @param[in]    v1   start vertex
     * @param[in]    v2   end vertex
     * @return True if edge @p e exists in the graph.
     */
     [[maybe_unused]] bool Delete(unsigned int v1, unsigned int v2);     // graph_3

     /** \brief Removes edge @p e from the graph.
     *
     * @param[in]    e   edge
     * @return True if edge @p e exists in the graph.
     */      
    bool Delete(Edge const &e);                        // graph_3  
      
     /** \brief Removes the given edges from the graph.
     *    The method add only edges that not already contained in the graph.
     *
     * @param[in]    v   vector[ne],[2] of edges
     * @warning No message if an edge (@p v[k][1], @p v[k][2]) doesn't exist in the graph.
     */      
    void Delete(std::vector<Edge> const &v);           // graph_3

     /** \brief Prints edges and vertices of the graph
     *
     * @param[in,out] s    output stream
     * @param[in]    rhs   graph
     * @return Output stream.
     */      
    friend std::ostream& operator<<(std::ostream &s, graph const &rhs);

private:
    /**
      Determines the number of vertices from the edge information.
      No consecutive numbering of the vertices required.
    */
    void DetermineNumberVertices();

    std::vector<Edge>         _edges;   /**< stores the two vertices for each edge */
    std::set<unsigned int>    _vertices;/**< stores the vertex indices */
    unsigned int              _maxvert; /**< maximal vertex index */

};
