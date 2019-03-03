import sys

H = 0   # horizontal placement of a tile
V = 1   # vertical placement of a tile

def is_transversal(m, n, lenS, Sr, Sc, exhibit_untouched_tile):
    S = [ [0 for _ in range(n+1)] for _ in range(m+1)]
    for i in range(lenS):
       S[Sr[i]][Sc[i]] = 1

    for i in range(1,m+1):
        for j in range(1,n-1):
            intersects = 0 
            for k in range(3):
                if S[i][j+k] == 1:
                    intersects += 1
            if intersects==0:
                exhibit_untouched_tile(i,j,H)
                return 0
    for i in range(1,m-1):
        for j in range(1,n+1):
            intersects = 0 
            for k in range(3):
                if S[i+k][j] == 1:
                    intersects += 1
            if intersects==0:
                exhibit_untouched_tile(i,j,V)
                return 0
    return 1

def produce_min_transversal(m, n, place_in_S):
    if m <= 2:
        for j in range(1,n+1):
            for i in range(1,m+1):
                if j%3 == 0:
                    place_in_S(i, j)
    elif n <= 2:
        for i in range(1,m+1):
            for j in range(1,n+1):
                if i%3 == 0:
                    place_in_S(i, j)
    else:                
        for i in range(1,m+1):
            for j in range(1,n+1):
                if (i+j)%3 == 1:
                    place_in_S(i, j)  


def produce_max_packing(m, n, place_tile):
    if n%3 == 0 or m <= 2:
        for i in range(1,m+1):
            for j in range(1,n-1,3):
                place_tile(i,j,H)
        return
    if m%3 == 0 or n <= 2:
        for j in range(1,n+1):
            for i in range(1,m-1,3):
                place_tile(i,j,V)
        return
    for i in range(m-2,3,-3):
        for j in range(1,n+1):
            place_tile(i,j,V)
    m = 3 + m%3
    for j in range(n-2,3,-3):
        for i in range(1,m+1):
            place_tile(i,j,H)
    n = 3 + n%3
#    print("ora i casi particolari",file=sys.stderr)
    if m == 4 and n == 4:
         place_tile(1,1,V)
         place_tile(1,2,V)
         place_tile(1,3,V)
         place_tile(1,4,V)
         place_tile(4,1,H)
    if m == 4 and n == 5:
         place_tile(2,1,V)
         place_tile(2,2,V)
         place_tile(1,3,H)
         place_tile(2,3,H)
         place_tile(3,3,H)
         place_tile(4,3,H)
    if m == 5 and n == 4:
         place_tile(1,2,H)
         place_tile(2,2,H)
         place_tile(3,1,V)
         place_tile(3,2,V)
         place_tile(3,3,V)
         place_tile(3,4,V)
    if m == 5 and n == 5:
         place_tile(1,1,H)
         place_tile(2,1,H)
         place_tile(3,1,V)
         place_tile(3,2,V)
         place_tile(1,4,V)
         place_tile(1,5,V)
         place_tile(4,3,H)
         place_tile(5,3,H)

def max_card_of_a_packing(m, n):
    if m <= 2:
        return m*( n//3 )
    if n <= 2:
        return n*( m//3 )
    return (m*n)//3

def min_card_of_a_transversal(m, n):
    if m <= 2:
        return m*( n//3 )
    if n <= 2:
        return n*( m//3 )
    return (m*n)//3

