require_relative "MyVertex.rb"
require_relative "MyGraph.rb"
require_relative "MyEdge.rb"



class MyVertex
  attr_accessor :label
  attr_accessor :value

  $label = Array.new #creates the array i will use later

  def new_vertex(label, value)# - Insert a new isolated vertex into graph G
    $label << "#{value}";
  end

  def remove_vertex(v)# - Remove an vertex ”e” from G
    $label.delete(v)
    print "I successfully deleted the vertex for you "
  end

  def find_vertex(v)# - Return some vertex ”v” in G
    q = 0
    for i in 0..$counter
      if v == $label[i] then
        puts "i found it"
        print "here is the value #{$label[i]}"
        q = 1;
        break
      end
    end#ends the for
      if q != 1
        print "sorry couldnt find it"
      end
  end#ends the method

  def deg_vertex(v)# - Return the degree of a given vertex ”v” in G
    i = 0
    h = 0
    for i in 0..$counter
    hey = "#{$array[i]}"
      if hey[v]#if hey contains v
        h +=1
      end#end of if
    end#end of for
    puts "The degree of the Vertex is #{h-1}"
  end

  def adjacent_vertices(v)# - Return an array of all vertices adjacent to a vertex ”v” in G
    i = 0
    for i in 0..$counter
    hey = "#{$array[i]}"
      if hey[v]#if hey contains v
        puts "#{$array[i]} are the adjacent vertices"
      end
    end
  end

  def are_adjacent(v, w)# - Return whether two vertices ”v” and ”w” are adjacent in G
    i = 0
    h = 0
    for i in 0..$counter
    hey = "#{$array[i]} are adjacent to each other"
      if hey[v] && hey[w]#if hey contains v
        print "YES Those are adjacent"
      end
    end
  end
end#ends the class
