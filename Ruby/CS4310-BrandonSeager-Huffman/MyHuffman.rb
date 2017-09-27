
#Date: 02/18/2017
#Class: CS4310
#Assignment: Assignment 4
#Author(s): Brandon Scott Seager

class Node #SUPER BASIC NODE CLASS
  attr_accessor :data, :left, :right
  def initialize(data)
    @data = data
  end
end

class MyHuffman
$characters = Array.new
  def huffman(hash)#where my huffman algorithm starts
    queue = Queue.new
    array = Array.new
    k = 0;
    tree = Node.new($begin) #makes my tree object
    for k in 0..hash.length
      add = hash[k]
      queue << add #adds elements to the queue
      while queue.size > 1 do
        value = queue.pop #pops the minimum value
        array << tree.left = Node.new(value) #puts a value on the left node
        tree.right = Node.new(1) #puts a 1 on the right node
      end
      k = k + 1
    end #end of hash.each do
  encodeString(array)
  end#end of huffman

  def countFrequencies(string)
    print "The original string is #{string}\n"
    $begin = string
    size = string.size
    backwards = -1
    string.each_byte do |i|
      $characters << i.chr #stores each characters in a array
    end
    frequency = {}#creats array for frequency
    $characters.each {|i| frequency[i] ||=0; frequency[i] +=1 } #tell the frequency of each character and adds for each occurance
    frequency = frequency.sort { |a, b| b[1] <=> a[1]} #swaps a and be so we can sort and negates them
    huffman(frequency)#calls the huffman algorithm
  end

  def encodeString(array)
    #puts array[0].data #letter that i will search for
    k = 0
    for k in 0..array.length-1

    if array[k] == array[0]
      bits = 0
      hey = array[0].data
      alphabet = hey[0]
    end
    if array[k] == array[1]
      bits = 10
      hey = array[1].data
      alphabet = hey[0]
    end
    if array[k] == array[2]
      bits = 110
      hey = array[2].data
      alphabet = hey[0]
    end
    if array[k] == array[3]
      bits = 1110
      hey = array[3].data
      alphabet = hey[0]
    end
    if array[k] == array[4]
      bits = 11110
      hey = array[4].data
      alphabet = hey[0]
    end
    if array[k] == array[5]
      bits = 111110
      hey = array[5].data
      alphabet = hey[0]
    end
    if array[k] == array[6]
      bits = 1111110
      hey = array[6].data
      alphabet = hey[0]
    end
    if array[k] == array[7]
      bits = 11111110
      hey = array[7].data
      alphabet = hey[0]
    end
    if array[k] == array[8]
      bits = 111111110
      hey = array[8].data
      alphabet = hey[0]
    end
    if array[k] == array[9]
      bits = 1111111110
      hey = array[9].data
      alphabet = hey[0]
    end
      k = k + 1
      convert = $begin.gsub! "#{alphabet}", "#{bits}"#this will change the letters to bits by the pattern i created
    end#end of loop
    print "Here is the String converted to bits "
    puts convert
  end#end of the method
end#end of the class

#here is where my script is
huff = MyHuffman.new #makes new instance
huff.countFrequencies("AABACADDDBACAFFGH")#this is what you put in as your string
puts "The Data is Now Compressed"
