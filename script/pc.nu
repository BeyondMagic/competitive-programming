#!/usr/bin/env nu
#
# João Farias © 2023-2024 BeyonadMagic <beyondmagic@mail.ru>

use root.nu

const green = (ansi green_bold)
const red = (ansi red_bold)
const yellow = (ansi yellow_bold)
const white = (ansi white_bold)

# Copy content of the source code.
export def "copy file" [
	file : string = './source.*' # File to copy content from.
	temp : string = './.temp.pc' # File to create temporarily.
] : nothing -> nothing {
	copy

	^wl-paste | save $temp --force

	$temp | path expand | ^wl-copy
}


# Copy content of the source code.
export def copy [
	file : string = './source.*' # File to copy content from.
] : nothing -> nothing {
	let path = ls --directory ($file | into glob)
		| get name
		| first

	# For C++ files.
	let content = if ("./library.hpp" | path exists) {
		let library = open --raw "./library.hpp"

		open --raw $path
			| str replace `#include "library.hpp"` $library
	# For the rest kind of soruces.
	} else if ("./library.py" | path exists) {
		let library = open --raw "./library.py"

		open --raw $path
			| str replace `from library import *` $library
	} else {
		open --raw $path
	}

	$content | ^wl-copy
}

# To see if it's a number.
def is-number []: string -> bool {
	try { $in | into float } catch { null } | is-not-empty
}

# To see if the string is precise by floating precisions.
export def is-precise [
	a_str: string # Base expeceted argument to compare.
	b_str: string # Given argument to compare.
]: nothing -> bool {
	let a = $a_str | str trim | split row ' '
	let b = $b_str | str trim | split row ' '

	let max = $a | length

	# Different quantity of elements won't work.
	if $max != ($b | length) {
		return false
	}

	mut i = 0
	while $i < $max {
		
		mut x = $a | get $i
		mut y = $b | get $i

		# Case 1: both are numbers.
		if ($x | is-number) and ($y | is-number) {

			$x = $x | str substring ..-2
			$y = $y | str substring ..-2

			if ($x | str length) > ($y | str length) {
				if not ($x =~ $y) {
					break
				}
			} else {
				if not ($y =~ $x) {
					break
				}
			}

		# Case 2: string is not equal to each other.
		} else if $x != $y {
			break
		}

		$i = $i + 1
	}

	# If had to break of loop earlier.
	if $i != $max {
		false
	} else {
		true
	}
}

# Given test file, will match result.
export def test [
	--executable : string = './binary' # Program to run.
	--test-folder : string = './tests/' # Folder for tests.
]: nothing -> nothing {
	# If it is compiled language:
	let binary = if ($executable | path type) == 'file' {
		$executable
	} else {
		'./' + (
			ls
			| where name =~ source
			| get 0.name
		)
	}

	ls --full-paths ($test_folder + '*.in' | into glob)
	| get name
	| par-each {|file|

		let data = open $file

		# Benchmark start...
		let start = date now

		# Result of the test.
		let result = $data
			| ^$binary
			| complete

		# ... and end.
		let end = date now

		let output = ($file
			| str substring ..-3
			) + 'out'

		let expected = (open --raw $output) + "\n"

		# Set respectiv ecolour for output.
		let colour_output = if $result.stdout == $expected {
			$green

		# If trailing characters are the problem, use yellow instead.
		} else if (
			$result.stdout | lines | str trim | str join "\n"
		) == (
			$expected | lines | str trim | str join "\n"
		) {
			$yellow

		# For calculating floating number precisions:
		#} else if (is-precise $result.stdout $expected) {
		#	$green
		} else {
			$red
		}

		# Return a record explaining how the test went.
		{
			# Duration of the test.
			time : ($end - $start)

			# Test itself.
			test : ($white + $data)

			# The expected output of the test.
			expected : ($colour_output + $expected)

			# The output of the program with the given test.
			stdout : ($colour_output + $result.stdout)

			# The stderr of the given test.
			stderr : (if ('stderr' in $result) {
				$red + ($result.stderr | into string)
			} else {
				''
			})

			# The exit code of the program with the given test.
			exit_code : (if $result.exit_code != 0 {
				$red + ($result.exit_code | into string)
			} else {
				$green + ($result.exit_code | into string)
			})
		}
	}
}

# Make tests in the current folder.
export def make-tests [
	n : number # Amount of tests.
	--test-folder: string = 'tests' # Folder for tests.
] : nothing -> nothing {

	# In case there is folder, let's create it.
	mkdir ($test_folder | path expand)
	cd $test_folder

	mut i = 0
	while $i != $n {
		let test = [
			($i + 1)
			'.'
		]
		| str join
		| path expand

		touch ($test + 'in') ($test + 'out')

		$i += 1
	}

	cd -
}


# Create problem.
export def --env create [
	folder : string # Folder to be created.
	--type : string = 'c++' # Type of language.
	--tests : number = 1 # Amount of tests. Natural number (positive integer).
] : nothing -> nothing {

	# Raise error when folder already exists.
	if ($folder | path exists) {
		error make --unspanned {
			msg: "The problem already exists."
		}
	}

	# Go to the folder problem..
	mkdir $folder
	cd $folder

	let root = root folder

	let type = $type | str downcase
	let template = $root + './templates/' + $type + '/*'
		| into glob

	cp --recursive $template ./

	# Go back.
	cd -

	modify $folder --tests $tests
}

# Modify the source of a problem.
#
# Will enter in the folder and change environment.
export def --env modify [
	folder : string # Folder to modiy.
	--tests : number = 1 # Amount of tests. Natural number (positive integer).
	--test-folder : string = 'tests' # Folder for tests.
] : nothing -> nothing {

	# Raise error when path is not directory problem.
	if ($folder | path type) != 'dir' {
		error make --unspanned {
			msg: "The given path is a not directory."
		}
	}

	cd $folder

	# Raise error when a `source.*` code is not found.
	# To represent when a path does not seem like a problem.
	let source = ls --full-paths ('source.*' | into glob)
		| first
		| get name

	# Make the tests.
	make-tests $tests --test-folder $test_folder

	# Run environment editor.
	run-external $env.EDITOR ...[
		$source
		# Make next files opened, but not focused.
		"+args %"
		# Open all the test files.
		# NOTE: In UNIX systems it opens by default in order.
		# May need to change for other operating systems.
		...(glob ($test_folder + '/*') | sort)
	]
}

export module build.nu
