import time     #21BCT0128
import random

class StopAndWait:
    def __init__(self):
        self.sequence_number=0
    
    def sender(self,message):
        print("Sender: Sending message -",message)
        
        # Simulating the transmission time
        time.sleep(1)
        
        ack_received=False
        while not ack_received:
            self.receiver(message)
            ack_received=self.receiver(message)
    
    def receiver(self,message):
        # Simulating the receiving of a packet
        time.sleep(1)
        
        # Randomly decide whether to send a positive acknowledgment (ACK)
        # or negative acknowledgment (NACK)
        if bool(random.getrandbits(1)):
            print("Receiver: ACK sent for packet -",message)
            return True
        else:
            print("Receiver: NACK sent. Retransmitting packet...")
            return False

# Create an instance of StopAndWait
sw=StopAndWait()

# Run the sender
sw.sender("21BCT0128")
