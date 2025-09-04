# Drosrok

Drosrok can help you find the word you are looking for when solving a crosswords.

It currently only works with Swedish words.

## Compilation

Move to the root of this repo and run:

```shell
$ mkdir build && cd build
$ cmake ..
$ make
```

## Execution

Execute the program by running the below command from `build/` after compilation.

```shell
$ ./drosrok [QUERY]
```

Where `[QUERY]` is the search query.
Empty cells are represented by (`_`).

## Tests

The program also contains unit tests, which can be executed by running the below command from `build/` after compilation.

```shell
$ ./tests
```