This is a simple collection of C++ files, where
[Clang Tidy](https://clang.llvm.org/extra/clang-tidy/)
either doesn't find problems which exist
([false negative](https://en.wikipedia.org/wiki/False_positives_and_false_negatives))
or finds errors, which are not errors
([false positive](https://en.wikipedia.org/wiki/False_positives_and_false_negatives)).

The list of Clang-Tidy checks can be found [here](
https://clang.llvm.org/extra/clang-tidy/checks/list.html).

The source of known issues in C/C++ programs is
[Common Weakness Enumeration (CWE)](https://cwe.mitre.org/index.html)
and
[Juliet Test Suite for C/C++](https://samate.nist.gov/SARD/test-suites/112).

To run all together, just do this:

```
$ make
```

You are welcome to submit your own cases.