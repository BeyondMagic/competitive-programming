#!/usr/bin/env sh
#
# Aliases to add in your shell to facilitate usage of this script.
#
# @author
#   João F. BeyondMagic <koetemagie@gmail.com>

# To output commands in terminal.
LOG=true

# Default variables.
SCRIPT_FOLDER="$(dirname "$0")"
NAME_FOLDER="$(basename "$SCRIPT_FOLDER")"

source "$SCRIPT_FOLDER"/_logging.sh

# Execute main script no matter which subfolder user is in.
run ()
{
  git ls-remote --get-url > /dev/null && {
    root="$(git rev-parse --show-cdup)script/$NAME_FOLDER"
    ___log "./${root}/run.zsh $@"
    ./${root}/run.zsh $@
  }
}
