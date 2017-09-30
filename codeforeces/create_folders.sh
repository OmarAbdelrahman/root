#!/bin/bash

for i in $(eval echo {A..$2})
do
  if [ ! -d "$1/$i" ]
  then
    ./create_folder.sh $1 $i
  fi
done
