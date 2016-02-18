# CIS22B_FinalProject
\ Final project for Group 4 in CIS22B

basic git tutorial: https://www.youtube.com/watch?v=XdhuWDdu-rk

Information about the project and how we distribute the workload will go here once we know more about the project.

We should require 2-3 approvals from group members before accepting pull requests to ensure we only add good code.

Project Specifications

Project— Part 1: Program Specifications
Serendipity Booksellers is a small bookstore located in a shopping mall. They have a
cashier station equipped with a personal computer. The manager wants you to develop a
point-of-sale (POS) software package that will make the computer function as a cash
register and keep an inventory file. The inventory file will be a database of all the books
in the bookstore. In general, the software is to perform the following tasks:
• Calculate the total of a sale, including sales tax
• When a book is purchased, subtract it from the inventory file
• Add, change, delete, and look up books in the inventory file
• Display various sales reports
You will build on the project by implementing newly learned features from each
chapter. In the end, you will have designed and written a fully functional software
package that incorporates most of the topics covered in the text.

The Modules
The program will be organized into the following three modules:
• Cashier module
• Inventory Database module
• Report module
When the program runs, a menu will be displayed on the screen, which allows the user
to activate any of the modules. A discussion of each module follows:

The Cashier Module
The Cashier module allows the computer to act as a cash register. The user enters
information for the books being purchased and the program calculates the sales tax and
the total price. In addition, the books being purchased are automatically subtracted from
the Inventory Database.

The Inventory Database Module
The Inventory Database will be a file containing a list of all the books in Serendipity’s
inventory. The following information for each book will be stored in the file:
Chapter 1 Introduction to Computers and Programming
©2012 Pearson Education, Inc. Upper Saddle River, NJ. All Rights Reserved.
Field Description
ISBN              This is the International Standard Book Number. It is a unique number assigned to each book by the publisher.
Title             The title of the book.
Author            The book’s author.
Publisher         The company that publishes the book.
Date Added        The date the book was added to the inventory.
Quantity-On-Hand  The number of copies of the book in inventory.
Wholesale Cost    The price paid by Serendipity for each copy of the book.
Retail Price      The price Serendipity is charging for each copy of the book.

The Inventory Database module will allow the user to look up information on any book
in the file, add new books to the file, delete books, and change any information in the
database.

The Report Module
The Report module will analyze the information in the Inventory Database to produce
any of the following reports:
• Inventory List. A list of information on all books in the inventory.
• Inventory Wholesale Value. A list of the wholesale value of all books in the
inventory and the total wholesale value of the inventory.
• Inventory Retail Value. A list of the retail value of all books in the inventory
and the total retail value of the inventory.
• List by Quantity. A list of all books in the inventory sorted by quantity on hand.
The books with the greatest quantity on hand will be listed first.
• List by Cost. A list of all books in the inventory, sorted by wholesale cost. The
books with the greatest wholesale cost will be listed first.
• List by Age. A list of all books in the inventory, sorted by purchase date. The
books that have been in the inventory longest will be listed first. 
