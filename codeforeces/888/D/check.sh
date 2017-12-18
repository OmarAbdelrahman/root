#!/bin/bash

for i in in*
do
  j=$(echo $i | tail -c +3 | head -c 1)
  out="out$j.out"
  ./main < $i > "res$j.out"
  if [ -z "$(diff -B res$j.out $out)" ]
  then
    echo "Test $j: OK"
  else
    echo "Test $j: WA"
    echo "Correct answer:"
    cat $out
    echo
    echo "Your answer:"
    cat "res$j.out"
    echo
  fi
done
