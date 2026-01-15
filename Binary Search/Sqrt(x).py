def mySqrt(x : int) -> int:
    if x < 2 :
        return x
    l = 0 
    r = x
    while( l <= r ):
        mid = l + ( r - l ) // 2
        sq = mid * mid 
        if sq == x :
            return mid 
        elif sq > x :
            r = mid - 1
        elif sq < x :
            l = mid + 1
    return r

print(mySqrt(5))