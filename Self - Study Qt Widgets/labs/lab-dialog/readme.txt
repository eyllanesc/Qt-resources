==========
Dialog Lab
==========

Shows how modal and modeless dialogs can be launched and value changes are reflected back to the main window.
From the main window you can launch the dialogs in modeless and modal mode.

MainWindow class
================

 * A simple widget
 * Shows a slider and two buttons.
 * Button modal, launches a modal dialog
 * Button modeless, launches a modeless dialog
 * The slider value changed is connected to the dialog set value.
 * onModal and onModeless slots launches the dialogs


Value Dialog class
==================
 * Dialog derived from QDialog
 * A dialog, which displays a spinbox and a slider.
 * Spinbox and slider value changes are connected to each others set value.
 * Emits valueChanged if sliders value is changed
 * Provides also a setValue, which set's value on the slider.
 * Additional shows two dialog buttons Ok and Cancel.
 * The dialog shall only be accepted, if the value is < 50, otherwise a message box is shown.

Note: To show a message box, use QMessageBox::information(...)

===================
Optional FindDialog
===================

 * Create a find dialog for a QTextEdit
 * The dialog shall be modeless
 * Find next shall be case sensitive/insensitive
 * Find shall find backward, forwards

Tip: See QTextEdit::find(...)

