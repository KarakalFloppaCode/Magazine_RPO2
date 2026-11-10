#include "account.hpp"




size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"Karakal", L"cat", L"user"};
std::wstring* passArr = new std::wstring[userSize]{ L"admin123", L"cat", L"user" };
std::wstring* statusArr = new std::wstring[userSize]{ L"Super admin", L"admin", L"user" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };




