#!/bin/bash

# コンパイル
g++ "$1" -std=c++23 -O0 -g -I "${WORKSPACE_DIR}/.include/" -o "$2"

# テストファイルの内容を表示
if [ -f "$3" ]; then
    echo "Using input from $3:"
    cat "$3"
else
    echo "Test file not found: $3"
fi
