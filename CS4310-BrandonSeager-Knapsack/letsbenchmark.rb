require_relative './knapsack'
require 'benchmark'

class Benchmarktest

    knap = Knapsack.new#opens the kruskal algorithm
    file = File.open('Test 5.csv', 'w') #new file opening
    hey = 0
    (1..500).each do |size|#how many data points do you want
      for t in 0..(size*100) -1
        weight = 1
        value = 1
      end
      knap.newItem("cookies",weight,value)
      #local = knap.real
      hey = hey + 1
      puts "#{hey}"#prints the number i want to see
      time = Benchmark.measure do |i|#times to run the algorithm per turn
        3.times do#gets me the average
              knap.KnapSackAlgorithm#runs the algorithm
        end
      end
      file.write("#{size*10},#{time.real/10}\n")#writes my data to the file
    end
  file.close#closes the file
end
