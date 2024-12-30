import time     # 21BCT0128
import random

class SlidingWindow:
    def __init__(self,window_size):
        self.window_size=window_size
        self.base=0
        self.next_seq_num=0
        self.buffer={}
    
    def sender(self,message):
        
        print("Sender: Sending message -",message)
        
        while self.base<len(message):
            if self.next_seq_num<self.base+self.window_size:
                print("Sender: Sending packet -",message[self.base])
                self.buffer[self.next_seq_num]=False
                # False indicates the packet has not been acknowledged
                self.next_seq_num+=1
            
            # Simulating the transmission time
            time.sleep(0.1)
            
            self.receiver()
        
        print("Sender: All packets acknowledged.")
    
    def receiver(self):
        # Simulating the receiving of a packet
        time.sleep(0.1)
        
        # Randomly decide whether to send an acknowledgment or not
        ack_seq_num=self.base
        if bool(random.getrandbits(1)):
            print("Receiver: ACK sent for packet -",ack_seq_num)
            self.buffer[ack_seq_num]=True
            # True indicates the packet has been acknowledged
            self.base+=1
        else:
            print("Receiver: NACK sent. Retransmitting packets...")
            self.base = ack_seq_num
            # Go back to the sequence number of the NACK
            
        self.slide_window()
    
    def slide_window(self):
        while self.base in self.buffer and self.buffer[self.base]:
            del self.buffer[self.base]
            self.base+=1

# Create an instance of SlidingWindow with a window size of 3
window=SlidingWindow(window_size=3)

# Run the sender
message="21BCT0128"
window.sender(message)
