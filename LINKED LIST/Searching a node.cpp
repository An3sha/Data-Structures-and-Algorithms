//Recursively

bool searchrec (node* head, int key)
{
  if(head == NULL)
  {
    return false;
  }
  //base case
  if(head -> data == key)
  {
    return true;
  }
  else
  {
    return searchrec(head -> next, key);
  }
}

//Iteratively

bool searchit (node* head, int key)
{
  while (head!=NULL)
  {
    if(head -> data == key)
    {
      return true;
    }
    head = head -> next;
  }
  return false;         //if the key is not found till the end
}

  
  















