#basic graph class
class Graph
  attr_accessor :nodes
  attr_accessor :edges
#initalitze nodes and edges
  def initialize
    @nodes = []
    @edges = []
  end

  def add_node(node)

    nodes << node #adds the node to the nodes array
    #node.graph = self #initalize it to its self

  end

  def add_edge(from, to, weight)

    edges << Edge.new(from, to, weight)#adds the new edge to the edges array

  end
end#end of the graph class
