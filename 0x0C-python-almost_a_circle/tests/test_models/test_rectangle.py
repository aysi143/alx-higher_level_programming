#!/usr/bin/python3
"""Unittests for base
"""

import unittest
from models.rectangle import Rectangle


class TestRectangle(unittest.TestCase):
    """Define unit test for Rectangle model"""

    def test_initialization(self):
        r1 = Rectangle(2,5)
        self.assertEqual(r1.id, Rectangle._Base__nb_objects)
        r2 = Rectangle(1,2)
        self.assertEqual(r2.id, Rectangle._Base__nb_objects)


if __name__ == '__main__':
    unittest.main()
