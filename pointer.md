# ADVANCED POINTER NOTES 

> this notes is realted to session -(https://www.youtube.com/watch?v=YLKOa1YAaxk)
## TOPICS
1. Basic pointers 
1. Poniter airthmatic
1. Pointers to 1D array
1. Runtime operator & Complie time operator
### Basic pointers
---
```C
int d = 10 ;
int *p; // initialisation of pointer
p = &d; // assigning the value to the pointer 
```
``` 
*p --- value at p - 10
p -- value of p  -- 100 
&d -- address of d -- 100
d -- value of d -- 10 
```
> size of pointer is always same.

### Poniter airthmatic
---
1. Size of data type of pointer is known as **SCALE FACTOR**.
2. Scale factor defines num of bytes read/written while deferencing(*p -- value at ) the pointer. 
```
- ptr + n  = ptr +  n * scale factor of ptr --> n locations ahead from current location 
- ptr - n  = ptr -  n * scale factor of ptr --> n locations behind from current location 
- ptr1 - ptr2 = ptr1(1016) - ptr2(1000) / scale factor of ptr(suppose double-- 8) = 2 - no of  locations in between
```
### Pointers to 1D array
---
* 1D array is :
1. Collection of similar elements
1. Consecutive memory location 
1. Pointer to an array is pointer to 0th Element to the array.
> `x[y] = *(x + y)`
```
       ptr --->  arr [ 10   ,   20   ,   30   ,   30  ]
addr-> 100             100      104     108       112    
- ptr + 1 = 104
- ptr - 2 = 92 (Ram is big so memory locations are availble)
```
```
- suppose
int *ptr1 = &arr[3] , *ptr2 = arr;
- so ptr1 - ptr2 = 112 - 100 = 12 / 4(scale factor) = 3
```
> arr and &arr[0] are same.
- arr + 1 = 104
- &arr[0] + 1 = 104
> arr and &arr are not same
- arr + 1 = 104 
- &arr + 1 = 116 (which is the size of whole array which means &arr is pointer to whole array)


