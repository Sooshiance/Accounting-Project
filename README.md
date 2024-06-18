# Search Engine

This is a `Search Engine` using C++.

## WebPage

This class has one method which is constructor method.

This method takes two arguments : 
- string
- integer

This string is used to create the URL based on the given contents.

The integer is used to numbered the current URL.

## InvertedIndex

In here, we have a private attribute named : `index`

This attribute's type is **unordered_map** which is a 
key-value pair that key is string type and value is 
a set of integers(as you know in `set` there is no repeated members)

In the <Public> section we have `addPage` and `search` methods. 

- **addPage** : takes two arguments : [pageID] and [token] and return nothing.

`token` is a string and store in a pointer and `pageID` will insert into this `token`.

- **search** : takes one argument and return a set of integers. This method will search through `tokens` and finds `index` the place of each `tokens` and returns its place.

## SearchEngine

- **Private**

In here, we will use the both of <a link=InvertedIndex>InvertedIndex</a> and <a link=WebPage>WebPage</a> classes.
First we will create an object with `WebPage` template that has **vector** type and an object from `InvertedIndex` also a vector named string that has template of string.

Now the tokenize function is a little bit challenging :
This function will take one reference named `content` and returns a **vector** with string **template**. This function effectively splits the input string into words based on spaces and stores each word as a separate string in a vector. It's a common way to parse sentences into words or commands into arguments.

- **Public**

In here we have three functions : 

- **addPage** : 
This function takes a WebPage object as an argument and adds it to a `vector` of WebPage objects called pages. It then calculates the ID for the new page (which is the index of the last element in the vector) and calls another function **addPage** on an index object, passing the new page ID and the `tokenized` content of the page.

- **search**
The search function takes a search query string, adds it to a history `vector` to keep track of all searches, and then uses an `index` object to search for the query. If no results are found, it prints a message. Otherwise, it prints the **URLs** of the pages found.

- **showHistory**
The showHistory function simply iterates over the history `vector` and prints each stored search query.

# main

In here, we will add a sample web page to our search engine and than we will search for each one of them.
