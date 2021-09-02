//delete at head

void deleteathead (node* &head)
{
  if(head == NULL)
  {
    return;
  }
  
  node* temp = head;
  head = head -> next;
  delete temp;
  return;
}

//delete at tail

void deleteattail (node* &head)
{
  node* prev = NULL;
  node* temp = head;
  
  while(temp -> next != NULL)
  {
    prev = temp;
    temp = temp -> next;
  }
  
  delete temp;
  prev -> next = NULL;
  return;
}

//delete from mid

void deleteatmid (node* &head, int key)
{
  node* prev = NULL;
  node* temp = head;
  
  if(temp == NULL)
  {
    return;
  }
  
  while(temp != NULL && temp -> data != key)
  {
    prev = temp;
    temp = temp -> next;
  }
  
  prev -> next = temp -> next;
  delete temp;
  return;
}
  
  
//delete at position

void deleteatpops (node* &head, int pos)
{
  if(head==NULL)
  {
    return;
  }
  node* temp = head;
  if(pos==0)
  {
    head = temp -> next;
    free(temp);
    return;
  }
  for (int i=0; temp!=NULL && i<pos-1; i++)
  {
    temp = temp -> next;
    
    if(temp==NULL || temp -> next = NULL)       //if pos is greater than the number of nodea
    {
      return;
    }
    
    node* next = temp -> next -> next;          //temp->next is the node to be deleted. So, store the pointer to the next of node to be deleted
    free(temp->next);
    temp->next = next;
  }
}
















