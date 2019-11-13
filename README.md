## Exercise: Stacks (20 Points)

The objective of this project is to learn about implementing your second
data structure and apply to a problem to solve. In this assignment you will 
implement the methods of a stack using either your linked list or STL's. Then
you'll use that stack to implement a simple function that checks the balance
of parentheses and others.

### Getting Started

The first thing you will need to do is accept the invitation to this 
assignment from GitHub Classroom. You can click 
[here](https://classroom.github.com/a/58TIHTBb) to accept the 
invitation, and get started.

Be sure that you accept the invitation first and use the URL to your new project when you clone it in CLion. After copying
the URL into the clipboard, in CLion click **VCS -> Checkout from Version Control -> Git**. Paste the URL into the **URL** box of the _Clone Repository_ dialog box and press **Clone**.


### Requirements of this project

This project is based on the stack data structure as defined in C++-11. To see more details,
take a look at the documentation on the [CPP Reference](https://en.cppreference.com/w/cpp/container/stack) 
website or the [C++ official](http://www.cplusplus.com/reference/stack/stack/) site. 

You will implement the following methods of the generic (or templated) `stack` class.

 | Method name     | Return type | Input parameters      | Description                                                     |
 |-----------------|-------------|-----------------------|-----------------------------------------------------------------|
 |`push`           | `void`      | `const &Ty`           | Insert a value to the top of the stack                         |
 |`pop`            | `void`      | `void`                | Erase a value from the top of the stack                        |
 |`top`            | `const &Ty` | `void`                | Return the value at the top of the stack                        |
 |`empty`          | `bool`      | `void`                | Returns true if the stack is empty, false otherwise                        |
 |`size`           | `size_t`    | `void`                | Returns the number of elements on the stack                        |
  
Additionally, you'll also write a function object that determines if a specific delimiter pair is 
is balanced. For example, a common delimiter pair is parentheses, the `(` and `)` characters. Using
a stack you can determine if the delimiters are properly balanced by pushing any beginning delimiter
on the stack and popping when reading an ending delimiter. If the stack is empty, and as long as 
you never read an ending delimiter when the stack is empty, then the delimiters are balanced.

For this part of the project we will use the concept of a function object. In that way we can make it
templated, and then defined specific instances for different pairs of delimiters. Your code will only
need to go in the file `balanced.h`, in the `operator() (const std::string &code)` function.

The file looks like this:

```cpp
#include <string>
#include "stack.h"

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template <char Open, char Close>
    struct Balancer {
        bool operator ()(const std::string &code) {
            // Put your code here using the stack you wrote
        }
    };

    // Declarations of different function objects for different delimiter pairs
    extern Balancer<'(', ')'> balanced_parens;
    extern Balancer<'{', '}'> balanced_curly;
    extern Balancer<'[', ']'> balanced_square;
    extern Balancer<'<', '>'> balanced_angle;
}}}}
```

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
Configuration* called `Stacks | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It could look something like this:

```bash
/tmp/tmp.s3fwukqGrW/cmake-build-debug/../bin/Stacks
unbalanced
balanced

Process finished with exit code 0
```

But in this case, it could be whatever you want to make sure you code works.

Once your code runs and behaves the way you want, Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `Stacks Tests | Debug` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
/tmp/tmp.s3fwukqGrW/cmake-build-debug/../bin/Stacks_GTest
Running main() from gtest_main.cc
[==========] Running 8 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 8 tests from StacksFixture
[ RUN      ] StacksFixture.TestEmptyStack
[       OK ] StacksFixture.TestEmptyStack (0 ms)
[ RUN      ] StacksFixture.TestStackPushTop
[       OK ] StacksFixture.TestStackPushTop (0 ms)
[ RUN      ] StacksFixture.TestStackPop
[       OK ] StacksFixture.TestStackPop (0 ms)
[ RUN      ] StacksFixture.TestStackPopulated
[       OK ] StacksFixture.TestStackPopulated (0 ms)
[ RUN      ] StacksFixture.TestEmptyParens
[       OK ] StacksFixture.TestEmptyParens (0 ms)
[ RUN      ] StacksFixture.TestBalancedAngles
[       OK ] StacksFixture.TestBalancedAngles (0 ms)
[ RUN      ] StacksFixture.TestUnbalancedCurlys
[       OK ] StacksFixture.TestUnbalancedCurlys (0 ms)
[ RUN      ] StacksFixture.TestUnalancedSquares
[       OK ] StacksFixture.TestUnalancedSquares (0 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 8 tests from StacksFixture (1 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 8 tests.

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

### Turning in and Grading your code

Go back to LazyGrader and login again, if needed. Press the _Build_ button next to
**EX04-Stacks** for this course. This will send a command to Jenkins to download your code
from GitHub and test it. If all goes well and all the tests pass, the ball next to the _Build_
will turn blue. If some of the tests don't pass the ball will be yellow. If the ball is grey,
that means you have not run the tests before and your project is not ready for grading.

Once the Jenkins status is blue or yellow, press the _Grade_ button for **EX04-Stacks**.
This will read the results from Jenkins and send your grade to Canvas. Once the notification in 
LazyGrader says the grade has been posted, you should see your grade on Canvas.

That's it, once you've submitted your grade, you are done. I will add points later, after I 
inspect your code. For example, most projects will be out of a total of 25 points, but after 
pressing the _Grade_ button, Canvas will show 20 points. I will add up to 5 points after I have
looked at your code and am conviced it is original.