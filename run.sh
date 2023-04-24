#!/usr/bin/env zsh
#
# Tool to create, build, test, and modify competitive problems.
#
# @param string: modify or m. Modify a problem.
#   @param string: name of project in case being in root path.
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
# @note: Enviroment variables used:
#   EDITOR
#
# Dependencies:
#   fd
#     github.com/sharkdp/fd
#   git
#   cat (rust)
#
# BeyondMagic © 2022-2023 <beyondmagic@mail.ru>

# Global variables.

SCRIPT="$(basename $0)"
SOURCE='source'
TEMPLATE='templates'

# To colorise output uniquely.

function gray  () { echo "\033[2m$@\033[0m" }
function bold  () { echo "\033[3m$@\033[0m" }
function red   () { echo "\033[31m$@\033[m" }
function green () { echo "\033[32m$@\033[m" }
function yellow () { echo "\033[33m$@\033[m" }
function bright_yellow () { echo "\033[93m$@\033[m" }

# Auxialiary functions to reduce code.

function _is_in_root () {
  if [ ! -f "./$SCRIPT" ]; then
    red "You have to be on the root path of the project to create a problem's folder."
    exit 1
  fi
}

function _is_not_in_root () {
  if [ -f "./$SCRIPT" ]; then
    red "You have to be on a folder's problem."
    exit 1
  fi
}

function _has_folder () {
  folder="$1"
  shift

  if [ ! -d "./$folder/" ]; then
    red "\"./$folder/\" problem's folder does not exist."
    exit 1
  fi
}

function _hasnt_folder () {
  name="$1"
  shift

  if [ -d "$name" ]; then
    red "\"$name\" folder or problem solution already exist."
    exit 1
  fi
}

function _hasnt_argument () {
  name="$1"
  shift

  reason="$1"
  shift

  # Has to have problem's name.
  if [ ! "$name" ]; then
    red "Specify the $reason's problem following the convention."
    exit 1
  fi
}

function _open_editor () {
  if [ -d './tests/' ]; then
    if [[ "$EDITOR" = 'nvim' ]] || [[ "$EDITOR" = 'vim' ]]; then
      $EDITOR "./$SOURCE."* +args\ % './tests/'*
    else
      "$EDITOR" "./$SOURCE."* './tests/'*
    fi
  else
    if [[ "$EDITOR" = 'nvim' ]] || [[ "$EDITOR" = 'vim' ]]; then
      $EDITOR "./$SOURCE."*
    else
      "$EDITOR" "./$SOURCE."*
    fi
  fi
}

function _see_errors () {
  failed="$1"
  shift

  if [ -d './failed/' ]; then
    if [ "$failed" = true ]; then
      $EDITOR +args\ % './failed/'*
    else
      rm -rf './failed/'
    fi
  fi
}

function _set_tests () {
  tests="$1"

  if [ "$tests" ]; then
    shift
    mkdir -p 'tests/'

    if [ "$tests" -gt 0 ]; then
      for i in {1..$tests}; do
        touch "tests/$i.in" "tests/$i.out"
      done
    fi
  fi
}

# Build systems for each language.

# TODO: Use esbuild to make this.
function build_typescript () {
}

function _build_bear_cpp_c ()
{
  compile_file='compile_commands.json'

  export root="$1"
  shift

  export filename="$1"
  shift

  bear -- make build -s
  if [ ! -f "$root/$compile_file" ]; then
    mv compile_commands.json "$last_dir"
  fi
}

function build ()
{
  language="$1"
  shift

  case "$language" in

    'c' )

      cd ./build/c/
      _build_bear_cpp_c $@

    ;;

    'c++' | 'cpp' )

      cd ./build/c++/
      _build_bear_cpp_c $@

    ;;

    'typescript' | 'ts' )

      cd ./build/typescript/
      build_typescript $@

    ;;

  esac
}

{
  action="$1"
  shift

  case "$action" in

    'modify' | 'm' )

      folder="$1"
      shift

      tests="$1"
      [ "$1" ] && shift \
               || gray 'Not called quantity of tests.'

      _hasnt_argument "$folder" 'folder'
      _has_folder "$folder"

      cd "./$folder/"
      _set_tests "$tests"

      _open_editor

    ;;

    'run' | 'r' )

      # Has to be in a folder's problem.
      _is_not_in_root

      root="$PWD"

      filename="$1"
      [ "$1" ] && shift

      if [ -f "$filename" ]; then
        #filename="$(basename "$filename")"
        language="$(echo "$filename" | awk -F '[.]' '{print $NF}')"
      else
        filename="$(echo source.*)"
        language="$(echo "$filename" | awk -F '[.]' '{print $NF}')"
      fi

      cd $(git rev-parse --show-cdup)
      build $language "$root" "$filename"
      cd "$root"
    ;;

    'create' | 'c' )

      [ "$1" ] && folder="$1" \
               || _hasnt_argument "$folder" 'folder'
      shift

      [ "$1" ] && extension="$1" \
               || _hasnt_argument "$extension" 'extension'
      shift

      tests="$1"
      [ "$1" ] && shift \
               || gray 'Not set quantity of tests. Default is none.'

      _hasnt_folder "$folder"

      cp -r "$(git rev-parse --show-cdup)templates/$extension/" "$folder"
      touch "$folder/$SOURCE.$extension"
      cd "$folder"

      "$(git rev-parse --show-cdup)$SCRIPT" run
      _set_tests "$tests"

      _open_editor

    ;;

    'test' | 't' )

      tests="$1"
      [ "$1" ] && shift \
               || gray 'Not called quantity of tests.'

      diff="$1"
      [ "$1" ] && shift \
               || gray 'Not called whether difference should be shown if failed. Default is true.'

      _is_not_in_root
      _has_folder 'tests'

      # Discover the quantity of tests in the root folder of the problem.
      quantity=$(fd --base-directory tests/ --extension in --size +1b | wc -l)

      if [[ "$tests" ]] && [[ "$tests" -gt $quantity ]]; then
        gray "There are not that many tests."
      fi

      failed=false

      # Run over each one.
      for a in {1..$quantity}; do

        filename="./tests/$a.in"

        if [ ! -s "$filename" ]; then
          gray "Input file $a is empty."
          continue
        fi

        input="$(cat "./tests/$a.in")"
        result="$("./binary" < "./tests/$a.in")"
        expected="$(cat "./tests/$a.out")"

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

        # If it got here, it failed.
        bold "$a.  INPUT:"
        gray "$input"

        bold "$a.   RESULT:"
        red "$result"

        if [ "$diff" ]; then
          mkdir -p './failed'
          echo "$result" > "./failed/$a.result"
          diff "./failed/$a.result" "./tests/$a.out"  --unified=0 > "./failed/$a.diff"
          rm -f "./failed/$a.result"
          failed=true
        fi

        bold "    EXPECTED:"
        gray "$expected"

        echo
      done

      if [ "$diff" ]; then
        _see_errors "$failed"
      fi

    ;;

  esac
}
