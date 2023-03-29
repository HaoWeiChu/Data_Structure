
''' 
build single linked-list including:
    insert, delete ,search
    
'''

# create list node
class node:
    def __init__(self,data):
        self.data = data
        self.next = None

class linkedlist:
    # initial the list head
    def __init__(self):
        self.head = None
    
    def printlist(self):
        cur = self.head
        while cur != None:
            print(cur.data,end=' -> ') # 使其結果列印時 不換行 end=''
            cur = cur.next
        print("None")
        
    def append(self,data):
        newnode = node(data)
        if self.head == None:
            self.head = newnode
            return
        cur = self.head
        while cur.next != None:
            cur = cur.next
        cur.next = newnode
    
    def prepend(self,data):
        newnode = node(data)
        newnode.next = self.head
        self.head = newnode
        
    def appoint_insert(self,prev,data):
        newnode = node(data)
        cur = self.head
        while cur.data != prev:
            cur = cur.next
        newnode.next = cur.next
        cur.next= newnode
        
    def delete_node(self,data):
        cur = self.head
        deletenode = node(data)
        # key at the head
        if cur.data == deletenode.data:
            self.head = self.head.next        
            return
        while cur.next.data != deletenode.data:
            cur = cur.next
        deletenode = cur.next
        cur.next = deletenode.next

## main 
if __name__ == '__main__':
    llist = linkedlist()
    llist.append('A')
    llist.append('B')
    llist.append('C')
    llist.append('D')
    llist.delete_node('B')
    llist.appoint_insert('A', 'A+')
    llist.prepend('S')
   
    llist.printlist()
        
        
            
        
            
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
