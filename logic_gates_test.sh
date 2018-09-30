#!/bin/bash
ECHO "Testing AND"
ECHO ""
ECHO | ./logic_gates -a 0 0
ECHO | ./logic_gates -a 0 1
ECHO | ./logic_gates -a 1 0
ECHO | ./logic_gates -a 1 1
ECHO ""
ECHO ""


ECHO "Testing OR"
ECHO ""
ECHO | ./logic_gates -o 0 0
ECHO | ./logic_gates -o 0 1
ECHO | ./logic_gates -o 1 0
ECHO | ./logic_gates -o 1 1
ECHO ""
ECHO ""


ECHO "Testing XOR"
ECHO ""
ECHO | ./logic_gates -x 0 0
ECHO | ./logic_gates -x 0 1
ECHO | ./logic_gates -x 1 0
ECHO | ./logic_gates -x 1 1
ECHO ""
ECHO ""


ECHO "Testing NOT"
ECHO ""
ECHO | ./logic_gates -n 0 1
ECHO | ./logic_gates -n 1 0
ECHO ""
ECHO ""