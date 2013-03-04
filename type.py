#!/usr/bin/env python

import serial
import time
import sys
import string

uppercase_letters = string.ascii_uppercase + '~!@#$%^&*()_+<>?:"{}|'

codes = \
{'!': '21',
 '#': '23',
 '$': '24',
 '%': '25',
 '&': '26',
 '(': '28',
 ')': '29',
 '*': '2A',
 '+': '2B',
 ',': '2C',
 '-': '2D',
 '.': '2E',
 '/': '2F',
 '0': '30',
 '1': '31',
 '2': '32',
 '3': '33',
 '4': '34',
 '5': '35',
 '6': '36',
 '7': '37',
 '8': '38',
 '9': '39',
 ':': '3A',
 ';': '3B',
 '<': '3C',
 '<CR>': '0D',
 '<Caps Lock>': '10',
 '<Num Lock>': '0F',
 '<Pause / Break>': '0E',
 '<Scroll Lock>': '11',
 '<backspace>': '08',
 '<delete>': '7F',
 '<down arrow>': '19',
 '<end>': '1D',
 '<escape>': '00',
 '<home>': '1C',
 '<insert>': '07',
 '<left arrow>': '1B',
 '<menu>': '0B',
 '<page down>': '1F',
 '<page up>': '1E',
 '<print screen>': '0C',
 '<right arrow>': '1A',
 ' ': '20',
 '<tab>': '09',
 '<up arrow>': '18',
 '<windows>': '0A',
 '=': '3D',
 '>': '3E',
 '?': '3F',
 '@': '40',
 'A': '41',
 'B': '42',
 'C': '43',
 'D': '44',
 'E': '45',
 'F': '46',
 'F1': '01',
 'F10': '15',
 'F11': '16',
 'F12': '17',
 'F2': '02',
 'F3': '03',
 'F4': '04',
 'F5': '05',
 'F6': '06',
 'F7': '12',
 'F8': '13',
 'F9': '14',
 'G': '47',
 'H': '48',
 'HID': '80',
 'I': '49',
 'J': '4A',
 'K': '4B',
 'L': '4C',
 'M': '4D',
 'N': '4E',
 'O': '4F',
 'P': '50',
 'Q': '51',
 'R': '52',
 'S': '53',
 'T': '54',
 'U': '55',
 'V': '56',
 'W': '57',
 'X': '58',
 'Y': '59',
 'Z': '5A',
 '[': '5B',
 '\\': '5C',
 ']': '5D',
 '^': '5E',
 '_': '5F',
 '`': '60',
 'a': '61',
 'b': '62',
 'c': '63',
 'd': '64',
 'e': '65',
 'f': '66',
 'g': '67',
 'h': '68',
 'i': '69',
 'j': '6A',
 'k': '6B',
 'l': '6C',
 'm': '6D',
 'n': '6E',
 'o': '6F',
 'p': '70',
 'q': '71',
 'r': '72',
 's': '73',
 't': '74',
 'u': '75',
 'v': '76',
 'w': '77',
 'x': '78',
 'y': '79',
 'z': '7A',
 '{': '7B',
 '|': '7C',
 '}': '7D',
 '~': '7E',
 '\'': '27',
 '"': '22'}

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

if len(sys.argv) > 1:
    file = open(sys.argv[1])
else:
    file = ''

line = True
while line:
    if file:
        line = file.readline()
    else:
        line = input()
    for letter in line:
        if letter == '\n':
            letter = '<CR>'
        code = codes[letter]
        print('{:1} = '.format( letter), end='')

        # shift is needed for upper case
        two_modifier_chars = '00'
        if letter in uppercase_letters:
            two_modifier_chars = '02'
        fourchars = two_modifier_chars + code
        # send
        byteswritten = ser.write(fourchars.encode())
        # wait for response
        while not ser.inWaiting():
            pass
        result = ''
        while '\n' not in result:
            byte = ser.read()
            try:
                byte = byte.decode()
            except:
                byte = '*'
            result += byte
        print(result[:-1])
