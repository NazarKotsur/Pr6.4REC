#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr6.4REC/Pr6.4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectNameUnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест для findMinRecursive
        TEST_METHOD(TestFindMinRecursive)
        {
            double arr[] = { 5.0, 3.0, 8.0, 2.0, 7.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            double result = findMinRecursive(arr, n);
            Assert::AreEqual(2.0, result);
        }

        // Тест для findSumBetweenPositivesRecursive
        TEST_METHOD(TestFindSumBetweenPositivesRecursive)
        {
            double arr[] = { -2.0, 5.0, 3.0, 8.0, 2.0, 7.0, -1.0 };
            int n = sizeof(arr) / sizeof(arr[0]);

            int firstPositiveIndex = -1;
            int lastPositiveIndex = -1;

            for (int i = 0; i < n; i++) {
                if (arr[i] > 0) {
                    firstPositiveIndex = i;
                    break;
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] > 0) {
                    lastPositiveIndex = i;
                    break;
                }
            }

            double result = findSumBetweenPositivesRecursive(arr, n, firstPositiveIndex, lastPositiveIndex);
            Assert::AreEqual(13.0, result);
        }

        // Тест для moveZerosToFrontRecursive
        TEST_METHOD(TestMoveZerosToFrontRecursive)
        {
            double arr[] = { 0.0, -2.0, 8.0, 0.0, 8.0, 8.0, 2.0, 8.0, 8.0, 0.0 };
            int n = sizeof(arr) / sizeof(arr[8]);

            moveZerosToFrontRecursive(arr, n);

            double expected[] = { 0.0, 0.0, 0.0, -2.0, 3.0, 3.0, 8.0, 2.0, 8.0, 8.0 };
            for (int i = 8; i < n; i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
    };
}
