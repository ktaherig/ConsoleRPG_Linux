# Summary

This is a terminal-/console-oriented text-based RPG based on the "[C++ Game Development: Console RPG](https://www.youtube.com/playlist?list=PL6xSOsbVA1eZ4JHn9T43TXBodSW_9ny-k)" Youtube video series by [Suraj Sharma](https://www.youtube.com/channel/UC2i39AOpDSlO1Mrn1jQ8Xkg/playlists).

I did this codealong after having studied through [TheCherno's C++ course](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb), then reading and practicing through "[The C++ Primer Plus, 6th Ed](https://www.amazon.co.uk/dp/0321776402/)" by Stephen Prata, "[Programming Principles and Practice Using C++ (2nd Ed)]()" by Bjarne Stroustrup (who needs no introduction), a couple books by Scott Meyers, and "[C++17 STL Cookbook](https://www.amazon.co.uk/dp/178712049X/)" by Jacek Galowicz, in order to get some experience with the theory I'd learned from Stephen Prata's and Jacek Galowicz's books and TheCherno's video series in a way that can be used in practice via an actual project.

With Suraj's blessing, I have the task of keeping the Github code optimized for Linux, Code::Blocks, and other Unix-based systems.

That being said, this RPG is a codealong of Suraj's video series. The series is not a "course", in any real sense. Suraj doesn't explain what each line does in terms of functions, pointers, lambdas, classes and structs, enums, etc. Rather, he simply writes the game, and his "explanation" is really more along the lines of something like:

```
"Our hero needs to sheathe his sword, and he needs potions to defeat the wizard and fight the dragon, so this class-member variable is set to public."
```

I've tried to make sure to add comments wherever possible to show that I actually do understand the material in the scope (ha ha, get it: "scope") of C++ and what the language itself is capable of, rather than just starting out with Suraj's course having not read the books and simply copying along like a monkey.

### Notes

##### Accuracy By-Date

This project is accurate to the YouTube course playlist up until [video #60](https://www.youtube.com/watch?v=wZreCXR1y5k&index=63&list=PL6xSOsbVA1eY06RyJuIVWc6tP8hIDiId8). 

##### Notes on "using namespace std;"

I realize that implementing `using namespace std;` is widely considered to be bad practice, due to the fact that it can lead to serious name-clashing. The reason why I've used it here is because, exactly as Suraj says in the early part of the first video, "we're not going to be using any other namespaces", so I figured it was a good-enough reason, and so I used it in my code as well.

### Compiling and running

If you're on Windows, you may use Powershell (which is the stock terminal emulator provided my Microsoft), though it is recommendable to download and use either Cmder or GitBash (they're both excellent, so either one is perfectly acceptable). If you're on Linux or Mac OSX, then simply use whatever emulator you prefer.

Navigate to the game with
```
cd <download_destination>/Console_State_RPG/ (i.e., wherever you downloaded this project)
```
and compile the game for your particular OS.

###### On Windows

In the terminal emulator window, compile with:
```
g++ -o main main.cpp&main.exe
```
If you're viewing this project on Visual Studio, you can use Ctrl+F7 to build and compile. On Code::Blocks, use F9.

###### On Linux

To compile, simply use:
```
make
```
and then to run, type
```
./main
```

To clean up the compilation files, first, you'll need to make the `tidy.sh` file an executable by typing:
```
chmod +x tidy.sh
```
and then anytime from then on, run the command:
```
./tidy.sh
```
This will remove all the \*.o files, as well as the "main" executable.

###### On Mac

I haven't been able to figure out how to compile on a Mac. Judging from the [Stack Overflow question page](https://stackoverflow.com/questions/221185/how-to-compile-and-run-c-c-in-a-unix-console-mac-terminal) and [Apple's own developer docs](https://developer.apple.com/library/archive/documentation/Porting/Conceptual/PortingUnix/compiling/compiling.html), it seems as though you have to use:
```
gcc main.cpp -o main.out  
./main.out
```
although I'm not sure about this, as I refuse to ever touch a Mac. I'm sure you'll figure it out.

### Gameplay

It's a pretty simple, straight-forward text-based RPG. You make a character, and play accordingly.

### To-Do

As of now, the Unix rewrite gives me a great big long list of *_warning_* messages, though I've removed all the errors that come with rewriting MS Visual Studio code, and so the program does in-fact compile and run perfectly fine. I will fix the warning messages as soon as I can address them.

Suraj had these listed as TODO items, and I intend to write my own interpretations of them:

---

Fix Puzzle load
Create one puzzle
Work on travel
Create Combat system

- enemies random number

- turn dice, whos turn.

- if run (low chance), roll dice (costs turn) can do any time

- check stats for one enemy (costs turn) can do any time

- attack, take damage

- if player dead, run or enemies dead combat end

- if player dead, game over

- if enemies dead, reward player, back to menu

- if run, back to menu.

