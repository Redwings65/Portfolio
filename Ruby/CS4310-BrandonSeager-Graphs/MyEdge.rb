require_relative "MyEdge.rb"
require_relative "MyGraph.rb"
require_relative "MyVertex.rb"
#require_relative "MyEdge.rb"

class MyEdge
  attr_accessor :label
  attr_accessor :value

  def initialize()
    $counter = 0
    @nodes = {}
  end

  def add_node(node)
    @nodes[node.name] = node
  end

  def add_edge(predecessor_name, successor_name)
    @nodes[predecessor_name].add_edge(@nodes[successor_name])
    $counter = $counter + 1
  end

  def remove_edge(predecessor_name, successor_name)
    puts "I Removed the Edge for You"
    @nodes[predecessor_name].remove_edge(@nodes[successor_name])
    $counter = $counter - 1
  end

  def [](name)
    @nodes[name]
  end

  def incident_edges(v)# - Return an array of edges incident upon some vertex ”v” in G adjacent
    i = 0
    for i in 0..$counter
    hey = "#{$array[i]}"
      if hey[v]#if hey contains v
        puts "#{$array[i]} is the incident edges"
      end
    end
  end

  def end_vertices(e)# - Return the two end vertices of an edge ”e” in G
    puts "#{e}"
  end
end

class Node
  attr_reader :name

  def initialize(name)
    @name = name
    @successors = []
  end

  def add_edge(successor)
    @successors << successor
  end

  def remove_edge(successor)#same as above just opposite
    @successors.delete(successor)
  end

  def to_s#this could probably be deleted
    "#{@name} -> [#{@successors.map(&:name).join(' ')}]"
  end
end


#http://stackoverflow.com/questions/12720771/adjacency-list-and-graph
