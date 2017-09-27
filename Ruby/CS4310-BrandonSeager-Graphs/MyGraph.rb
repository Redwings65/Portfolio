require_relative "MyGraph.rb"
require_relative "MyEdge.rb"
require_relative "MyVertex.rb"

class MyGraph
  attr_accessor :label
  #$label = Array.new
  def num_vertices()# - Return the number of vertices in graph G
    print "Number of Vertices = "
    print $label.count() #couns how many vertices there are in G
    print "\n"
  end

  def num_edges()# - Return the number of edges in graph G
    print "Number of Edges = "
    puts $counter
    print "\n"
  end

  def list_vertices()# - Return an array containing all vertices in G
    print "Defined Verticies: "
    print $label
    print "\n"
  end

  def list_edges()# - Return an array containing all edges in G
    print "\nList the Edges:\n"
    i = 0
    while i < $counter/2
      puts $edge[$label[i]]
      i+=1
    end
    print "\n"
  end
end


#this is the script that runs the above
graph = MyGraph.new
vertex = MyVertex.new
$edge = MyEdge.new
$array = Array.new
vertex.new_vertex(1, "HNL")
vertex.new_vertex(2, "LAX")
vertex.new_vertex(3, "SFO")
vertex.new_vertex(4, "ORD")
vertex.new_vertex(5, "DFW")
vertex.new_vertex(6, "LGA")
vertex.new_vertex(7, "MIA")
vertex.new_vertex(8, "PVD")
HNL = $edge.add_node(Node.new($label[0]))
LAX = $edge.add_node(Node.new($label[1]))
SFO = $edge.add_node(Node.new($label[2]))
ORD = $edge.add_node(Node.new($label[3]))
DFW = $edge.add_node(Node.new($label[4]))
LGA = $edge.add_node(Node.new($label[5]))
MIA = $edge.add_node(Node.new($label[6]))
PVD = $edge.add_node(Node.new($label[7]))
$edge.add_edge($label[0], $label[1])# HNL - LAX
$edge.add_edge($label[1], $label[2])# LAX - SFO
$edge.add_edge($label[1], $label[3])# LAX - ORD
$edge.add_edge($label[1], $label[4])# LAX - DFW
$edge.add_edge($label[2], $label[1])# SFO - LAX
$edge.add_edge($label[2], $label[3])# SFO - LAX
$edge.add_edge($label[3], $label[2])# ORD - SFO
$edge.add_edge($label[3], $label[4])# ORD - DFW
$edge.add_edge($label[3], $label[1])# ORD - LAX
$edge.add_edge($label[5], $label[4])# LGA - DFW
$edge.add_edge($label[5], $label[6])# LGA - MIA
$edge.add_edge($label[5], $label[7])# LGA - PVD
$edge.add_edge($label[4], $label[6])# DFW - MIA
$edge.add_edge($label[4], $label[5])# DFW - LGA
$edge.add_edge($label[4], $label[3])# DFW - ORD
$edge.add_edge($label[4], $label[1])# DFW - LAX
$edge.add_edge($label[6], $label[4])# MIA - LGA
$edge.add_edge($label[6], $label[5])# MIA - DFW
$edge.add_edge($label[7], $label[3])# PVD - ORD
$edge.add_edge($label[7], $label[5])# PVD - LGA
$array.insert(0,HNL)
$array.insert(1,LAX)
$array.insert(2,SFO)
$array.insert(3,ORD)
$array.insert(4,DFW)
$array.insert(5,LGA)
$array.insert(6,MIA)
$array.insert(7,PVD)
graph.num_vertices
graph.num_edges
graph.list_vertices
graph.list_edges
vertex.deg_vertex("DFW")
$edge.incident_edges("DFW")
print "\n"
vertex.adjacent_vertices("DFW")
print "\n"
$edge.end_vertices(LAX)
vertex.are_adjacent("LAX", "HNL")
print "\n"
$edge.remove_edge("HNL", "LAX")#removes the edge that connects the vertexs.
graph.num_edges
vertex.deg_vertex("LAX")
vertex.deg_vertex("HNL")
vertex.remove_vertex("HNL")
print "\n"
graph.list_vertices




exit # this is needed so it doesnt run the code twice
