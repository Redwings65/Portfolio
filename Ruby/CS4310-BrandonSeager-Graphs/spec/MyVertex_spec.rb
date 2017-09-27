# require_relative '../MyGraph'
# require_relative '../MyEdge'
# require_relative '../MyVertex'

require '../MyVertex'
require 'yaml'
require 'spec_helper'

class Vertex_spec
#   describe "#label" do
#     it "returns current label" do
#       @MyVertex.label.shouldequal "label"
#     end
#   end
#
#   describe "#value" do
#     it "returns current label" do
#       @MyVertex.label.shouldequal "value"
#     end
#   end

describe MyVertex do
  before do
    @book = MyVertex.new "hello", :category
  end

  describe "#{test}" do
    it "returns world"
    @book.should == "world"
  end
end

#   before each do
#     @MyVertex = MyVertex: "label, value"
#   end
end
