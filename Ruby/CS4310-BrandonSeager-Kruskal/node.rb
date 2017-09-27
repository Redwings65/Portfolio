
#This is the basic Node Class
class Node
  attr_accessor :name, :graph
#Initalize graph and name for use
  def initialize(name)
    @name = name
  end

  def adjacents#helps to map the adjacent edges
    graph.edges.select{|e| e.from == self}.map(&:to)
  end

  def to_s #to string method for the value name
    @name
  end
end
