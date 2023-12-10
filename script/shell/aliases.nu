# For competitive programming.
def run [...arguments] {
	let repository = $'(git ls-remote --get-url)'

	if $env.LAST_EXIT_CODE == 0 and $repository ends-with 'BeyondMagic/competitive-programming.git' {
		let command = $'(git rev-parse --show-cdup)script/shell/run.zsh'
		^$command $arguments
	}
}
