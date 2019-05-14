# EX-5
# cpp - Projects
## Iterators

### Eliashiv Deri 305368433

### Netanel Ben-Isahar - 204478150

### Yarden Gaon - 312469174

### Project Subject:
### Iterators!
### General explanation of the project:
![Smart algorithm](http://blog.filmdiy.co.il/images/digital-library/blog/buffer-to-stack.gif)
##### The project deals with structures that can be run on even though they do not take up memory space.  
##### We will implement five such structures.
### range -
##### represents a range of integers, for example: range (x,y) --> where integers are from x to y , which does not y.    
#### For example range (1,5)  returns {1,2,3,4}

### chain -
##### represents a concatenation of two container-like shapes
#### For example: chain (range (1,4), range (5,9)) --> {1,2,3,4,5,6,7,8}
##### The expressions are true for both strings and string strings
#### For example: chain (range ('a','d'),string ("hello")) returns --> { a, b, c, h, e, l, l, o }

### zip - 
##### parallel connection of two container-like
#### For example the expression zip (range (1,6), string ("hello")) 
##### Represents a series of five arranged pairs:
#### returns --> {{1,h},{2,e}, {3,l}, {4,l}, 5,o}}

### product - 
##### represents a cartesian product of two container-like.
##### Not necessarily the same length.
#### For example:
#### product(range(1,4),string("helo"))
##### Represents 12 regular pairs:
#### returns --> {{1,h},{1,e},{1,l},{1,o},{2,h},{2,e},{2,l},{2,o},{3,h},{3,e},{3,l},{3,o}}

### powerset - 
##### represents all sub-groups of container-like
#### for example
#### powerset (string ("abc"))
##### Represents 8 sub-groups:
#### returns --> { {},{a},{b},{a, b},{c},{a,c},{b,c},{a,b,c}}

![Smart algorithm](https://3.bp.blogspot.com/-THzNQ7yDkpE/XFCmkGvYeYI/AAAAAAAADuE/ycT09f23p8UzjfyBflsTvsdWoQ8KafUcgCLcBGAs/s640/GIF1.gif)



 


