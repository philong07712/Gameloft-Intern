// *p1 = 10 (Because ptr p1 point to iVar so *p1 will return value of iVar)
// *p2 = 0x100 (Because p2 point to p1, so *p2 will return value of p1 which is address of iVar)
// *(*p2) = 10 (because p2 will get value of the address of p1 point to, which is 10)