#!/usr/bin/env zsh
#
# @param string: run or r. Build the project.
#   @param string: name of project in case being in root path.
#     @param boolean: force move compile_commands.json
#   @param boolean: force move compile_commands.json
#
# @param string: create or r
#   @param string: name of project to be created.
#   @param tests: quantity of tests to be used.
#   @param language: C++ or C.
#
# @param string: test or t. Will show input and output of all tests.
#   @param number: quantity of tests to run.
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
function yellow () { echo "\033[33m$1\033[m" }
function bright_yellow () { echo "\033[93m$1\033[m" }

function build ()
{
  bear -- make build -s
  compile_file='compile_commands.json'
  if [[ ! -f "$last_dir/$compile_file" || $1 = 'true' ]]; then
    mv compile_commands.json "$last_dir"
  fi
}

case "$1" in

  'run' | 'r' )

    # If it the root folder.
    if [ -f "config.mk" ]; then

      if [ ! "$2" ]; then
        red "\$2 argument should be the problem's folder name."
        exit 1
      fi
      if [ ! -f "./$2/" ]; then
        red "\"$2\" problem's folder does not exist."
        exit 1
      fi
      export c="$(echo source.* | awk -F '[.]' '{print $NF}')"
      n="$2" build $43
    else
      last_dir="$PWD"
      export c="$(echo source.* | awk -F '[.]' '{print $NF}')"
      cd "../"
      n="$(basename "$last_dir")" build $3
      cd "$last_dir"
    fi
  ;;

  'create' | 'c' )

    # Verify if user's on the root path.
    if [ ! -f "config.mk" ]; then
      red "You have to be on the root path of the project to create a problem's folder."
      exit 1
    fi

    # Verify if user is on the root of the project.
    if [ ! "$2" ]; then
      red "Specify the name's problem following the convention."
      exit 1
    fi

    if [ -d "$2" ]; then
      red "\"$2\" folder or problem solution already exist."
      exit 1
    fi

    mkdir -p "$2/tests/"

    # Make default C++.
    [ ! "$4" ] && extension="c++" \
               || extension="$4"

    name="$2/source.$extension"

    cp "template.$extension" "$name"

    if [ "$3" -gt 0 ]; then
      for i in {1..$3}; do
        touch "./$2/tests/$i.in" "./$2/tests/$i.out"
      done

      nvim "$name" "./$2/tests"/*
    else
      nvim "$name"
    fi
  ;;

  'test' | 't' )

    # Discover the quantity of tests.
    [ "$2" ] && quantity="$2" \
             || quantity="$(fd --base-directory tests/ --extension in --size +1b | wc -l)"

    failed=""

    # Run over each one.
    for a in {1..$quantity}
    do

      input="$(cat "./tests/$a.in")"
      result="$("./binary" < "./tests/$a.in")"
      expected="$(cat "./tests/$a.out")"

      #echo "__result: \"$result\"\nexpected: \"$expected\"" | nvim
      #exit 1

      if [ $? -eq 0 ]; then
        if [ "$result" = "$expected" ]; then
          green "$a. $result"
          continue
        fi

        min_result="$(echo "$result" | awk '{$1=$1};1')"
        min_expected="$(echo "$expected" | awk '{$1=$1};1')"

        if [ "$min_result" = "$min_expected" ]; then
          gray "Had to remove leading and trailing spaces."
          bright_yellow "$a. $result"
          continue
        fi

        min_result="$(echo "$min_result" | tr -d '\r\n')"
        min_expected="$(echo "$min_expected" | tr -d '\r\n')"
        if [ "$min_result" = "$min_expected" ]; then
          gray "Had to remove newlines, leading and trailing spaces."
          yellow "$a. $result"
          continue
        fi
      fi

      # Here failed.
      bold "$a.  INPUT:"
      gray "$input"

      bold "$a.   RESULT:"
      red "$result"

      # See difference between results.
      {
        mkdir -p './failed'
        echo "$result" > "./failed/$a.result"
        diff "./failed/$a.result" "./tests/$a.out"  --unified=0 > "./failed/$a.diff"
        rm -f "./failed/$a.result"
        failed=true
      }

      bold "    EXPECTED:"
      gray "$expected"

      echo
    done

    if [ -d "./failed/" ]; then
      [ "$failed" ] && nvim "./failed/"* \
                    || rm -rf "$failed_folder"

    fi

  ;;

esac
