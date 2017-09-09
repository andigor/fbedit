//
// var1 -|    |        
//       | GT |----|---------|     |
//    5 -|    |    |         | SET |-var2
//                 |     123-|     |
//                 | 
//                 |--------o|     |
//                           | SET |-var2
//                       456-|     |
//

// INT var1;
// INT var2;
// 
// BOOL r1_gt_fun;
// INT r2_set_fun1;
// INT r3_set_fun2;
// 
// r1_gt_fun = gt_fun(var1, 5);
// r1_gt_fun 
//   ? r2_set_fun1 = set_fun(123);
//     var2        = r2_set_fun1;
//   : nop_fun ();
// !r1_gt_fun
//   ? r3_set_fun2 = set_fun(456); 
//     var2 = set_fun(456);
//   : nop_fun();
// 

int main()
{
  return 0;
}


