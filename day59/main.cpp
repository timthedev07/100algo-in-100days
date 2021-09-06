/**
 * Swap to integers without using a third variable
 *
 */
void swap(int &a, int &b)
{
  a = a + b;
  b = a - b;
  a = a - b;
}
