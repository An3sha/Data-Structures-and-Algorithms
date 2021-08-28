
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
  
  

















