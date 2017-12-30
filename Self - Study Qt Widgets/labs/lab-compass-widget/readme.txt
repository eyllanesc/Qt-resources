The Compass Widget
==================

In this lab we will walk through the process of creating a custom widget.
The discrete compass widget allows the user to select one of the main
directions: North, West, South, East. The changes shall be propagated to the
outside world.

The compass panel is our test environment to test our compass class.
It currently contains QLabels as placeholders for your compass.

Note: The directions are represented by widgets of type QPushButton.

Task 1:
-------

* Think about a possible API to set the direction of the compass
* Think about how to notify other widgets about changes of direction
* Implement the compass widget
* Test the compass in the compass panel

Hint: For grouping buttons you can use the QButtonGroup (see setExclusive())
