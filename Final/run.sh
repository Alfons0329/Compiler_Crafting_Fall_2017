#!/bin/bash
JASMIN="./jasmin/jasmin.jar"
read -p "Input testcase without .p filename:  " FILE_NAME
PNAME="$FILE_NAME.p"
JNAME="$FILE_NAME.j"
CLASSNAME=FILE_NAME
make
echo "Pname is $PNAME Jname is $JNAME Filename is $FILE_NAME"
./parser Examples/"$PNAME"
echo "Parsing succeeded ready for execution"
java -jar "$JASMIN" "$JNAME"
java "$FILE_NAME"
echo "End running program"
#make clean
#rm -f "$FILE_NAME.class"
#rm -f "$FILE_NAME.j"
