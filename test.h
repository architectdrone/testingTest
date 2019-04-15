#ifndef TEST
#define TEST

class TestSuite
{
  public:
    void testAll();

  private:
    int testInit();
    int testAddBack();
    int testAddFront();
    int testAddMultiple();
    int testRemoving();
    int testOrdering();
};

#endif
