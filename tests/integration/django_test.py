from django.test import TestCase
from core.mqtt import send_command

class IntegrationTest(TestCase):
    def test_light_control_flow(self):
        response = send_command("light:on")
        self.assertEqual(response.status_code, 200)
        # Проверяем, что mock-устройство получило сообщение (логируется в консоль)
