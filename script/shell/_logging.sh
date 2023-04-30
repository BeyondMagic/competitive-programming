#!/usr/bin/env sh
#
# @author
#   João F. BeyondMagic <koetemagie@gmail.com>

# Colorising.
__bold      () { echo "\033[3m$@\033[0m" }
__bold_gray () { echo "\033[2;3m$@\033[0m" }

__gray   () { echo "\033[2m$@\033[0m" }
__red    () { echo "\033[31m$@\033[m" }
__green  () { echo "\033[32m$@\033[m" }
__yellow () { echo "\033[33m$@\033[m" }

__bright_yellow () { echo "\033[93m$@\033[m" }

# Logging.
___log         () { [ "$LOG" ] && __gray $@ }
___log_bold    () { __bold_gray $@ }
___log_error   () { __red $@ }
___log_warning () { __yellow $@ }
___log_success () { __green $@ }
