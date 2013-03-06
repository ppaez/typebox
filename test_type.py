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


class ParseLine(unittest.TestCase):

    def test_key(self):
        from type import parse_line

        self.assertEqual( [['a']], parse_line('a'))

    def test_name(self):
        from type import parse_line

        self.assertEqual( [['name']], parse_line('{name}'))

    def test_two_names(self):
        from type import parse_line

        self.assertEqual( [['mod','key']], parse_line('{mod-key}'))

    def test_three_names(self):
        from type import parse_line

        self.assertEqual( [['mod1', 'mod2', 'key']], parse_line('{mod1-mod2-key}'))

    def test_two_groups(self):
        from type import parse_line

        self.assertEqual( [['name1'], ['a'], ['b'], ['name2']],
                          parse_line('{name1}ab{name2}'))
