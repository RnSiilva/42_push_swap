<h1 align="center">
  push_swap
</h1>

<p align="center">
	<b><i>Because Swap_push isn’t as natural</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/RnSiilva/42_push_swap?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/RnSiilva/42_push_swap?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/RnSiilva/42_push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/RnSiilva/42_push_swap?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
	<span> · </span>
	<a href="#-study-summary">Study Summary</a>
</h3>

---

## 💡 About the project

> _This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions._

	🚀 TLDR: this project consists of coding a program that finds the lowest possible number of moves to
	sort a random list of integers using 2 stacks and a limited set of operations

## 📑 Index

* [**📁 includes:**](push_swap/inc/) contains the program's headers.
* [**📁 srcs:**](push_swap/srcs/) contains the source code of the program.
* [**Makefile**](push_swap/Makefile) - contains instructions for compiling the program and testing it.

_Note: only mandatory requirements of the project's subject are covered._

## 🛠️ Usage

### Requirements

The program is written in C language for **Linux** distributions and thus needs the **`clang` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ make
```

**2. Executing the program**

To execute the program, run:

```shell
$ ./push_swap $ARG
```

where `$ARG` is a space separated list of integers, e.g. `ARG="1 5 2 4 3"`

**3. Example**
```shell
$ ARG="1 5 2 4 3"; ./push_swap $ARG
```

---
## Grade: 100 / 100

## 📋 Testing

You can use this third party tester to fully test the project:

- Push-Swap-Tester (gemartin99): https://github.com/gemartin99/Push-Swap-Tester
- Push_swap_visualizer (o-reo): https://github.com/o-reo/push_swap_visualizer


## 📌 Useful Links

* [[YOUTUBE] push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk)
* [[MEDIUM] Turk method](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## 🤓 Study Summary

### Actions

**PUSH**

Take the first element at the top of one stack and put it at the top of the other; do nothing if the origin stack is empty.

* **`pa`** - top element of _stack b_ goes to top of _stack a_.
* **`pb`** - top element of _stack a_ goes to top of _stack b_.

**SWAP**

Swap the first 2 elements at the top of the stack; do nothing if there is only one or no elements.

* **`sa`** - swap  _stack a_.
* **`sb`** - swap  _stack b_.
* **`ss`** - `sa` and `sb` at the same time.

**ROTATE**

Shift up all elements of the stack by one; the first element becomes the last.

* **`ra`** - rotate stack a.
* **`rb`** - rotate stack b.
* **`rr`** - `ra` and `rb` at the same time.

**REVERSE ROTATE**

Shift down all elements of the stack by one; the last element becomes the first.

* **`rra`** - reverse rotate stack a.
* **`rrb`** - reverse rotate stack b.
* **`rrr`** - `rra` and `rrb` at the same time.
