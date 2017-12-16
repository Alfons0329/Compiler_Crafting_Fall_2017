#!/bin/bash
./parser Array.p > arrout_student.txt
vim arrout_student.txt

./parser basicSym.p > basicSymout_student.txt
vim basicSymout_student.txt

./parser Function.p > Functionout_student.txt
vim Functionout_student.txt

./parser Redefined.p > Redefinedout_student.txt
vim Redefinedout_student.txt

./parser Loopredefined.p > Loopredefinedout_student.txt
vim Loopredefinedout_student.txt

./parser advanced.p > advanced_student.txt
vim advanced_student.txt

./parser basic.p > basic_student.txt
vim basic_student.txt

./parser error.p > error_student.txt
vim error_student.txt

./parser test.p > test_student.txt
vim test_student.txt
