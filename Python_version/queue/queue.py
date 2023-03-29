

class student():
    def __init__(self):
        self.name = ''
        self.score = 0
        self.next = None

class queue():
    def __init__(self):
        self.front = None
        self.rear = None
          
    def enqueue(self,name,score):
        newnode = student()
        newnode.name = name
        newnode.score = score
        if self.rear == None:
            self.front = newnode
        else:
            self.rear.next = newnode
        self.rear = newnode
    
    def dequeue(self):
        if self.front == None:
            print('the queue is empty')
        else:
            print('name:%s and score:%d was taken out'%(self.front.name, self.front.score))
            self.front = self.front.next
        
    def quprint(self):
        ptr = self.front
        if ptr == None:
            print('the queue is empty')
        else:
            while ptr != None:
                print('name:%s and score:%d'%(ptr.name,ptr.score))
                ptr = ptr.next

if __name__ == '__main__':
    q = queue()
    q.enqueue('howard',80)
    q.enqueue('koko',90)
    q.enqueue('dodo',100)
    q.dequeue()
    print('\nfinal output is below')
    print('---------------------------------')
    q.quprint()
