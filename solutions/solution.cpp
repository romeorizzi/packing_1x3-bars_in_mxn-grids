static const int H = 0;
static const int V = 1;

int is_transversal(int m, int n, int lenS, int *Sr, int *S, void exhibit_untouched_tile(int row, int col, int dir)) {
  int S[101][101];
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
      S[i][j] = 0;
  for(int i = 0; i < lenS; i++) {
     S[Sr[i]-1][Sc[i]-1] = 1;
  }

  for(int i = 1; i <= m; i++)
    for(int j = 1; j+2 <= n; j++) {
      int intersects = 0; 
      for(int k = 0; k<3; k++)
        if(S[i][j+k])
	  intersects++;
      if(intersects==0)
	exhibit_untouched_tile(i,j,H);
	return 0;
    }  
  for(int i = 1; i+2 <= m; i++)
    for(int j = 1; j <= n; j++) {
      int intersects = 0; 
      for(int k = 0; k<3; k++)
        if(S[i+k][j])
	  intersects++;
      if(intersects==0)
	exhibit_untouched_tile(i,j,V);
	return 0;
    }  
  return 1;
}

void produce_min_transversal(int m, int n, void place_in_S(int row, int col)) {
  if(m <= 2) {
    for(int j=1; j<=n; j++)
      for(int i=1; i<=m; i++)
	if(j%3 == 0)
	  place_in_S(i, j);
  }
  else if(n <= 2) {
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n ;j++)
	if(i%3 == 0)
	  place_in_S(i, j);
  }
  else {
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n ;j++)
	if( (i+j)%3 == 1)
	  place_in_S(i, j);
  }
}
void produce_max_packing(int m, int n, void place_tile(int row, int col, int dir)) {
  if((n%3 == 0) || (m <= 2)) {
    for(int i = 1; i <= m; i++)
      for(int j = 1; j+2 <= n; j += 3)
        place_tile(i,j,H);
    return;
  if((m%3 == 0) || (n <= 2)) {
    for(int j = 1; j <= n; j++)
      for(int i = 1; i+2 <= m; i += 3)
        place_tile(i,j,V);
    return;
  }	 
  for(int i = m-2; i > 3; i-=3)
    for(int j = 1; j <= n; j++)
      place_tile(i,j,V);
  m = 3 + (m%3);
  for(int j = n-2; j > 3; j-=3)
    for(int i = 1; i <= m; i++)
      place_tile(i,j,H);
  n = 3 + (n%3);
  if( (m == 4) && (n == 4) ) {
    place_tile(1,1,V);
    place_tile(1,2,V);
    place_tile(1,3,V);
    place_tile(1,4,V);
    place_tile(4,1,H);
  }
  if( (m == 4) && (n == 5) ) {
    place_tile(2,1,V);
    place_tile(2,2,V);
    place_tile(1,3,H);
    place_tile(2,3,H);
    place_tile(3,3,H);
    place_tile(4,3,H);
  }
  if( (m == 5) && (n == 4) ) {
    place_tile(1,2,H);
    place_tile(2,2,H);
    place_tile(3,1,V);
    place_tile(3,2,V);
    place_tile(3,3,V);
    place_tile(3,4,V);
  }
  if( (m == 5) && (n == 5) ) {
    place_tile(1,1,H);
    place_tile(2,1,H);
    place_tile(3,1,V);
    place_tile(3,2,V);
    place_tile(1,4,V);
    place_tile(1,5,V);
    place_tile(4,3,H);
    place_tile(5,3,H);
  }
}
int max_card_of_a_packing(int m, int n) {
  if(m <= 2)
    return m*( n/3 );
  if(n <= 2)
    return n*( m/3 );
  return (m*n)/3;
}
int min_card_of_a_transversal(int m, int n) {
  if(m <= 2)
    return m*( n/3 );
  if(n <= 2)
    return n*( m/3 );
  return (m*n)/3;
}
