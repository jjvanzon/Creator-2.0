Creator 2.0
===========

*JJ van Zon, 2027-06-08*

Experimental __model-driven__ programming language written in `2007` using `Visual C++ 6.0`.

Started off with high hopes, but left as: an interesting quirky experiment, an obscure project out of a series called "Not for Lack of Trying". Called `Creator` because well it was meant for creating things with. With this I tested a few interesting concept I otherwise would nt have.

__Contents__

- [Syntax](#syntax)
- [Code Lives Here](#code-lives-here)
- [Model-Driven](#model-driven)
- [Rewritten in Itself](#rewritten-in-itself)
- [Parser](#parser)
- [C++ Fallback](#c-fallback)
- [Tree Control](#tree-control)
- [Data Structures Base Library](#data-structures-base-library)
- [Prototype Apps](#prototype-apps)
- [C++](#c)
- [Small and Large Spaces](#small-and-large-spaces)
- [Memory Leaks](#memory-leaks)
- [Indentation Style](#indentation-style)
- [Version Folders](#version-folders)
- [Fair Use](#fair-use)



Syntax
------

...


Code Lives Here
---------------

The main code is a bit burried in the folders, so here are some links to the main code:

- [C++ Code](./Code/Creator/XXXX-XX-XX%20XX/C++%20Code/)
- [Creator Code](./Code/Creator/XXXX-XX-XX%20XX/Creator%20Code/)

Interpreted

-----------

This is an __interpreted__ / __engine__ variant, because of a bad experience keeping a __code generator__ variant stable under various options.


Model-Driven
------------

You use the language by defining `classes` and their `relationships` as a structure of `1 -> 1` and `1 -> n` relationships. Classes can also get `attributes` defined with a similar syntax.

The idea is that everything else is hung up on this structure. Sort of like a Christmas tree: logic, methods, auto-generated things and all that good stuff. 


Rewritten in Itself
-------------------

The engine is reprogrammed in itself several times going from pure `C++` to dynamic generic object definitions and parsed text code.

It was rewritten about 7 times with different layers of genericity until arriving in a layer where a text file with `Creator` code is used by the engine to instantiate `Creator` objects. Fully loose from the C++ base (well, mostly).

Thea idea was that I define the absolute bare essentials in C++, while the more high-level features are all described using the programming language itself.


Parser
------

The text parser for the Creator code is written in C++ itself though, so there goes my claim everything is written in Creator code itself. But it converts the code to generic definition objects that can sort of run in the Creator engine.


C++ Fallback
------------

The data and a few default behaviors are defined in a custom syntax in `.cre` files. But __methods__ are written with `C++` code, though embedded in the `.cre` files. Those methods are compiled into DLL's and called from the running `Creator` program.

The methods access the model in a bit of a verbose syntax, but a next step could have easily been to allow use of the model in a more friendly notation embedded right into the C++ code. The Christmas tree concept comes to mind here again.

Tree Control
------------

The UI of a running `Creator` program is an original ASCII-based tree control.
The whole program is used within that tree control, where you can create objects and run actions (methods) that are defined in the `.cre` files with `Creator` code.


Data Structures Base Library
----------------------------

...


Prototype Apps
--------------

- Sound Objects
- Math Objects
- Controls Model



C++
---

One of the few projects I did in `C++`. I chose it for speed, which I hoped I would get of the box. But apparently it's so easy to make a computer run slow, that it didn't actually render much performance gain. Oh well. All in a day's hobbyin' then.


Small and Large Spaces
----------------------

I wanted to allow spaces inside  __names__ in the code, which most languages intentionally avoid (for good reason). To be able to keep the syntax simple and easy to parse, I came up with this: You'd need to separate tokes by double spaces, while single spaces could exist in names. The double spaces then came to sort of stand in for a normal space, while the single space was a sort of "short space" you can use in the names in your code.

The idea was that identifiers could immediately stand in for user-friendly names used in (auto-generated) user interfaces.


Memory Leaks
------------

...

Indentation Style
-----------------

....

Version Folders
---------------

...

Fair Use
--------

Third party files included, deemed fair-use are: generated project template files from Visual C++ 6.0, and a few low-res sound samples.