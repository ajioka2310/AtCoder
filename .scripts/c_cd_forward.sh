#!/bin/bash

# カレントディレクトリを取得
current_dir=$(basename "$PWD")

# ルートディレクトリからの深さを取得
depth=$(echo "$PWD" | awk -F'/' '{print NF-1}')

# 現在のディレクトリが問題ディレクトリかを確認
if [[ $depth -ne 5 ]]; then
    echo "エラー: カレントディレクトリが問題ディレクトリではありません。"
    return 1
fi

# ディレクトリ一覧を取得してソート
dirs=($(ls -d ../*/ | sed 's|../||;s|/||' | sort))

# 現在のディレクトリのインデックスを取得
current_index=-1
for i in "${!dirs[@]}"; do
    if [[ "${dirs[$i]}" == "$current_dir" ]]; then
        current_index=$i
        break
    fi
done

# 次のディレクトリに移動
if [[ $current_index -ge 0 && $current_index -lt $((${#dirs[@]} - 1)) ]]; then
    next_dir="../${dirs[$(($current_index + 1))]}"
    cd "$next_dir"
else
    # 次のディレクトリがない場合は最初のディレクトリに戻る
    cd "../${dirs[0]}"
fi

# ファイルを開く
if command -v code &> /dev/null; then
    code main.py
elif command -v cursor &> /dev/null; then
    cursor main.py
fi
