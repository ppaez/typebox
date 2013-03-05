#!/usr/bin/env python

import serial
import time
import sys
import string

uppercase_letters = string.ascii_uppercase + '~!@#$%^&*()_+<>?:"{}|'

codes = {
 'tab': '09',
 'cr': '0D',
 'capslock': '10',
 'numlock': '0F',
 'pause / Break': '0E',
 'scrolllock': '11',
 'backspace': '08',
 'delete': '7F',
 'down': '19',
 'end': '1D',
 'escape': '00',
 'home': '1C',
 'insert': '07',
 'left': '1B',
 'menu': '0B',
 'pagedown': '1F',
 'pageup': '1E',
 'printscreen': '0C',
 'right': '1A',
 'up': '18',
 'windows': '0A',
 'f1': '01',
 'f2': '02',
 'f3': '03',
 'f4': '04',
 'f5': '05',
 'f6': '06',
 'f7': '12',
 'f8': '13',
 'f9': '14',
 'f10': '15',
 'f11': '16',
 'f12': '17',
 'hid': '80'}


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
