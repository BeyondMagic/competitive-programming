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
ROOT="$(git rev-parse --show-cdup)"
TEMPLATES="${ROOT}templates"
BUILDS="${ROOT}build"
PROBLEM='problem.pdf'

source "$SCRIPT_FOLDER"/_logging.sh

# Auxialiary functions to reduce code.
function _is_in_root () {
  if [ ! -d "./.git" ]; then
    ___log_error "You have to be on the root path of the project to create a problem's folder."
    exit 1
  fi
}

function _is_not_in_root () {
  if [ -d "./.git" ]; then
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

function _build_bear_cpp_c () {
  compile_file='compile_commands.json'

  export root="$1"
  shift

  export filename="$1"
  shift

  bear -- make build -s || exit 1
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

      [ -f "./$PROBLEM" ] && $READER "$PROBLEM" > /dev/null & disown

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

      if [ ! -f "$filename" ]; then
        filename="$(echo source.*)"
      fi

      language="$(echo "$filename" | awk -F '[.]' '{print $NF}')"

      # Exit if source file is the same as the last.
      {
        COMPILED_FOLDER="./compiled/$(dirname "$filename")"
        #printf "FOLDER of: %s\n" "$COMPILED_FOLDER"
        file_content="$(cat "$filename" | awk '{$1=$1};1' | tr -d '\r\n')"
        original_filename="$filename"
        filename="$(basename $filename)"
        mkdir -p "$COMPILED_FOLDER"
        if [ -f "$COMPILED_FOLDER/$filename" ]; then
          last_file_content="$(cat "$COMPILED_FOLDER/$filename" | awk '{$1=$1};1' | tr -d '\r\n')"
          if [ "$file_content" = "$last_file_content" ]; then
            #___log_bold "Built file already."
            exit 1
          fi
        fi
        cp -rf "$original_filename" "$COMPILED_FOLDER/$filename"
      }
      #cd "$ROOT"
      build $language "$problem_root" "$COMPILED_FOLDER/$filename"
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

      tests="$1"
      [ "$1" ] && shift \
               || ___log 'Not set quantity of tests. Default is none.'

      pdf_link="$1"
      [ "$1" ] && shift \
               || ___log 'Not set a PDF link to download.'

      _hasnt_folder "$folder"

      cp -r "$TEMPLATES/$extension/" "$folder"
      touch "$folder/$SOURCE.$extension"
      cd "$folder"

      curl "$pdf_link" -o "$PROBLEM"

      "$ROOT$SCRIPT" run
      _set_tests "$tests"

      #echo "PWD: $PWD"

      [ -f "$PROBLEM" ] && $READER "$PROBLEM" > /dev/null & disown

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

      echo "\033[46;1;38;5;15m JUDGE \033[0;2m $(basename "$PWD")/tests/ \033[0m\n "
      _START_TIME="$(date +"%T.%3N")"

      # Discover the quantity of tests in the root folder of the problem.
      quantity=$(fd --base-directory tests/ --extension in | wc -l)

      if [[ "$tests" ]] && [[ "$tests" -gt $quantity ]]; then
        ___log "There are not that many tests."
      fi

      failed=false
      _COMMANDS_READING=()
      _FILES_TO_TEST=0
      _TESTS_RESULT=()
      _COMMANDS_DURATION=()
      _FAILED=0
      results=()

      # Run over each one.
      for a in {1..$quantity}; do

        filename="./tests/$a.in"

        if [ ! -s "$filename" ]; then
          #echo "             \033[2m$a.in \033[0;90mempty\033[0m"
          _COMMANDS_READING+=('empty')
          _COMMANDS_DURATION+=('?')
          continue
        fi

        _COMMANDS_READING+=("$(du -sh $filename | awk '{print $1}')")
        ((_FILES_TO_TEST++))

        input="$(cat "./tests/$a.in")"
        _COMMAND_START="$(date +"%S.%3N")"
        results+=("$("./binary" < "./tests/$a.in")")
        _COMMANDS_DURATION+=("$(($(date +"%S.%3N") - $_COMMAND_START))")
        expected="$(cat "./tests/$a.out")"

        if [ $? -eq 0 ]; then
          if [ "$results[$a]" = "$expected" ]; then
            #echo "             \033[92m$a.in \033[2mpassed\033[0m"
            _TESTS_RESULT+=('passed')
            continue
          fi

          min_result="$(echo "$results[$a]" | awk '{$1=$1};1')"
          min_expected="$(echo "$expected" | awk '{$1=$1};1')"

          if [ "$min_result" = "$min_expected" ]; then
            _TESTS_RESULT+=('min_warning')
            #echo "             \033[33m$a.in \033[2mpassed\033[0m"
            #___log "Had to remove leading and trailing spaces."
            #___log_warning "$a. $result"
            continue
          fi

          min_result="$(echo "$min_result" | tr -d '\r\n')"
          min_expected="$(echo "$min_expected" | tr -d '\r\n')"
          if [ "$min_result" = "$min_expected" ]; then
            _TESTS_RESULT+=('max_warning')
            #echo "             \033[93m$a.in \033[33mpassed\033[0m"
            #___log "Had to remove newlines, leading and trailing spaces."
            #___log_warning "$a. $result"
            continue
          fi
        fi

        # If it got here, it failed.
        #___log_bold "$a.  INPUT:"
        #___log "$input"

        #___log_bold "$a.   RESULT:"
        #___log_error "$result"
        
        _TESTS_RESULT+=('failed')
        ((_FAILED))

        if [ "$diff" ]; then
          mkdir -p './failed'
          echo "$results[$a]" > "./failed/$a.result"
          diff "./failed/$a.result" "./tests/$a.out"  --unified=0 > "./failed/$a.diff"
          rm -f "./failed/$a.result"
          failed=true
        fi

        #___log_bold "    EXPECTED:"
        #___log "$expected"

        echo
      done

      if [ "$diff" ]; then
        _see_errors "$failed"
      fi

      printf " \e[2mTest Files\e[0m  %d total    \e[1m(%d)\e[0m\n" $quantity $_FILES_TO_TEST
      for i in {1..$quantity}; do
        printf '             '
        if [ "$_COMMANDS_READING[$i]" = 'empty' ]; then
paste file1 file2 | awk '{print $1,$2,$3,$5}'
          printf "\e[0;2m%s \e[90m%s" $i.in 'empty'
        else
          printf "\e[90m%s \e[2m%s" $i.in $_COMMANDS_READING[$i]
        fi
        printf "\e[0m\n"
      done

      printf " \e[2m     Tests\e[0m  %d passed \e[1m(%d)\e[0m\n" $_FILES_TO_TEST $(($_FILES_TO_TEST - $_FAILED))
      for i in {1..$quantity}; do
        printf '            '
        case "$_TESTS_RESULT[$i]" in

          'failed' )
            printf "\e[31m %s\t\t\t%s\t\t\t%s\n\e[90;1m" $i.in $i.out 'failed'
            #echo "\n$results[$i]" | sed 's_^_       _'
            # echo "1 1 1 0 0 0 0 0 0 0\n2 5 3 1 1 1 1 1 1 1" | paste 1.in 1.out - | column -s $'\t' -t
            #printf "%s"paste tests/$i.in tests/$i.out | column -s $'\t' -t | sed 's_^_             _'
            results[$i]="$(printf "$results[$i]" | sed -e 's_^_\\e[0;31;1m_' -e 's_$_\\e[0;90;1m_')"
            printf $results[$i] | paste tests/$i.in tests/$i.out - | column -s $'\t' -t | sed 's_^_             _'
            printf "             \e[0;31;2m"
            _TESTS_RESULT[$i]=''
          ;;

          'passed' )
            printf "\e[92m %s \e[2m" $i.in
          ;;

          'min_warning' )
            _TESTS_RESULT[$i]='passed'
            printf "\e[33m %s \e[2m" $i.in
          ;;

          'max_warning' )
            _TESTS_RESULT[$i]='passed'
            printf "\e[93m %s \e[33m" $i.in
          ;;
        esac
        printf "%s\e[0m\n" $_TESTS_RESULT[$i]
      done
      #echo " \033[2m  Start at\033[0m  $_START_TIME"
      printf " \e[2m  Duration\e[0m  1 passed\n"

      for i in {1..$quantity}; do
        printf "             \e[90m%s\e[1m " $i.in
        if [ ! "$_COMMANDS_DURATION[$i]" = '?' ]; then
          printf "%gs" $_COMMANDS_DURATION[$i]
        else
          printf "-"
        fi
        printf "\e[0m\n"
      done

      echo

    ;;

    # Will build and test.
    'judge' | 'j' )

      "$0" run
      "$0" test

    ;;

  esac
}
