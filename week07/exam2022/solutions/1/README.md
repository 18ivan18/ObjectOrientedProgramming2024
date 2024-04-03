## Compiled with
```
$ g++ --version 
g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```



`g++ -c *.cpp && g++ *.o -o 1.out && cat input.txt | 1.out`

where `input.txt` is a file in the same directory with the content of a `NaturalNumbers` object, e.g.

```
$ cat input.txt
5
1 2 5 5 42
Set of random numbers
```

## Expected output
```
Empty Set with 0 items

1 is not unique
2 is not unique
3 is not unique
One digit numbers with 10 items
0 1 2 3 4 5 6 7 8 9 
One digit numbers with 10 items
0 1 2 3 4 5 6 7 8 9 
One digit numbers with 10 items
0 1 2 3 4 5 6 7 8 9 
Two digit divisible by 33 with 3 items
33 66 99 
Union of One digit numbers and Two digit divisible by 33 with 13 items
0 1 2 3 4 5 6 7 8 9 33 66 99 
Union of Special numbers and One digit numbers with 13 items
42 420 69 0 1 2 3 4 5 6 7 8 9 
Is 5 a one digit number? true
Is 10 a one digit number? false
5 is not unique
Set of random numbers with 4 items
1 2 5 42 
```