#!/bin/bash

if [[ -f hello.txt ]] ; then cat hello.txt ; fi
if [ -f hello.txt ] ; then cat hello.txt ; fi
if test -f hello.txt ; then cat hello.txt ; fi
