This is a simple collection of C++ files, where
[Clang Tidy](https://clang.llvm.org/extra/clang-tidy/)
either doesn't find problems which exist
([false negative](https://en.wikipedia.org/wiki/False_positives_and_false_negatives))
or finds errors, which are not errors
([false positive](https://en.wikipedia.org/wiki/False_positives_and_false_negatives)).

For reference: the list of Clang-Tidy checks can be found [here](
https://clang.llvm.org/extra/clang-tidy/checks/list.html).

To run all together, just do this:

```
$ make
```

You are welcome to submit your own cases.