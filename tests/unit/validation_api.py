from django.test import TestCase
from core.validators import validate_command

class CommandValidatorTest(TestCase):
    def test_valid_command(self):
        self.assertTrue(validate_command("light:on"))

    def test_invalid_command(self):
        with self.assertRaises(ValueError):
            validate_command("invalid")
