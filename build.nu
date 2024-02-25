#!/usr/bin/env nu
#
# João Farias © 2023-2024 BeyonadMagic <beyondmagic@mail.ru>

use log.nu
const name = "build"

def lsp_database [
	command : list<string> # The command itself passed as a list.
] : nothing -> nothing {
	let input = $in

	# Compilation database like bear for clang and gcc for language servers.
	[
		{
			arguments: $command
			directory: ($input | path dirname | path expand)
			file: ($input | path expand)
		}

	# Save the file for language servers.
	] | save --force compile_commands.json
}

# Compile source code.
export def c++ [
	--output : string = "./binary" # Binary output.
	--eyes = false # Print the command of build.
	--optimise = false # Optimise (O3).
	--debug = true # Add debug flags.
	--standard : string = 'c++20' # Standardad of the compiler.
] : string -> nothing {

	# Input is supposed to be a path for a file
	let input = $in
	let type = $input | describe

	# Raise error when nothing was given.
	if $type == 'nothing' {
		error make --unspanned {
			msg: "No input file was passed"
		}

	# Raise error when string is not a valid path and file.
	} else if $type == 'string' and ($input | path type) != 'file' {
		error make --unspanned {
			msg: "Path passed is not a file"
		}
	}

	# Standard for the compiler.
	mut args = [
		('-std=' + $standard)
	]

	$args = $args ++ if $optimise {
		[
			# Optimise in accordance to O3 specification.
			# See manual gcc(1).
			'-O3'
		]
	} else {
		[
			# No unused variables.
			'-Wno-unused'
			# All warnings to be treated as errors.
			'-Wall'
			# Extra flgs.
			'-Werror'
			# Further extra flags.
			'-Wextra'
			# Stick to the standardad.
			'-pedantic'
			# Disallow implicit conversion.
			'-Wconversion'
			# Disallow implicit sign conversion.
			'-Wsign-conversion'
			# Variable shadowing/repeating names of variables in the same context.
			'-Wshadow'
		]
	}

	if $debug {
		$args = $args ++ [
			# For debugging with gdb.
			'-ggdb'
			# To catch UB as must as it can.
			'-fsanitize-undefined-trap-on-error'
			# To catch memory-leak-specific UB as must as it can.
			'-fsanitize-address-use-after-scope'
			# Sanitize all addresses and UB by default.
			'-fsanitize=address,undefined'
		]
	}

	let command = [
		'c++'
		...$args
		$input
		'-o'
		$output
	]

	# Create folder for this file.
	mkdir ($output | path dirname)

	if $eyes {
		print $command
	}

	log debug --name $name "Compiling."

	let exit_code = nu --commands ($command | str join ' ')
		| complete
		| get exit_code

	if $exit_code != 0 {
		log fail --name $name "Failed at compiling!"
	} else {
		log success --name $name "Compiled successfully!"
	}

	$input | lsp_database $command
}

# Will try to build any file based on the extension.
#
# Mapping extension to its respective language builder:
#	c++ -> C++
#	cpp -> C++
#	TODO: c -> c
export def main [] : string -> nothing {
	let input = $in

	let extension = $input
		| path basename
		| split row '.'
		| last

	$input | match $extension {
		'c++' => c++
		'cpp' => c++
	}
}
