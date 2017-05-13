require 'mathn'
class Knapsack
  $start = Time.now
  $array = Array.new
  $value = Array.new
  $temp = Array.new

  def newItem(name,benefit,weight)
    item = [name,benefit,weight]
    $array << item
    #print $array[0][0]
  end

  def KnapSackAlgorithm()
    knapsack_capacity = 100000000;#control the knapsack compacity
    k = 0#just a initalizer
    w = 0#current weight
    for k in 0..$array.length-1
      name,benefit,weight = $array[k]
      x = 0;
      value_of_item = benefit/weight
      temp = value_of_item,name
      temp2 = value_of_item,weight
      $value << temp
      $temp << temp2
      #puts $value
      k = k + 1
    end
    $value.sort
    $temp.sort
    #puts $temp# this is correct
    i = 0;
    while (w < knapsack_capacity) do
      value,weight = $temp[i]
      w = w + weight.to_f
      #puts weight
      i = i + 1
      if($temp.count == i)
        break
      end
    end
    hey = 0
    puts "looks like you can hold "
    while(hey < i)
      puts $value[hey][1]
      hey = hey + 1
    end
    if (w > knapsack_capacity)
      puts "looks like you cant hold all of it but"
    end
    puts "your total weight is #{w}/#{knapsack_capacity}"
  end #this is the end of the algorithm
end
