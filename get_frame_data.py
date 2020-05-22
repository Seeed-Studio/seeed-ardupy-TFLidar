from arduino import grove_tf_lidar
import time

lidar = grove_tf_lidar()

while True:
    while True != lidar.get_frame_data():
        time.sleep(0.001)
    print ("The distance is:", lidar.distance, 'CM')
    print ("The strength is:", lidar.strength, '')
    time.sleep(1)
    

