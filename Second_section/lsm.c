/* lsm.c                            */
/* 最小二乗法による計算式の決定     */
/* 統計的な機械学習の例題プログラム */

#include <stdio.h>

#define TEXTLENGTH 4096

int main()
{
  char text [TEXTLENGTH] ;
  double xi, yi ;
  double sxi = 0, syi = 0, sxiyi = 0, sxi2 = 0 ;
  double a0, a1 ;
  int n = 0;
  
  while (fgets (text, TEXTLENGTH, stdin) != NULL) {
    if (sscanf (text, "%lf %lf", &xi, &yi) == 2) {
      sxi += xi ;
      syi += yi ;
      sxiyi += xi * yi ;
      sxi2 += xi * xi ;
      ++n ;
    } else{
      fprintf (stderr, "不正なデータです：%s", text);
    }
  }
  
  if( n > 1) {
    a0 = ( sxi2 * syi - sxiyi * sxi) / ( n * sxi2 - sxi * sxi) ;
    a1 = ( n * sxiyi - sxi * syi) / ( n * sxi2 - sxi * sxi);
    
    printf ("%lf\n%lf\n", a0, a1) ;
  } else{
    fprintf (stderr, "データが足りません\n");
  }
  
  return 0;
}
