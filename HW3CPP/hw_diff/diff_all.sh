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

./parser_teacher advanced.p > advanced_teacher.txt
./parser advanced.p > advanced_student.txt
vimdiff advanced_teacher.txt advanced_student.txt

./parser_teacher basic.p > basic_teacher.txt
./parser basic.p > basic_student.txt
vimdiff basic_teacher.txt basic_student.txt

./parser_teacher error.p > error_teacher.txt
./parser error.p > error_student.txt
vimdiff error_teacher.txt error_student.txt

./parser_teacher test.p > test_teacher.txt
./parser test.p > test_student.txt
vimdiff test_teacher.txt test_student.txt
