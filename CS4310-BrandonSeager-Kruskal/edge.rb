
#This is my basic Edge class.
class Edge
  attr_accessor :node1, :node2, :weight
#make a node 1 and a node 2 with a weight
  def initialize(node1, node2, weight)
    @node1, @node2, @weight = node1, node2, weight
  end

  def <=>(other)#lets return 1, -1 or 0
    self.weight <=> other.weight
  end

  def to_s#basic to string method
    "The #{node1.to_s} To #{node2.to_s} with the weight of #{weight}"
  end
end
