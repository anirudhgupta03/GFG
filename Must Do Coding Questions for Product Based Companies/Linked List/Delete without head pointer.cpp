//Ref: https://www.youtube.com/watch?v=icnp4FJdZ_c
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       del -> data = del -> next -> data;
       del -> next = del -> next -> next;
    }

};
