==============================
Color Dialog: Connect A Button
==============================

Create an application which allows to display/select a color.
Read through the existing code template, first. This time we
create a widget by specializing QWidget.
Our own color selection dialog is already laying out the UI elements.
Your job will be to implement the actual application logic using Signals and Slots.

Step 1: Implement the slot: Ask the user for a color
====================================================

 - Declare the method in a "private slots" section.
 - Use QColorDialog::dialog() to fetch the color name.
 - Override the window background color of the label using
   the color choosen by the user.

Step 2: Connect signals and slots
=================================
 - Connect the button's pressed() signal with your slot.
