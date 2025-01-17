#!/bin/bash

# 確認メッセージを表示してユーザーの入力を待つ
read -n 1 -p "現在開いているファイルを提出しますか？ (y/N): " confirm

# "y" 以外が入力された場合はスクリプトを終了
if [[ "$confirm" != "y" ]]; then
    echo 
    echo "提出がキャンセルされました。"
    exit 0
fi

# 開いているファイルパスを取得
file_path="$1"

# ファイルパスが無効でないか確認
if [[ -z "$file_path" ]]; then
    echo "エラー: ファイルパスを取得できませんでした。タスクの設定を確認してください。"
    exit 1
fi

# ファイルのディレクトリに移動
cd "$(dirname "$file_path")" || exit 0

# 提出の実行
# 提出先タスクを指定するため、-t フラグを追加
PARENT=$(basename "$(dirname "$(pwd)")")  # 親ディレクトリ名を取得
CURRENT=$(basename "$(pwd)")             # カレントディレクトリ名を取得
TASK="${PARENT}_${CURRENT}"
TASK=$(echo "$TASK" | tr '[:upper:]' '[:lower:]')  # 小文字に変換
# echo $TASK
# timeout 20s acc submit main.cpp -t "$TASK" -- --no-open -y
timeout 20s acc submit main.py -t "$TASK" -- --no-open -y --language 5078
exit 0
