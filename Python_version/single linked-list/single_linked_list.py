# -*- coding: utf-8 -*-
"""
Created on Wed Mar 22 14:08:21 2023

@author: howger
"""

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next != None:
            last_node = last_node.next

        last_node.next = new_node

    def print_list(self):
        curr_node = self.head
        while curr_node:
            print(curr_node.data)
            curr_node = curr_node.next

    def insert_after_node(self, prev_node, new_data):
        """
        在指定節點後插入新節點
        :prev_node_data: 指定節點的資料
        :new_data: 新節點的資料
        """
        current_node = self.head
        while current_node:
            if current_node.data == prev_node:
                new_node = Node(new_data)
                new_node.next = current_node.next
                current_node.next = new_node
                return
            current_node = current_node.next
        print('您所需要的節點不在鏈表當中')

    def delete_node(self, key):
        curr_node = self.head

        if curr_node and curr_node.data == key:
            self.head = curr_node.next
            curr_node = None
            return

        prev_node = None
        while curr_node and curr_node.data != key:
            prev_node = curr_node
            curr_node = curr_node.next

        if curr_node is None:
            return

        prev_node.next = curr_node.next
        curr_node = None

    def switch(self, choice):
        if choice == 1:
            num = int(input('請輸入要插入的數字: '))
            prev = int(input('請輸入要取代的位置: '))
            self.insert_after_node(prev, num)
            print('已經在指定位置插入新節點')
        elif choice == 2:
            key = int(input('請輸入要刪除的數字: '))
            self.delete_node(key)
            print('已經刪除指定節點')
        else:
            print('請輸入正確的選項')
# 主程式
if __name__ == '__main__':
    linked_list = LinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(3)
    linked_list.print_list()

    while True:
        print('請選擇要執行的操作：')
        print('1. 在指定位置插入新節點')
        print('2. 刪除指定節點')
        print('3. 結束程式')
        choice = int(input('請輸入選項: '))

        if choice == 3:
            break

        linked_list.switch(choice)
        linked_list.print_list()
    print('----------------------')
    print('最終結果(final results)')
    linked_list.print_list()