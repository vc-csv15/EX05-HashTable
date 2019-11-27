## Exercise: HashTable (25 Points)

The objective of this project is to learn about collision resolution for
hash tables. You will choose to implement either linear probing, quadratic
probing or double hashing.

### Getting Started

The first thing you will need to do is accept the invitation to this 
assignment from GitHub Classroom. You can click 
[here](https://classroom.github.com/a/8bUbXXr0) to accept the 
invitation, and get started.

Be sure that you accept the invitation first and use the URL to your new project when you clone it in CLion. After copying
the URL into the clipboard, in CLion click **VCS -> Checkout from Version Control -> Git**. Paste the URL into the **URL** box of the _Clone Repository_ dialog box and press **Clone**.


### Requirements of this project

This project is based on the unordered_map data structure, a hash table, as defined in C++-11. To see more details,
take a look at the documentation on the [CPP Reference](https://en.cppreference.com/w/cpp/container/unordered_map) 
website or the [C++ official](http://www.cplusplus.com/reference/unordered_map/unordered_map/) site. 

You will update the `_find` method of the generic (or templated) `unordered` class. The comment
`// Resolve collisions here` indicates where you need to make your changes. At that point you can
choose your collision resolution strategy. However, each strategy will earn you a different amount
of points. If you choose linear probing, the easiest, you will get 22 points for the project. If
you implement quadratic probing you will get 23 points, and double hashing, as described in the book
and elsewhere, will get you the full 25 points.

You should only need to make the change in this one function (aside from perhaps adding a hash function
for double hashing).

When you start the project, the code looks like this in `unordered_map.h`:

```cpp
size_t _find(const Key &key) const {
    size_t hash = hash_function()(key);
    size_t bucket = hash % _capacity;
    for (int i = 0;
           _buckets + bucket       != end()._current  &&
           _buckets[bucket]        != nullptr &&
           _buckets[bucket]->first != key; i++) {
        // Resolve collisions here
    }
    return bucket;
}
```

Replace `// Resolve collisions here` with your solution.

### Writing the code for this Project

There is only one requirement for creating the code for this project correctly. 
Fill in all required code for the class `unordered_map` in the namespace `edu::vcccd::vc::csv13` with
the given interface from the reference websites. 

#### All files must have the header comment

Be sure to add the proper header comment to each `.cc` and `.h` file you add to this project.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `HashTable | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It could look something like this:

```bash
/tmp/tmp.s3fwukqGrW/cmake-build-debug/../bin/HashTable
123
456
908
1234
size: 4
bucket count: 11
load factor: 0.363636

Process finished with exit code 0
```

But in this case, it could be whatever you want to make sure you code works.

Once your code runs and behaves the way you want, Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `HashTable Tests | Debug` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
/tmp/tmp.s3fwukqGrW/cmake-build-debug/../bin/HashTable_GTest
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from HashTableFixture
[ RUN      ] HashTableFixture.TestEmptyHashTable
[       OK ] HashTableFixture.TestEmptyHashTable (0 ms)
[ RUN      ] HashTableFixture.TestBasicHashTable
[       OK ] HashTableFixture.TestBasicHashTable (0 ms)
[ RUN      ] HashTableFixture.TestOneRehash
[       OK ] HashTableFixture.TestOneRehash (0 ms)
[ RUN      ] HashTableFixture.TestMultipleRehash
[       OK ] HashTableFixture.TestMultipleRehash (0 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 4 tests from HashTableFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 4 tests.

Process finished with exit code 0
```

You should also see your score for this assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `unordered_map.h`, and our changes/additions to `list.h`.
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
**EX05-HashTable** for this course. This will send a command to Jenkins to download your code
from GitHub and test it. If all goes well and all the tests pass, the ball next to the _Build_
will turn blue. If some of the tests don't pass the ball will be yellow. If the ball is grey,
that means you have not run the tests before and your project is not ready for grading.

Once the Jenkins status is blue or yellow, press the _Grade_ button for **EX05-HashTable**.
This will read the results from Jenkins and send your grade to Canvas. Once the notification in 
LazyGrader says the grade has been posted, you should see your grade on Canvas.

That's it, once you've submitted your grade, you are done. I will add points later, after I 
inspect your code. For example, most projects will be out of a total of 25 points, but after 
pressing the _Grade_ button, Canvas will show 20 points. I will add up to 5 points after I have
looked at your code and am conviced it is original.
