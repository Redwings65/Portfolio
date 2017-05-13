# Kruskal Algorithm
Created By: Brandon Seager

The Kruskal's algorithm is used to compute the [minimum spanning tree (MST)
of a graph. It's is classified as a greedy algorithm.

Implementation: First we sort the edges by weight, then we analyze the edges in
this order (smallest weight first). If the nodes of the current edge
are still not connected, we add this edge to the MST. This last verification
ensure that we won't create a cycle.

The script for the program is script.rb and can be ran by cd'ing into the directory
and typing ruby script.rb. There are a series of comments to the right of each code line.
I hopefully improved  upon the last analysis assignment because instead of focusing on code i focused on the actual analysis.
Thanks! and ENJOY!


# References

https://github.com/brianstorti/ruby-graph-algorithms

https://ex0ns.me/2015/01/30/-ruby-graph-representation/

http://www.algorithmist.com/index.php/Union_Find

http://en.wikipedia.org/wiki/Minimum_spanning_tree

https://ex0ns.me/2015/01/30/-ruby-graph-representation/

https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
