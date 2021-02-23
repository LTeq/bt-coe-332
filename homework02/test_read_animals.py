import unittest
from read_animals import *

class TestReadAnimals(unittest.TestCase):
	
	def test_animal_parts(self):
		self.assertRaises(AssertionError, check_animal_head, 1)
		self.assertRaises(AssertionError, check_animal_body, 1)
		self.assertRaises(AssertionError, check_animal_arms, '5')
		self.assertRaises(AssertionError, check_animal_legs, '5')
		self.assertRaises(AssertionError, check_animal_tail, '5')

if __name__ == '__main__':
	unittest.main()
