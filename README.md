Creator 2.0
===========

*JJ van Zon, 2027-06-08*

Experimental __model-driven__ programming language written in `2007` using `Visual C++ 6.0`.

Started off with high hopes, but left as: an interesting quirky experiment, an obscure project out of a series called "Not for Lack of Trying". `Creator` is the name, because well it was meant for creating things with. And with it I tested a few interesting concept I otherwise would not have.

__Contents__

- [Syntax](#syntax)
- [Code Lives Here](#code-lives-here)
- [Engine / Interpreted Language](#engine--interpreted-language)
- [Model-Driven](#model-driven)
- [Rewritten in Itself](#rewritten-in-itself)
- [Parser](#parser)
- [C++ Fallback](#c-fallback)
- [Tree Control](#tree-control)
- [Data Structures Base Library](#data-structures-base-library)
- [Prototype Apps](#prototype-apps)
- [C++](#c)
- [Short and Long Spaces](#short-and-long-spaces)
- [Memory Leaks](#memory-leaks)
- [Indentation Style](#indentation-style)
- [Version Folders](#version-folders)
- [Fair Use](#fair-use)


Syntax
------

```
//  Classes

Class  Product
Class  Order
Class  Order Item

//  Attributes

Product  -->  Name  (  String  )
Product  -->  Price  (  Double  )
Product  -->  Item Number  (  String  )

Order  -->  Order Number  (  Integer  )
Order  -->  Customer Name  (  String  )

//  Relations

Order Item  -->  Quantity  (  Integer  )
Order  (  Order  )    1  -->  n    Order Item  (  Order Items  )
Order Item  (  Order Items  )    n --> 1    Product  (  Product  )
```

Code Lives Here
---------------

The main code is a bit burried in the folders, so here are some links to the main code:

- [C++ Code](./Code/Creator/XXXX-XX-XX%20XX/C++%20Code/)
- [Creator Code](./Code/Creator/XXXX-XX-XX%20XX/Creator%20Code/)


Engine / Interpreted Language
-----------------------------

This is an __interpreted__ / __engine__ variant, because  keeping a __code generator__ variant stable under various options was sort of a bad experience.


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

Somr propriety data structures were used to keep lists and trees alive. They were mostly based on `CArray<T>`.


Prototype Apps
--------------

Several prototype apps were built. The Sound app was functional, though maybe not too user friendly. Here's a list of models in the repo:

- Sound Objects
- Math Objects
- Controls Model
- The Creator Model itself


C++
---

This is one of the few projects I ever did in `C++`. I chose it for speed which I hoped, I would get of the box. But apparently it's really easy to make a computer run slow. So it didn't actually render much performance gain. Oh well. All in a day's hobbyin'.


Short and Long Spaces
---------------------

I wanted to allow spaces inside  __names__ in the code, which most languages intentionally avoid (for good reason). The idea was that with spaces in identifiers, they could immediately stand in for user-friendly names used in the user interface.

To be able to keep the syntax simple and easy to parse, I came up with this: You'd need to separate tokes by double spaces, while single spaces could exist in names. The double spaces then came to sort of stand in for a normal space, while the single space was a sort of "short space" you can use in your identifiers.

In the code editor, pressing the space bar even inserted *two* spaces while `Ctrl-Space` would insert a single space: a __"short space"__. The *font* was chosen so that the wider spacing wouldn't distract much.


Memory Leaks
------------

About 3/4 into the project I realize that some panel in Visual C++ showed massive amounts of memory leak detections. I didn't think the IDE would warn me about these, but it turns out it had been trying to all along.

I dove into a pattern of ownership of pointers and creation and destruction of objects being fully symmetrical: e.g. create in constructor, then destroy in destructor; create when adding to a list, destroy when removing from the list.

But alas, I never could figure out why there was still a waterfall of memory leak warnings, even after checking all the code again 3 times. I guess I never was that good at C++ after all.

I have my suspicion now what I did wrong, but the project is just too long ago to bother.

The app worked though. That wasn't the issue.


Indentation Style
-----------------

....


Version Folders
---------------

...

Fair Use
--------

Third party files included, deemed fair-use are: generated project template files from Visual C++ 6.0, and a handful of low-res sound samples.