#!/bin/bash

make
./parser_exec err.p
./parser_exec decl.p
./parser_exec err2.p
./parser_exec test.p
./parser_exec expr1.p
./parser_exec statement.p
