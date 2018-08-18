# Buffer Overflow Demonstration

# Usage
1. Run 'Project.exe' in a command line with a single password argument.
2. The correct password is "bestpass" however a sufficiently long password input will cause an overflow.  
  >Project.exe hackthepassword  
3. Demo will output both memory address values before and after the vulnerable "strcpy" function is called.
  