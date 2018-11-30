# ProgrammingOneHour_2018

Programming-One-Hour Activity By Tongji Google Camp, Fall Semester, 2018



## Part One: Fibonacci with Sliding Array

### 1. Reversion Version

$F(1)=1\\F(2)=1\\F(3)=F(1)+F(2)=2\\F(4)=F(2)+F(3)=F(2)+F(1)+F(2)=3\\F(5)=F(4)+F(3)=F(3)+F(2)+F(2)+F(1)=F(2)+F(1)+F(2)+F(2)+F(1)=5\\...$

![image](./images/Fib(5).png)

**Analysis:**

Time complexity: $O(1.618^n)$

Space complexity: $O(n)$

**Problem: Duplicate calculation**

### 2. Sliding Array Version

$F(1)=1\\F(2)=1\\F(3)=F(2)+F(1)=2\\F(4)=F(3)+F(2)=3\\F(5)=F(4)+F(3)=5\\...$

| F(n) | Cell 0 | Cell 1 | Cell 2 |
| ---- | ------ | ------ | ------ |
| F(1) | [1]    | -      | -      |
| F(2) | 1      | [1]    | -      |
| F(3) | 1      | 1      | [2]    |
| F(4) | [3]    | 1      | 2      |
| F(5) | 3      | [5]    | 2      |

**Analysis:**

Time complexity: $O(n)$

Space complexity: $O(1)$



## Part Two:  Doubled Array

### 1. Two facts

Fact 1: Allocated memory block cannot be modified dynamically

Fact 2: Sometimes we need to change the size of array we have allocated to fit elements in different numbers

**Conclusion:** Resize the array

### 2. Analysis

**Key Point: Tradeoff between space utilization and operation time**

#### 2.1 Space utilization

Scenario 1: 1 element in an array of 10000 elements long

Scenario 2: 9000 element in an array of 10000 elements long

#### 2.2 Operation time

To expand an array from 10 elements long to 10000 elements long

Scenario 1: increase the size of the array by 1 every time

result 1: 9900 times, 10000 elements long

Scenario 2: increase the size of the array by doubling it

result 1: 10 times, 10240 elements long

### 3. One more thing

C library function - realloc()

#### Description

The C library function **void \*realloc(void *ptr, size_t size)** attempts to resize the memory block pointed to by **ptr** that was previously allocated with a call to **malloc** or **calloc**.

#### Declaraion

Following is the declaration for realloc() function.

```c
void *realloc(void *ptr, size_t size)
```

#### Parameters

- **ptr** − This is the pointer to a memory block previously allocated with malloc, calloc or realloc to be reallocated. If this is NULL, a new block is allocated and a pointer to it is returned by the function.
- **size** − This is the new size for the memory block, in bytes. If it is 0 and ptr points to an existing block of memory, the memory block pointed by ptr is deallocated and a NULL pointer is returned.

#### Return value

This function returns a pointer to the newly allocated memory, or NULL if the request fails.

