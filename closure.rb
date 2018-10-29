# A closure is a chunk of code which meets three criteria:
#
#     * It can be passed around as a value and
#
#     * executed on demand by anyone who has that value, at which time
#
#     * it can refer to variables from the context in which it was created
#       (i.e. it is closed with respect to variable access, in the
#       mathematical sense of the word "closed").


# ---------------------------- Section 1: Blocks ----------------------------

# Blocks are like closures, because they can refer to variables from their defining context:

example 1

def thrice
  yield
  yield
  yield
end

x = 5
puts "value of x before: #{x}"
thrice { x += 1 }
puts "value of x after: #{x}"

# A block refers to variables in the context it was defined, not the context in which it is called:

example 2

def thrice_with_local_x
  x = 100
  yield
  yield
  yield
  puts "value of x at end of thrice_with_local_x: #{x}"
end

x = 5
thrice_with_local_x { x += 1 }
puts "value of outer x after: #{x}"