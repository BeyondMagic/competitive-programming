#!/usr/bin/env nu
#
# Module for logging things with a kinda cute way.
# Reference for terminfo (colours, reverse, etc):
#	https://www.mankier.com/5/terminfo#Description-Predefined_Capabilities
#	https://linux.101hacks.com/ps1-examples/prompt-color-using-tput/
#
# TODO:
#	- Should use const ansi instead of dynamic tput.
#	- Should use standard input instead of argument.
#
# João Farias © 2023-2024 BeyonadMagic <beyondmagic@mail.ru>

const name_default = "log.nu"
const format_default = "%s"
const reset = (ansi reset)
const default_reverse = (ansi default_reverse)
const red = (ansi red)
const red_bold = (ansi red_bold)
const green_bold = (ansi green_bold)
const yellow_bold = (ansi yellow_bold)
const white_bold = (ansi white_bold)

# Printf parser.
def fprint [
	args: list<string> # Strings/number to print.
	--name: string     # Name of the program.
	--format: string   # Format of the program.
	--colour: string   # Colour of the whole message.
	--left: int = 0    # Extra padding.
] -> null {

	let final_name = '[' + $name + ']'

	# Count how many "padders" we need to add based on newlines.
	let pad_chars = ($final_name | str length) + 1 + $left

	# Create the string full of spaces
	mut spaces = ''
	mut i = 1
	while $i <= $pad_chars {
		$i = $i + 1
		$spaces = $spaces + ' '
	}

	let formats_replacement = (char newline) + $spaces + '$1'
	let final_format = "%s " + ($format | str replace --regex --all (char newline) $formats_replacement) + "%s"

	let arguments = [
		$final_format
		($colour + $default_reverse + $final_name + $reset + $colour)
		...$args
		($reset)
		(char newline)
	] | str join

	#print $arguments

	^printf $arguments
}

# Print a crossed item in red (represents task failed).
export def fail [
	...message: string,                 # Message to print
	--name: string = $name_default,     # Name of the program.
	--format: string = $format_default, # Format (printf specification) of the message.
] -> null {
	let t_fg_red = (tput setaf 1)
	fprint $message --left 4 --name $name --format ('[X] ' + $format) --colour $red_bold
}

# Print a checked item in green (represents task was done successfuly).
export def success [
	...message: string,                 # Message to print
	--name: string = $name_default,     # Name of the program.
	--format: string = $format_default, # Format (printf specification) of the message.
] -> null {
	fprint $message --left 4 --name $name --format ('[✓] ' + $format) --colour $green_bold
}

# Print in red (represents information that needs to be paid).
export def error [
	...message: string,                 # Message to print
	--name: string = $name_default,     # Name of the program.
	--format: string = $format_default, # Format (printf specification) of the message.
] -> null {
	fprint $message --name $name --format $format --colour $red
}

# Print in yellow (represents information to be paid attention).
export def warning [
	...message: string,                 # Message to print
	--name: string = $name_default,     # Name of the program.
	--format: string = $format_default, # Format (printf specification) of the message.
] -> null {
	fprint $message --name $name --format $format --colour $yellow_bold
}

# Print in gray (represents extra information).
export def debug [
	...message: string,                 # Message to print
	--name: string = $name_default,     # Name of the program.
	--format: string = $format_default, # Format (printf specification) of the message.
] -> null {
	fprint $message --name $name --format $format --colour $white_bold
}
