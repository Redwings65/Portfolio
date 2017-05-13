require "pp"
require_relative './graph'
require_relative './node'
require_relative './edge'
require_relative './kruskalalgorithm'
require 'benchmark'

class Benchmarktest

    kruskal = Kruskal.new#opens the kruskal algorithm
    file = File.open('Test 20.csv', 'w') #new file opening
    hey = 0
    letsgraph = Graph.new#open teh graph class
    benefit = Random.rand(1..10)
    (1..5000).each do |size|#how many data points do you want
      for t in 0..(size*100) -1
        node = 1
      end
      letsgraph.add_node(node)
      hey = hey + 1
      puts "#{hey}"#prints the number i want to see
      time = Benchmark.measure do |i|#times to run the algorithm per turn
        200.times do
              Kruskal.new.compute_mst(letsgraph).map(&:to_s)#runs the algorithm
        end
      end
      file.write("#{size*10},#{time.real/10}\n")#writes my data to the file
    end
  file.close#closes the file
end
