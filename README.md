Creator 2.0
===========

*JJ van Zon, 2027-06-08*

Experimental __model-driven__ programming language written in `2007` with `Visual C++ 6.0`.

Started off with high hopes, but left: an interesting quirky experiment, an obscure project out of a series I'd like to call "Not for Lack of Trying". `Creator` is the name, because well it was meant for creating stuff. With it I tested a few interesting concept I otherwise would have not.

__Contents__

- [Syntax](#syntax)
- [Code Lives Here](#code-lives-here)
- [Model-Driven](#model-driven)
- [Interpreted Language](#interpreted-language)
- [Rewritten in Itself](#rewritten-in-itself)
- [Tree Control](#tree-control)
- [Prototype Apps](#prototype-apps)
- [Short and Long Spaces](#short-and-long-spaces)
- [C++ Base](#c-base)
- [C++ Methods](#c-methods)
- [Parser](#parser)
- [Data Structures Base Library](#data-structures-base-library)
- [Memory Leaks](#memory-leaks)
- [Indentation Style](#indentation-style)
- [Version Folders](#version-folders)
- [Interceptors](#interceptors)
- [Fair Use Disclaimer](#fair-use-disclaimer)


Syntax
------

This is an example of a model that would form the base of your program:

```
Name  Shop

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

Order Item  -->  Quantity  (  Integer  )

//  Relations

Order  (  Order  )  1  -->  n  Order Item  (  Order Items  )
Order Item  (  Order Items  )  n  -->  1  Product  (  Product  )
```

Code Lives Here
---------------

The main code is a bit burried in the folders, so here are some links to the it:

- [C++ Code](./Code/Creator/XXXX-XX-XX%20XX/C++%20Code/)
- [Creator Code](./Code/Creator/XXXX-XX-XX%20XX/Creator%20Code/)


Model-Driven
------------

You use the language by defining `classes` and their `relationships` as a structure of `1 -> 1` , `1 -> n` or `n -> n` relationships. Classes can get `attributes` too.

The idea is that everything else is hung up on this structure. Sort of like a Christmas tree: logic, methods, auto-generated things and all that stuff. 


Interpreted Language
--------------------

This is an __interpreted__ / __engine__ variant. There also used to be a __code generator__ variant, but it was sort of a bad experience. It was hard to keep stable, when you could enable/disable options, that had dependencies with other options. Generated code would then not compile, thus the choice to have a more "live" system this time.


Rewritten in Itself
-------------------

The engine is reprogrammed in itself several times going from pure `C++` to dynamic generic object definitions and parsed text code.

It was rewritten about 7 times with different layers of genericity until arriving in a layer where a text file with `Creator` code is used by the engine to instantiate `Creator` objects. Fully loose from the `C++` base (well, mostly).

Thea idea was that I define the absolute bare essentials in `C++`, while the more high-level features are all described using the programming language itself.


Tree Control
------------

The UI of a running `Creator` program is an original ASCII-based tree control.
The whole program is used within that tree control, where you can create objects and run actions (methods) that are defined in the `.cre` files with `Creator` code.

The ideas was to have generated user interfaces be a thing so you have a UI out of the box. It wouldn't be just  limited to this Tree view, but this was the only UI element that made it into the prototype.


Prototype Apps
--------------

Several prototype apps were built. The __Sound__ app is functional, though maybe not too user friendly. Here's a list of models in the repo:

- Sound Objects
- Math Objects
- Controls Model
- The Creator Model itself


Short and Long Spaces
---------------------

I wanted to allow spaces inside  __names__ in the code, which most languages intentionally avoid (for good reason). The idea was that with spaces in identifiers, they could immediately stand in for user-friendly names used in the user interface.

This meant not only could you use spaces. An name could in fact contain *any* character, even ones that would conflict with the language. An identifier could even be `>` or `+`.

To be able to keep the syntax simple and easy to parse, I came up with this: You'd need to separate tokes by double spaces, while a name could contain single space characters. 

In the code editor, the double spaces then came to sort of stand in for a normal space, while the single space was a sort of "short space" you can use in your identifiers. 

Pressing the space bar even inserted *two* spaces, because having to remember to type too spaces yourself becomes a real pain. `Ctrl-Space` would insert a single space: a __"short space"__. The *font* was chosen so that the wider spacing wouldn't distract too much.


C++ Base
--------

This is one of the few projects I ever did in `C++`. I chose `C++` for speed which I hoped, I would get of the box. But apparently it's really easy to make a computer run slow. So it didn't actually render much performance gain. Oh well. All in a day's hobbyin'.


C++ Methods
-----------

The data and a few behaviors are defined in a custom syntax in `.cre` files. 

But __methods__ are written with `C++` code, though embedded in the `.cre` files. Those methods are compiled into `DLLs` and called by the engine running a `Creator` app.

The methods access the model in a bit of a verbose syntax, but a next step could have been to use the model in a more friendly notation. The Christmas tree concept comes to mind here again. This time `Creator` code decorated with `C++`, or the other way around; you choose.

Methods are usually hooked up to the model objects and by default become actions the user can perform from the user interface.


Parser
------

The text parser for the `Creator` code is written in `C++` itself, so there goes my claim everything is written in `Creator` code itself. But it converts the code to generic definition objects that can run inside the `Creator` engine.


Data Structures Base Library
----------------------------

Some propriety data structures were used to keep lists and trees alive. They were based on `CArray<T>` doing most of the work for me.


Memory Leaks
------------

About 75% into the project, I realize that some panel in `Visual C++` showed massive amounts of memory leaks. I didn't think the IDE would warn me about these, but it turns out it had been trying.

I dove into a pattern of ownership of pointers and creation and destruction of objects being fully symmetrical: e.g. create in constructor, then destroy in destructor; create when adding to a list, destroy when removing from the list.

But alas, I never could figure out why there was still a waterfall of memory leak warnings, even after checking all the code again 3 times. I guess I never was that good at `C++`.

I have my suspicion now what I did wrong, but the project is just too long ago to bother.

The app worked though. So there is that.


Indentation Style
-----------------

I had an uncommon indentation style, where a *title comment* would in my view be more important than the code itself. So after each title comment, I'd indent. This repo's code is full of that, so I thought I'd just mention that quirk, for the sake of mentioning quirks.

```
//  General

    Name  My App

//  Classes

    //  Main Classes

        Class  Workspace
        Class  Document

//  Attributes

    //  Document

        Document  -->  Name  (  String  )
        Document  -->  Author  (  String  )
        //  ...
```

Version Folders
---------------

I had no version control system back then, so I used *version folders* for code freezes. You'll find them sprinkled over the repository, so I thought I'd just mention it.

```
Code
|
|-- Creator
    |
    |-- 2007-04-01 00  Experimental Generic Creator
    |-- 2007-04-22 00  2.00a
    |-- 2007-05-30 00  2.01a
    |-- 2007-07-15 00  2.02a
    |-- XXXX-XX-XX XX
```

Each of those sub-folders represents a version. The last one with all the X's represent the latest, development version.

I meant to collapse these 'time-line' folders into `git` history as a succession of commits, but that would be some work to get right and I just can't be bothered. Too old.


Interceptors
------------

It gets a bit deep here.

The idea was to take this langauge further, until the project stranded.

Methods can be hooked into the model, responding to *data changes* or actions *reading* the data. These worked like *interceptors*. I only supported `Get` and `Set` interceptor, but the idea was to once support `Add`  `Remove`  and  `New` interceptors too.

Here's how that could look: an initial value is assigned to the `Name` of a new `Document`:

```
Method  Extend  App  .  Documents  .  Add
    aThis  ->  ItemAttributes  (  )  ->  Item  (  "Name"  )  ->  Value  (  "Untitled"  )  ;
End  Method
```

Yes, did I mentioned, the way to access the model is very verbose? 

This method body is actual C++ code accessing the model engine under the hood. With a little more work, this could have been simplified to:

```
Method  Extend  App  .  Documents  .  Add
    Document  .  Name  =  "Untitled"
End  Method
```

Which looks a little more like the language is doing its own work.

The idea was this would enable __aspect oriented programming__ where an *aspect* or *concept* was programmed once, and then applied to multiple applications, reused without any added programming. Well, that was the hope anyway. To have functionalities programmed as reusable concepts. The code generator version did it, but, well, it crashed a lot.


Fair Use Disclaimer
-------------------

There are some third party files included, deemed fair-use. These are: generated project template files from `Visual C++ 6.0`, and a handful of low-res sound samples.