## Exercise: LinkedLists (20 Points)

The objective of this project is to learn about implementing your first
data structure. In this assignment you will implement the methods that
add and remove elements from a linked list. The rest of the functionality
of a linked list is provided for you.

### Getting Started

The first thing you will need to do is accept the invitation to this 
assignment from GitHub Classroom. You can click 
[here](https://classroom.github.com/a/58TIHTBb) to accept the 
invitation, and get started.

Be sure that you accept the invitation first and use the URL to your new project when you clone it in CLion. After copying
the URL into the clipboard, in CLion click **VCS -> Checkout from Version Control -> Git**. Paste the URL into the **URL** box of the _Clone Repository_ dialog box and press **Clone**.


### Requirements of this project

This project is based on the linked list data structure as defined in C++-11. To see more details,
take a look at the documentation on the [CPP Reference](https://en.cppreference.com/w/cpp/container/list) 
website or the [C++ official](http://www.cplusplus.com/reference/list/list/) site. 

You will implement the following methods of the generic (or templated) `list` class.

 | Method name     | Return type | Input parameters      | Description                                                     |
 |-----------------|-------------|-----------------------|-----------------------------------------------------------------|
 |`push_front`     | `void`      | `const &Ty`           | Insert a value to the front of the list                         |
 |`pop_front`      | `void`      | `void`                | Erase a value from the front of the list                        |
 |`push_back`      | `void`      | `const &Ty`           | Insert a value at the back of the list                          |
 |`pop_back`       | `void`      | `void`                | Erase a value at the back of the list                           |
 |`insert`         | `iterator`  | `iterator, const &Ty` | Insert a value before the iterator and return that position     |
 |`erase`          | `iterator`  | `iterator`            | Erase a value at the iterator and return the iterator after it.                                           |
 |`erase`          | `iterator`  | `iterator, iterator`  | Erase all values from the first (inclusive) to last (exlusive) iterator and return the iterator after it. |
 |`clear`          | `void`      | `void`                | Erase all elements from the list |
 
### Writing the code for this Project

There are only three requirements for creating the code for this project correctly. One,
fill in all required code for the class `list` in the namespace `edu::vcccd::vc::csv13` with
the give interface from above. Two, you'll want a `main.cc` to test your code before doing all
the official tests, it should be in the `src` directory.
Three, you should should be able to replace all calls to your code and have the same behavior 
with the `std::list` implementation. You can test this by changing the `using namespace edu::vcccd::vc::csv15::list` 
`std::list` in main.cc.

#### All files must have the header comment

Be sure to add the proper header comment to each `.cc` and `.h` file you add to this project.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `LinkedLists | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It could look something like this:

```bash
size: 4
12
11
10
8
size: 0
0
1
2
3
4
5
6
7
8
9
size: 10
Size: 0

Process finished with exit code 0
```

But in this case, it could be whatever you want to make sure you code works.

Once your code runs and behaves the way you want, Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `LinkedLists Tests | Debug` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Testing started at 12:34 PM ...
/tmp/tmp.DBuo33Jk7q/cmake-build-debug/../bin/LinkedLists_GTest --gtest_filter=* --gtest_color=no
Running main() from gtest_main.cc
Your unit test score is 19 out of 20 (-1)
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.


Process finished with exit code 0
```

You should also see your score for this assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `main.cc`, and our changes/additions to `list.h`.
Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
