#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include "serviseFunction.hpp"

extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isStorageCreated;

void CreateStorage(int mode = 0);
void ShowStorage();




#endif // !_STORAGE_HPP_