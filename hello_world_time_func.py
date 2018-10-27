#! /usr/bin/env python
# -*- coding: UTF-8 -*-

import datetime

def your_name():
    name = input('what\'s is your name?: ')
    print ( 'Hi ' + name + ' I\'m your computer')
    print ('The current time is: ')
    print (datetime.datetime.now()) 

your_name()