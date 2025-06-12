import paho.mqtt.client as mqtt

def on_message(client, userdata, msg):
    print(f"Устройство получило: {msg.payload.decode()}")

client = mqtt.Client()
client.connect("mqtt_broker", 1883)
client.subscribe("lamp/control")
client.on_message = on_message
client.loop_forever()
