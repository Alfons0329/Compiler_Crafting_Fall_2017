#!/bin/bash
make
./parser_teacher Array.p > arrout_teacher.txt
./parser Array.p > arrout_student.txt
vimdiff arrout_teacher.txt arrout_student.txt

./parser_teacher basicSym.p > basicSymout_teacher.txt
./parser basicSym.p > basicSymout_student.txt
vimdiff basicSymout_teacher.txt basicSymout_student.txt

./parser_teacher Function.p > Functionout_teacher.txt
./parser Function.p > Functionout_student.txt
vimdiff Functionout_teacher.txt Functionout_student.txt

./parser_teacher Redefined.p > Redefinedout_teacher.txt
./parser Redefined.p > Redefinedout_student.txt
vimdiff Redefinedout_teacher.txt Redefinedout_student.txt

./parser_teacher Loopredefined.p > Loopredefinedout_teacher.txt
./parser Loopredefined.p > Loopredefinedout_student.txt
vimdiff Loopredefinedout_teacher.txt Loopredefinedout_student.txt
