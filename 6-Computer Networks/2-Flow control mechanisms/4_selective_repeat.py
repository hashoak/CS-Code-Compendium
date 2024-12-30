import time     # 21BCT0128
import random

class SelectiveRepeat:
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
        
        # Randomly decide whether to send a positive acknowledgment (ACK)
        # or negative acknowledgment (NACK)
        ack_seq_num=self.base
        if bool(random.getrandbits(1)):
            print("Receiver: ACK sent for packet -",ack_seq_num)
            self.buffer[ack_seq_num]=True
            # True indicates the packet has been acknowledged
            self.slide_window(ack_seq_num)
        else:
            print("Receiver: NACK sent for packet -",ack_seq_num)
            self.retransmit_packet(ack_seq_num)
    
    def slide_window(self,ack_seq_num):
        while self.base in self.buffer and self.buffer[self.base]:
            del self.buffer[self.base]
            self.base+=1
    
    def retransmit_packet(self,nack_seq_num):
        print("Sender: Retransmitting packet -",nack_seq_num)

# Create an instance of SelectiveRepeat with a window size of 3
sr=SelectiveRepeat(window_size=3)

# Run the sender
message="21BCT0128"
sr.sender(message)
