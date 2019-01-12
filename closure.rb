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


example 3

thrice do  # note that {...} and do...end are completely equivalent
  y = 10
  puts "Is y defined inside the block where it is first set?"
  puts "Yes." if defined? y
end
puts "Is y defined in the outer context after being set in the block?"
puts "No!" unless defined? y

# OK, so blocks seem to be like closures: they are closed with respect to variables defined in the
# context where they were created, regardless of the context in which they're called.
#
# But they don't look quite like closures in the code above because we aren't passing them around
# as we would any othe value: "yield" can *only* refer to the block passed to the method it's in.
#
# We can pass a block on down the chain, however, using &:

example 4

def six_times(&block)
  thrice(&block)
  thrice(&block)
end

x = 4
six_times { x += 10 }
puts "value of x after: #{x}"

# So do we have closures? Not quite! We can't hold on to a &block and call it later at an arbitrary
# time; it doesn't work. This, for example, will not compile:
#
# def save_block_for_later(&block)
#     saved = &block
# end
#
# But we *can* pass it around if we use drop the &, and use block.call(...) instead of yield:

example 5

def save_for_later(&b)
  @saved = b  # Note: no ampersand! This turns a block into a closure of sorts.
end

save_for_later { puts "Hello!" }
puts "Deferred execution of a block:"
@saved.call
@saved.call

# But wait! We can't pass multiple blocks to a function! As it turns out, there can be only zero
# or one &block_params to a function, and the &param *must* be the last in the list.
#
# None of these will compile:
#
#    def f(&block1, &block2) ...
#    def f(&block1, arg_after_block) ...
#    f { puts "block1" } { puts "block2" }
#
# What the heck?
#
# I claim this single-block limitation violates the "principle of least surprise." The reasons for
# it have to do with ease of C implementation, not semantics.
#
# So: are we doomed, never to do anything wild and Lisp-like with closures?