## Compiled with

```
$ g++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.2.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

`g++ -c *.cpp && g++ *.o -o exam.out && cat input.txt | exam.out`

where `input.txt` is a file in the same directory with the expected input

```
$ cat input.txt
4
123  3121
12 1523
-43550 340
123 456
```

## Expected output

```
Equal strength
First is weaker
Second is weaker
Not comparable
```
