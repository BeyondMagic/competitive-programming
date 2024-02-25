#!/usr/bin/env nu
#
# João Farias © 2023-2024 BeyonadMagic <beyondmagic@mail.ru>

# Given test file, will match result.
export def test [
] : string -> nothing {
	let input = $in
}

# Make tests in the current folder.
export def make-tests [
	n : number # Amount of tests.
	--test-folder : string = './tests/' # Folder for tests.
] : nothing -> nothing {

	# In case there is folder, let's create it.
	mkdir $test_folder
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

# Give the root folder.
def root_folder [] : nothing -> string {
	^git rev-parse --show-cdup
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

	let root = root_folder
		| str trim

	let template = $root + './templates/' + $type + '/*'

	cp --recursive $template ./

	# Go back.
	cd -

	modify $folder --tests $tests
}
#
# Will enter in the folder and change environment.
export def --env modify [
	folder : string # Folder to modiy
	--tests : number # Specify new number of tests.
	--test-folder : string = './tests/' # Folder for tests.
] : string -> nothing {
	# Raise error when path is not directory problem.
	if ($folder | path type) != 'dir' {
		error make --unspanned {
			msg: "The given path is a not directory."
		}
	}

	cd $folder

	# Raise error when a `source.*` code is not found.
	# To represent when a path does not seem like a problem.
	let file = ls --full-paths `source.*`
		| first
		| get name

	# In case there is folder, let's create it.
	mkdir $test_folder

	# Let's create tests.
	if not ($tests | is-empty) {
		mut test = 0
		while $test != $tests {
			let name = [
				$test_folder
				($test + 1)
			] | str join

			touch ($name + '.in' | path expand)

			$test += 1
		}
	}

	# Run environment editor.
	run-external $env.EDITOR ...[
		$file
		# Make next files opened, but not focused.
		"+args %"
		# Open all the test files.
		# NOTE: In UNIX systems it opens by default in order.
		# May need to change for other operating systems.
		($test_folder + '*')
	]
}

export module build.nu
