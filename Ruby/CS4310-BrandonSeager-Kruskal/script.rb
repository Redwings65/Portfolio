require "pp" #require the pretty print function

require_relative "graph"

require_relative "node"

require_relative "edge"

require_relative "kruskalalgorithm"

#Make a new graph object
graph = Graph.new
#Let make all the Nodes that I may use in the Algorithm
graph.add_node(nodeA = Node.new("Node A"))
graph.add_node(nodeB = Node.new("Node B"))
graph.add_node(nodeC = Node.new("Node C"))
graph.add_node(nodeD = Node.new("Node D"))
graph.add_node(nodeE = Node.new("Node E"))
graph.add_node(nodeF = Node.new("Node F"))
graph.add_node(nodeG = Node.new("Node G"))
graph.add_node(nodeH = Node.new("Node H"))
graph.add_node(nodeI = Node.new("Node I"))
graph.add_node(nodeJ = Node.new("Node J"))
graph.add_node(nodeK = Node.new("Node K"))
graph.add_node(nodeL = Node.new("Node L"))
graph.add_node(nodeM = Node.new("Node M"))
graph.add_node(nodeN = Node.new("Node N"))
graph.add_node(nodeO = Node.new("Node O"))
graph.add_node(nodeP = Node.new("Node P"))
graph.add_node(nodeQ = Node.new("Node Q"))
graph.add_node(nodeR = Node.new("Node R"))
graph.add_node(nodeS = Node.new("Node S"))
graph.add_node(nodeT = Node.new("Node T"))
graph.add_node(nodeU = Node.new("Node U"))
graph.add_node(nodeV = Node.new("Node V"))
graph.add_node(nodeW = Node.new("Node W"))
graph.add_node(nodeX = Node.new("Node X"))
graph.add_node(nodeY = Node.new("Node Y"))
graph.add_node(nodeZ = Node.new("Node Z"))

#Add a bunch of edges
graph.add_edge(nodeA, nodeH, 6)
graph.add_edge(nodeC, nodeD, 7)
graph.add_edge(nodeB, nodeH, 9)
graph.add_edge(nodeA, nodeC, 6)
graph.add_edge(nodeF, nodeH, 8)
graph.add_edge(nodeB, nodeD, 9)
graph.add_edge(nodeB, nodeF, 2)
graph.add_edge(nodeC, nodeH, 4)
graph.add_edge(nodeE, nodeF, 5)
graph.add_edge(nodeB, nodeC, 6)
graph.add_edge(nodeE, nodeH, 7)
graph.add_edge(nodeA, nodeE, 8)
graph.add_edge(nodeG, nodeC, 0)


 $start = Time.now #Make a start time
 pp Kruskal.new.compute_mst(graph).map(&:to_s) #call the pretty print and run krusals with the graph
 $finish = Time.now #Make a finish time
 diff = $finish - $start #Calculate the difference
 puts "#{diff} is the time it takes this algorithm to run" #print the time out

 print  "And that concludes my Minimum spanning tree\n"
