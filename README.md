# al
Small pracical algorithm:
  lowest common ancestor,
  implement strtok in c++ styles,
  construct tree,
  check binary search tree,
  check balanced tree
Solar Radiation Coding Style Check

After 3 times of reviewing and having rewritten half of the existing code, we found that the programming style and organization used is not very clear and acceptable for future maintenance. It has some bad programming practices which need to be modified in the further work. It may need some tools to automatically for revision.

Bad Practices  

A. Non-technical
1. Lack of comments. Comments is necessary for future code reviewing and maintenance. Ex, what the inputs, outputs of a module are, and a brief description a a function.
2. Source code files hierarchy are not clear. Files for data, files for functions declaration, and files for implementation should be separated into different folders. Clear hierarchy will make it easy to update data and program, to debug, and review. 

B. Technical coding style
1.Hard coding. Input data should be separated away from program. The input of the model work flow needs to be a separated module, not a entangled part of program scattered.
2.I/O is entangled with computation logic. I/O is a very expensive process. So it’s usage must be minimized, and separated from common logic. 
3.Lack of memory management. Memory is limited is both host and device. Usage optimization, memory capability is important. Potential memory 
4.Variables and functions naming. Name should be consistent
5.Lack of management output.
6.Lack of modulation.
7.Function category is not clear. 
