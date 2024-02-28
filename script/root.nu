#!/usr/bin/env nu
#
# João Farias © 2024 BeyonadMagic <beyondmagic@mail.ru>

# Give the root folder.
export def folder [] : nothing -> string {
	(^git rev-parse --show-cdup
	| str trim
	| path expand
	) + '/'
}
