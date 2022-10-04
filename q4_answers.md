## PART A
1 --> llrec((5,6), (2,3,4)) ==> 5 --> llrec((2,3,4), 6) ==> 2 --> llrec(6, (3,4)) ==> 6 --> llrec((3,4), nullptr) ==> 3 --> 4
Therefore, the returned linked list is now 
### 1 --> 5 --> 2 --> 6 --> 3 --> 4

## PART B
hits if (in1 == nullptr) and returns 2
### 2

