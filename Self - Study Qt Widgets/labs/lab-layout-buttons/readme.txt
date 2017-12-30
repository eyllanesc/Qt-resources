Let's play with layout stretching and the size policy of widgets.

We will arrange three buttons horizontally and then change their stretching
and at the end their size policy.


Starting Point
==============

Create a window, which has three buttons ("One", "Two", "Three") layed out horizointally

Note: If you want to have a grup title use QGroupBox

Exercise 1: Stretch 2-1-1
=========================

- Change the stretch of the buttons to
  - one  : 2
  - two  : 1
  - three : 1


Exercise 2: Find this stretch
=============================

- From the picture try to find the correct stretch for the buttons.

Exercise 3: Stretch at the end
==============================

- remove all stretches
- add a stretch of 1 at the end of the layout


Exercise 4: Stretch the middle
==============================

- remove all stretches
- add a stretch of 1 between the buttons

Exercise 5: Make all buttons vertical expanding
===============================================

- remove all stretches
- find all buttons: hint use QObject::findChildren
- change each buttons size policy to expand vertically
