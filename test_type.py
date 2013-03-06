import unittest

class GetCode(unittest.TestCase):

    def test_key(self):
        from type import getcode

        self.assertEqual('61', getcode('a'))

    def test_key_name(self):
        from type import getcode

        self.assertEqual('1C', getcode('home'))

class GetModifier(unittest.TestCase):

    def test_lower_case(self):
        from type import getmodifiers

        self.assertEqual('00', getmodifiers('a'))

    def test_upper_case(self):
        from type import getmodifiers

        self.assertEqual('02', getmodifiers('A'))

    def test_punctuation(self):
        from type import getmodifiers

        self.assertEqual('00', getmodifiers(';'))

    def test_shift_punctuation(self):
        from type import getmodifiers

        self.assertEqual('02', getmodifiers(':'))

    def test_modifier(self):
        from type import getmodifiers

        self.assertEqual('01', getmodifiers('controll'))
