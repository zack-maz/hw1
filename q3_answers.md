## PART A
### Big-Theta(log(log(N)))
i squares every time and starts at 2.  
i can be written as 2^2^k < n  
So, log base 2 of n = 2^k  
So, log base 2 of log base 2 of n = k  
So, the runtime is log(log(n))


## PART B
### Big-Theta(N^(7/2))
the outer for loop doesn't matter, only how many times we hit or don't hit the if statement  
we hit the if statement sqrt(n) times  
the for loop always goes from 0 to $k\sqrt{n}$ where 0 < k < $\sqrt{n}$  
Essentially, the values which pass the if are sqrt(n), 2sqrt(n), 3sqrt(n)... sqrt(n)sqrt(n)  
Since we're cubing our values, our sum is:  
= $\sum_{k=0}^{\sqrt{n}} k^3 n^{3/2}$  
= $n^(\frac{3}{2}) \frac{(\sqrt{n} (\sqrt{n} + 1))^2}{2}$  
Getting the largest value, we see   
$\sqrt{n} n^2$  
= $n^(\frac{7}{2})$  
The number of times we don't hit the for loop is less than we hit it, so it's negligible


## PART C
### Big-Theta(N^2)
firstly, let's check how many times we hit the if statement  
worst case scenario, A[k] = i n times where all values 1 < i < n are in A[k] or all values of A[k] are the same and within the described bounds  
our for loop increments by doubling everytime  
$2^m = n$  
$\log(n) = m$ as the runtime  
So, we have $n \log(n)$  
However, the if statement has a runtime of O(1) and hits n^2 times  
So, our runtime is $n^2 + n \log(n)$ or rather just $n^2$ 


## PART D
### Big-Theta(N)
size starts at 10 and increases by 3/2 over time  
So, n = 10 * (3/2)^k  
k = log(n/10) base 3/2  
the inner for loop hits every time size is hit, which is 10 * (3/2)^k for some k  
Let m = log(n/10) base 3/2  
So, $10 \sum_{k=0}^{m} (\frac{3}{2})^k$  
 = $\frac{10(1 - \frac{3}{2}^m)}{1-\frac{3}{2}}$  
  = $\frac{10(\frac{n}{10}-1)}{\frac{1}{2}}$  
  = $2n-20$

