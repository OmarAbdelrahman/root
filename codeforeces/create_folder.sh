#!/bin/bash

if [ -d $1 ]
then
  cd $1
else
  mkdir $1
  cd $1
fi

if [ ! -d $2 ]
then
  mkdir $2
  cp ../parse_task.py .
  cp ../parse_tasks.py .
  cp ../compile.sh ./$2
  cp ../template.cpp ./$2/main.cpp
  cp ../check.sh ./$2
  echo $1/$2
fi
