#!/usr/bin/env zsh
#
# Tool to create, build, test, and modify competitive problems.
#
# @note
#   + Enviroment variables used:
#     - EDITOR, like nvim
#     - READER, like zathura
#
# @dependencies
#   zsh
#     https://www.zsh.org/
#   fd
#     github.com/sharkdp/fd
#   git
#     https://git-scm.com/
#
# @author
#   João F. BeyondMagic <koetemagie@gmail.com>

# Global variables.

SCRIPT="$(basename $0)"
SCRIPT_FOLDER="$(dirname "$0")"
SOURCE='source'
ROOT="$SCRIPT_FOLDER/.."
TEMPLATES="$ROOT/templates"
BUILDS="$ROOT/build"
PROBLEM='problem.pdf'

source "$SCRIPT_FOLDER"/_logging.sh

# Auxialiary functions to reduce code.
function _is_in_root () {
  if [ ! -f "./$SCRIPT" ]; then
    ___log_error "You have to be on the root path of the project to create a problem's folder."
    exit 1
  fi
}

function _is_not_in_root () {
  if [ -f "./$SCRIPT" ]; then
    ___log_error "You have to be on a folder's problem."
    exit 1
  fi
}

function _has_folder () {
  folder="$1"
  shift

  if [ ! -d "./$folder/" ]; then
    ___log_error "\"./$folder/\" problem's folder does not exist."
    exit 1
  fi
}

function _hasnt_folder () {
  name="$1"
  shift

  if [ -d "$name" ]; then
    ___log_error "\"$name\" folder or problem solution already exist."
    exit 1
  fi
}

function _has_template () {
  language="$1"
  shift

  if [ ! -d "$TEMPLATES/$language/" ]; then
    ___log_error "\"$language\" does not have template yet!"
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
    ___log_error "Specify the $reason's problem following the convention."
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
  #if [ ! -f "$root/$compile_file" ]; then
    mv -f "$compile_file" "$root/$compile_file"
  #fi
}

function build () {
  language="$1"
  shift

  case "$language" in

    'c' )

      cd "$BUILDS"/c/
      _build_bear_cpp_c $@

    ;;

    'c++' | 'cpp' )

      cd "$BUILDS"/c++/
      _build_bear_cpp_c $@

    ;;

    'typescript' | 'ts' )

      cd "$BUILDS"/typescript/
      build_typescript $@

    ;;

  esac
}

{
  action="$1"
  shift

  case "$action" in

    # @param string: modify or m. Modify a problem.
    #   @param string: name of project in case being in root path.
    'modify' | 'm' )

      folder="$1"
      shift

      tests="$1"
      [ "$1" ] && shift \
               || ___log 'Not called quantity of tests.'

      _hasnt_argument "$folder" 'folder'
      _has_folder "$folder"

      cd "./$folder/"
      _set_tests "$tests"

      [ -f "./$PROBLEM" ] && $READER "$PROBLEM" & disown

      _open_editor

    ;;

    # @param string: run or r. Build the project.
    #   @param string: name of project in case being in root path.
    #     @param boolean: force move compile_commands.json
    #   @param boolean: force move compile_commands.json
    'run' | 'r' )

      # Has to be in a folder's problem.
      _is_not_in_root

      problem_root="$PWD"

      filename="$1"
      [ "$1" ] && shift

      language="$(echo "$filename" | awk -F '[.]' '{print $NF}')"

      if [ ! -f "$filename" ]; then
        filename="$(echo source.*)"
      fi

      cd $ROOT
      build $language "$root" "$filename"
      cd "$problem_root"
    ;;

    # @param string: create or r
    #   @param string: name of project to be created.
    #   @param tests: quantity of tests to be used.
    #   @param language: C++ or C.
    'create' | 'c' )

      [ "$1" ] && folder="$1" \
               || _hasnt_argument "$folder" 'folder'
      shift

      [ "$1" ] && extension="$1" \
               || _hasnt_argument "$extension" 'extension'
      shift

      _has_template "$extension"

      # TODO: Pass link as next argument to download the problems' PDF.

      tests="$1"
      [ "$1" ] && shift \
               || ___log 'Not set quantity of tests. Default is none.'

      _hasnt_folder "$folder"

      cp -r "$TEMPLATES/$extension/" "$folder"
      touch "$folder/$SOURCE.$extension"
      cd "$folder"

      "$(git rev-parse --show-cdup)$SCRIPT" run
      _set_tests "$tests"

      _open_editor

    ;;

    # @param string: test or t. Will show input and output of all tests.
    #   @param number: quantity of tests to run.
    'test' | 't' )

      tests="$1"
      [ "$1" ] && shift \
               || ___log 'Not called quantity of tests.'

      diff="$1"
      [ "$1" ] && shift \
               || ___log 'Not called whether difference should be shown if failed. Default is false.'

      _is_not_in_root
      _has_folder 'tests'

      # Discover the quantity of tests in the root folder of the problem.
      quantity=$(fd --base-directory tests/ --extension in --size +1b | wc -l)

      if [[ "$tests" ]] && [[ "$tests" -gt $quantity ]]; then
        ___log "There are not that many tests."
      fi

      failed=false

      # Run over each one.
      for a in {1..$quantity}; do

        filename="./tests/$a.in"

        if [ ! -s "$filename" ]; then
          ___log "Input file $a is empty."
          continue
        fi

        input="$(cat "./tests/$a.in")"
        result="$("./binary" < "./tests/$a.in")"
        expected="$(cat "./tests/$a.out")"

        if [ $? -eq 0 ]; then
          if [ "$result" = "$expected" ]; then
            ___log_success "$a. $result"
            continue
          fi

          min_result="$(echo "$result" | awk '{$1=$1};1')"
          min_expected="$(echo "$expected" | awk '{$1=$1};1')"

          if [ "$min_result" = "$min_expected" ]; then
            ___log "Had to remove leading and trailing spaces."
            ___log_warning "$a. $result"
            continue
          fi

          min_result="$(echo "$min_result" | tr -d '\r\n')"
          min_expected="$(echo "$min_expected" | tr -d '\r\n')"
          if [ "$min_result" = "$min_expected" ]; then
            ___log "Had to remove newlines, leading and trailing spaces."
            ___log_warning "$a. $result"
            continue
          fi
        fi

        # If it got here, it failed.
        ___log_bold "$a.  INPUT:"
        ___log "$input"

        ___log_bold "$a.   RESULT:"
        ___log_error "$result"

        if [ "$diff" ]; then
          mkdir -p './failed'
          echo "$result" > "./failed/$a.result"
          diff "./failed/$a.result" "./tests/$a.out"  --unified=0 > "./failed/$a.diff"
          rm -f "./failed/$a.result"
          failed=true
        fi

        ___log_bold "    EXPECTED:"
        ___log "$expected"

        echo
      done

      if [ "$diff" ]; then
        _see_errors "$failed"
      fi

    ;;

  esac
}
