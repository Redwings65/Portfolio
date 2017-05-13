require_relative "spec_helper"
require_relative "/Users/brandonseager/Desktop/CS4310-BrandonSeager-Huffman/MyHuffman"

#a few tests
describe MyHuffman do
  it "is named name"
  before :each do
      @name = MyHuffman.new "name"

      describe "#name" do
    it "returns the name of the class" do
        @name.title.should eql "MyHuffman"
    end
end
  end
  #hey.should countFrequencies
end

describe Node do
it "creates a basic node tree i can use in huffman"
before :each do
    @data = Node.new "data"
end

describe "#data" do
    it "holds data value in a Node class" do
        #@data.title.should eql "data"
    end
end
end
