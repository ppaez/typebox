#!/usr/bin/env python

import serial
import time
import sys
import string

uppercase_letters = string.ascii_uppercase + '~!@#$%^&*()_+<>?:"{}|'

codes = \
 {'<tab>': '09',
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
 '<up arrow>': '18',
 '<windows>': '0A',
 'F1': '01',
 'F2': '02',
 'F3': '03',
 'F4': '04',
 'F5': '05',
 'F6': '06',
 'F7': '12',
 'F8': '13',
 'F9': '14',
 'F10': '15',
 'F11': '16',
 'F12': '17',
 'HID': '80'}


if __name__ == '__main__':

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
            code = ord(letter)

            # send '*' if invalid
            if 31 < code < 128:
                code = hex(code)[2:]
            elif letter == '\n':
                code = '0D'
            elif letter == '\t':
                code = '09'
            else:
                code = hex(ord('*'))[2:]
            print('{:1} = '.format( letter), end='')

            # shift is needed for upper case
            two_modifier_chars = '00'
            if letter in uppercase_letters:
                two_modifier_chars = '02'

            # four hex characters
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
