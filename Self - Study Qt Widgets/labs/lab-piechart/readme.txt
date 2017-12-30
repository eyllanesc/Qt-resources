==============
Lab: Pie Chart Widget
==============

The task is to create a pie chart widget. The widget shall paint a set of date, in this case the country population in millions of citizens. Optional the widgets displays a legend of the right side.

Step
===
Complete the API to set/get the value and make yourself familar with the code.

Step
===
Now it's time to implement size hint and minimum size hint with a reasonable value. A size of 80x80 seems to be appropriate. 
It's also good to paint already a rectangle inside the widget to ensure painting is working.

Step
===

To draw the pie's we have to draw one value after another and move the angle offset by the pie we have just drawn. For each pie we need to chose a new color (see colorAt(pos) method).

* Make sure you painting is also working when resizing the widget
* Use the geometrical helper classes, where possible. They are your friends.

Optional:
======

Instead of a plain color you can use a radial gradient to colorize the
pie-elements. The center should be on the pie-center, the radius
the width of the pie and the focal point on the top-left of the pie.

Optional:
======

For the legend we need to extend the size hints to the double width. Additional we need to define a right rectangle, which is srunk by 10 pixel. Inside this rectangle we will need to draw an color-indicator and a label for the country.
The size of the color indicator is the size of the character 'x'. The space between indicator and label is the width of 'x'. The space between two lines of indicator is the hight of 'x'. Use the QFontMetrics class to calculate the size.


