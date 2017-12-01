#!/bin/bash

make
./parser err.p
./parser decl.p
./parser err2.p
./parser test.p
./parser expr1.p
./parser statement.p
./parser mytest.p
