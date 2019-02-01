#!/usr/bin/ruby

# Usage:
#  ruby pushswaptest.rb ./push_swap_binary "3 2 1"
#  ruby pushswaptest.rb ./push_swap_binary
#
#  If you leave numbers argument empty, a random generated number array will be used

require 'set'

def rand_n(n, max)
	randoms = Set.new
	loop do
		randoms << rand(max)
		return randoms.to_a if randoms.size >= n
	end
end

class List

	attr_accessor :a, :b

	def initialize(numbers)
		@a = numbers || []
		@b = []
	end

	def sa
		# swap a intervertit les 2 premiers éléments au sommet de la pile a. (ne fait rien s’il n’y en a qu’un ou aucun).
		@a[0], @a[1] = @a[1], @a[0] unless @a.count <= 1
	end

	def sb
		# swap b intervertit les 2 premiers éléments au sommet de la pile b. (ne fait rien s’il n’y en a qu’un ou aucun).
		@b[0], @b[1] = @b[1], @b[0] unless @b.count <= 1
	end

	def ss
		# sa et sb en même temps.
		sa
		sb
	end

	def pa
		# push a prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
		@a << @b.slice!(0) unless @b.count == 0
	end

	def pb
		# push b prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).
		@b << @a.slice!(0) unless @a.count == 0
	end

	def ra
		# rotate a décale d’une position tous les élements de la pile a. (vers le haut, le premier élément devient le dernier).
		@a.rotate!
	end

	def rb
		# rotate b décale d’une position tous les élements de la pile b. (vers le haut, le premier élément devient le dernier).
		@b.rotate!
	end

	def rr
		# ra et rb en meme temps.
		ra
		rb
	end

	def rra
		# reverse rotate a (vers le bas, le dernier élément devient le premier).
		@a.rotate!(-1)
	end

	def rrb
		# reverse rotate b (vers le bas, le dernier élément devient le premier).
		@b.rotate!(-1)
	end

	def rrr
		# rra et rrb en même temps.
		rra
		rrb
	end

	def to_s
		" -> #{@a.to_s}\n -> #{@b.to_s}"
	end

end

if ARGV[1].nil? || ARGV[1] == ""
	numbers = rand_n(100, 100)
else
	numbers = ARGV[1].split(' ').map(&:to_i)
end

save = list = List.new numbers
commands = `#{ARGV[0]} #{numbers.join(' ')}`.split(' ')

puts "Begin", list, "\n"

commands.each do |command|
	if !List.methods.map(&:to_s).include? command
		puts commands.join(' ')
		break
	end
	puts "#{command}"
	list.send command
	puts list
end

puts "\nFinal", list, "\n"

if list.a == save.a.sort || list.a == save.a.sort.reverse
	puts "[   OK   ]"
	exit 0
else
	puts "[  FAIL  ]"
	exit 1
end
