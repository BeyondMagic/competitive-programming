#!/usr/bin/env nu
#
# João Farias © 2023-2024 BeyonadMagic <beyondmagic@mail.ru>

# Given test file, will match result.
export def test [
] : string -> nothing {
	let input = $in
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
