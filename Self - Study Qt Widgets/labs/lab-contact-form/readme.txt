Lab Contact Form
================

Our designers came up with a genius contact form (see lab slide). As designers are they take their design very rigid. Use your best efforts to implement the specified contact form.

When you code user interfaces it's always good to split up the code into smaller chunks. Therefore it is recommended to use a createContactWidget and createDetailsWidget methods.

Note: You need to start from scratch with main.cpp and then a ContactForm widget.

Tasks
-----
* Implement the specified contact form
* Contact details shall be disabled by default
* Only when checking the "Show Details" checkbox, details shall be shown


Hints
-----
* The widgets used are QGroupBox, QLabel, QLineEdit, QTextEdit, QCheckBox
* Pay attention to text alignment of the "Picture" and the size
* To get a frame for a label your can use QLabel::setFrameStyle(...)

Optional Tasks
==============

Optional Task 1
---------------
* Use a QToolButton for the Picture element.
* When the button is clicked launch a file dialog (See QFileDialog).

The returned file can be loaded into a QPixmap. The QPixmap also offers methods for the desired resizing to 128x128.
The button accepts a QIcon. Look at the class and find out how to convert a QPixmap to a QIcon. Enjoy

Optional Task 2
---------------

Ensure only digits are entered in the Zip-Code field. See
QLineEdit::setValidator(...)
