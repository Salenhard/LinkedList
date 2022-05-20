#include <iostream>                 // потоки ввода / вывода
#include <string>

#include "Node.h"                   // шаблонный класс узла списка
#include "List.h"                   // класс для создания очереди
#include "LinkedList.h"

using namespace std;                // пространство имён

int main()
{
    string str;
    Node<string>* head = nullptr;   
    string e[3] = {"a","b","c"};  
    List<string> list;             
    for (int i = 0; i < 3; i++)     
    {
        list.add(head, e[i]);
    }
    Node<string>* x = head;         
    while (x != nullptr)           
    {
        str += x->get_data() + " ";
        x = x->get_next();         
    }
    delete head;                  
    str += "\n";
    cout << str;
    str = "Array:\n";
    LinkedList<int> linkList;                   
    linkList.add(5);                            
    Node<int>* h = linkList.get_head();        
    int a = -4;                               
    for (int i = 0; i < 5; i++)                 
    {
        linkList.add(h, a);
    }
    a = 25;                                    
    for (int i = 0; i < 2; i++)               
    {
        linkList.add(h, a);
    }
 
    while (h)                                  
    {
        str += to_string(h->get_data()) + " ";  
        h = h->get_next();
    }
    str += "\nSort array:\n";
    linkList.sort();                         
    h = linkList.get_head();
    while (h)                                  
    {
        str += to_string(h->get_data()) + " ";
        h = h->get_next();
    }
    cout << str + "\n\n\n";
    str += "\nNo duplicate:\n";
    linkList.remove_dupl();
    h = linkList.get_head();
    while (h)                                  
    {
        str += to_string(h->get_data()) + " "; 
        h = h->get_next();
    }
    delete h;                                  
    cout << str + "\n";                        
}