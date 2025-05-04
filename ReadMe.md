# student information:
- name: dotan danino
- id 328144951
- gmail: dotandanino@gmail.com
# project information:
- in this project i had implemnted class of matrix with real numbers and implemented the next operators:

| Operator              | Description                                      |
|-----------------------|--------------------------------------------------|
| `+`                   | Add two matrices                                 |
| `-`                   | Subtract one matrix from another                 |
| `-mat`                | Flip the sign of each element                    |
| `*`                   | Multiply two matrices                            |
| `scalar * mat`        | Multiply matrix by scalar (left)                 |
| `mat * scalar`        | Multiply matrix by scalar (right)                |
| `mat1 % mat2`         | Element-wise multiplication                      |
| `mat % int`           | Modulo of each element with an integer           |
| `/`                   | Divide all elements by scalar                    |
| `^`                   | Raise matrix to a power                          |
| `++` / `--`           | Add or subtract 1 to each element (pre/post)     |
| `~mat`                | Transpose the matrix                             |
| `mat[i][j]`           | Access or change a specific element              |
| `==`, `!=`            | Compare matrices by total sum of elements        |
| `<`, `>`, `<=`, `>=`  | Compare matrices by sum of elements              |
| `!mat`                | Calculate the determinant                        |
| `+=`, `-=`, `*=`,     | Do operation and update the matrix               |
| `/=`, `%=`            | (continued compound assignments)                 |
| `>>`                  | Print the matrix                                 |

- there is three ways to run this project you can run the main or the test or to run valgrind on both of then.
    #### run main
    - to run main first time you need to write the next commands:
        - make main
    after you build the files you can write: ./main
    #### run test
    - to run test you need to write the next commands:
        - make test
    #### run valgrind
    - to run valgrind you need to write the next commands:
        - make valgrind

# files namespace and classes
### Files:
    - Squaremat.hpp Squaremat.cpp
    - doctest.h
    - makefile
    - Main.cpp
    - test.cpp
    - row.hpp row.cpp
### Classes:
    - SquareMat
    - rows
    all the operators are declared in the hpp file
### Data Structures:
    - I build data structures to represent a row for the mat[i][j] operator
### NameSpace
    all the project is under the name space matrix