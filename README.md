# Subtraction of 'struct timeval'

Once upon a time I needed a result of subtraction 'struct timeval' values.
I've found this variant
https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html.
But soon understood that it doesn't work properly. Then I've found this
explanation:
https://stackoverflow.com/a/15849714. 
But it doesn't too.
After this I've wrote it myself and test code in addition. Here it is.
It is also worked for 'struct timespec' with minor changes.


### Prerequisites

I prefer to use NetBeans IDE 8.2 with C/C++ toolchain under Ubuntu 18.04.1 LTS.


### Running

1. Choose function variant to test by commenting others at main.c.

2. Press "Run Project" button.


