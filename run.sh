#!/usr/bin/env zsh
#
# ???
#
# Dependencies:
#   fd
#     github.com/sharkdp/fd
#
# BeyondMagic © 2022-2023 <beyondmagic@mail.ru>

# To colorise output uniquely.
function gray  () { echo "\033[2m$1\033[0m" }
function bold  () { echo "\033[3m$1\033[0m" }
function red   () { echo "\033[31m$1\033[m" }
function green () { echo "\033[32m$1\033[m" }

case "$1" in

  # Will build 
  #  $2? Name of the project in case of root folder.
  'run' | 'r' )

    # To verify if is the root folder.
    if [ -f "config.mk" ]; then

      if [ ! "$2" ]; then
        red "\$2 argument should be the problem's folder name."
        exit 1
      fi
      if [ ! -f "./$2/" ]; then
        red "\"$2\" problem's folder does not exist."
        exit 1
      fi
      n="$2" make optimise
    else
      last_dir="$PWD"
      cd "../"
      n="$(basename "$last_dir")" make optimise
      cd "$last_dir"
    fi
  ;;

  # To create a new folder for a problem.
  # @parameters
  #  $2 To create a new run of files.
  #  #3 'C' or 'C++', 'C++' default
  'create' | 'c' )

    # Verify if user is on the root of the project.

  ;;

  # Will show input and output of all tests.
  # @parameters
  #  $2 how many tests.
  'test' | 't' )

    # Discover the quantity of tests.
    [ "$2" ] && quantity="$2" \
             || quantity="$(fd --base-directory tests/ --extension in --size +1b | wc -l)"

    # Run over each one.
    for a in {1..$quantity}
    do

      input="$(cat "./tests/$a.in")"
      result="$("./binary" < "./tests/$a.in")"
      expected="$(cat "./tests/$a.out")"

      if [ $? -eq 0 ]; then
        min_result="$(echo "$result" | tr -d '\r\n' | awk '{$1=$1};1')"
        min_expected="$(echo "$expected" | tr -d '\r\n' | awk '{$1=$1};1')"
        if [ "$min_result" = "$min_expected" ]; then
          green "$a. $result"
          continue
        fi
      fi
      bold "    RESULT:"

      bold "$a.  INPUT:"
      gray "$input"

      red "$result"
      bold "    EXPECTED:"
      gray "$expected"

      echo
    done

  ;;

esac
