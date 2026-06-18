'''
Understanding
    input: integer n representing coins available
    output: int k representing # of rows built
    condition: last row can be incomplete (but it doesn't count)

Plan
    - `next_row` number of coins needed for the next row
    - `built_row` number that was used previously
        initially 1
    - loop while n != 0
        - update n, in each row n must decerment by `nex_row`
        - update `next_row` it must increase from its current value plus ONE
                n = 4   next_row = 1    built_row = 1
                n = 4-1 next_row = 1+1 (2)   built_row +=1
        - `built_row` updates as long as 
        - if n-next_row < 0
            - there isn't enough coins to make the row
        - else
            next_row += 1
            built_row +=1
            n = n-next_row
    - return built_row

'''
class Solution:
    def arrangeCoins(self, n: int) -> int:
        next_row = 1
        built_row = 0
        while n >= next_row:
            if n-next_row < 0:
                break
            else:
                n -= next_row
                next_row += 1
                built_row +=1
                   
        return built_row
        