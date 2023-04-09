#include <ctype.h>    // 文字処理
#include <stdio.h>    // 入出力
#include <stdlib.h>   // 汎用
#include <string.h>   // 文字列処理
#include <stdbool.h>  // 真偽値

#define DIGITS 10 + 1 // 配列の要素数（'+'と'-'を勘案して要素数を1つ増やしている）
#define LIMIT 30      // fgets関数で受け付ける上限文字数


// 桁数チェックのための関数
// 第1引数：入力された数字列、第2引数：（格納可能とする）最大桁数
// 戻り値：データとしての可否
bool checkDigits(char *str, int max)
{
    int  len = 0;       // 文字列長
    bool flg = false;   // 可／不可（デフォルトでは不可）

    len = strlen(str);  // 文字列長の取得

    // 文字列の先頭に符号がある場合、数字桁に反映しない
    if ((str[0] == '-') || (str[0] == '+')) {
        len--;
    }

    // 最大桁数以下の場合、データとして可
    // 最大桁数より大きい場合は不可とする
    if (len <= max) {
        flg = true;
    } else {
        flg = false;
    }

    return flg;
}


// 文字種判定関数（数字を可とする）
// 引数：入力された数字列
// 戻り値：データとしての可否
bool checkCharKind(char *str)
{
    int  i   = 0;     // カウンタ
    int  len = 0;     // 文字列長
    bool flg = false; // 可／不可（デフォルトでは不可）

    len = strlen(str) - 1;  // 配列参照のため1を減じる
    str[len] = '\0';        // 配列の最後尾にナル文字を格納する

    // 文字種判定部分
    while (str[i] != '\0') {
        if (str[i] == '-' || str[i] == '+') {
            if (i == 0) {
                i++;
            } else {
                break;
            }
        } else if (isdigit(str[i])) {
            i++;
        } else {
            break;
        }
    }

    // カウンタと文字列長との比較で可／不可を最終的に判定する
    if (i == len) {
        flg = true;
    } else {
        flg = false;
    }

    return flg;
}

// エターナルポイント（プログラムの始点）
int main(void)
{
    int  num = 0;         // 入力される数値
    bool flg = false;     // ループ判定
    char str[DIGITS + 1]; // 入力する数字列

    // 入力受付部分
    do {
        printf("\nInput number(10 digits or under) :  ");
        fgets(str, LIMIT, stdin);

        // 文字種判定
        if (checkCharKind(str)) {
            flg = true;
        } else {
            printf("\nInput \"number\":-< \n");
            memset(str, '\0', sizeof(str));
            flg = false;
        	continue;
        }

        // 桁数判定
        if (checkDigits(str, DIGITS - 1)) {
            flg = true;
        } else {
            printf("\nInput %d digits or under:-( \n", DIGITS - 1);
            memset(str, '\0', sizeof(str));
            flg = false;
            continue;
        }

    } while (!flg);

    // 判定をパスしたら数字列を数値に変換する
    num = atoi(str);

    // ディスプレイに出力
    printf("%d\n", num);

    // プログラム正常終了
    return 0;
}