/*
問題文
長さ N の整数列 A があります。

A の 空でない 連続する 部分列であって、その総和が 0 になるものの個数を求めてください。 ただし、ここで数えるのは 部分列の取り出し方 であることに注意してください。 つまり、ある 2 つの部分列が列として同じでも、取り出した位置が異なるならば、それらは別々に数えるものとします。

制約
1≤N≤2×105
−109≤Ai≤109
入力はすべて整数である。
入力
入力は以下の形式で標準入力から与えられる。

N
A1 A2 … AN
出力
A の空でない連続する部分列であって、その総和が 0 になるものの個数を出力せよ。
*/

#include <stdio.h>

int main() {
  int n;
  long a[20001];
  int i,j;
  long count = 0, sum;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%ld", a[i]);
  }

  for(j = 0; j < n; j++){
    sum = 0;
    for(i = j; i < n; i++){
      sum += a[i];
      if(sum == 0){
        count++;
      }
    }
  }


  printf("%ld", count);

  return 0;
}