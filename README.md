## What was the problem you were solving in the projects for this course?
ABCU is looking for software that will help their computer science advisors access course information for students. I had to write software that would read information
in from a CSV, store it into a data structure. From that point it needed to be able to be searched, and return Course number, Course name, and any prerequisites for the course.

## How did you approach the problem? Consider why data structures are important to understand.
I approached this problem by first identifying how large this piece of software was going to be. Once I realized it was only 8 items, I had decided to use a vector data structure.
A vector may be the worse one I could have chosen, while equal to Hash tables and binary search trees in worse case run-time scenarios the others performed better on average nad optimal
run-time scenarios. I still chose vector becuase the size is so small, and storing classes will never reach into the thousands or millions, and a vector is simple that when changes need
to be made, wether it is removing a course, or editing a prerequisite, it is easy enough for anyone to do.

## How did you overcome any roadblocks you encountered while going through the activities or project?
I had encounted a few roadblocks, one particular being reading in from a csv. I am not fluent with C++ so it had taken be some outside research on how to perform this task.
This is how I solved all of my roadbloacks, by reading documentation, reading people who had similar issues on stack overflow.

## How has your work on this project expanded your approach to designing software and developing programs?
My work in this project has really highlighted the need for consistent testing, and finding edge-case scenarios where your program will break. Designing must be kept with the end-user in mind.

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
This project forced my to stay consistant with my comments, as sometimes I would lose my train of thought and forget which variable was handing which item. I think this would
have been easier if this project was not about Classes, we were told earlier to refer to them as Courses. There are many things in C++ I am still inexperienced with and I am sure
with time this program could be reduced down even further.
