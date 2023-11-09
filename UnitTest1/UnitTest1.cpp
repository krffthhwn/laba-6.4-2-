#include "pch.h"
#include "CppUnitTest.h"
#include "../laba 6.4(2)/laba6.4(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1LAB64rec
{
	TEST_CLASS(UnitTest1LAB64rec)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double f[] = { -1, 2, -3, 4, 5 };
			int result = Max(f, 5, 0, f[0]);
			Assert::AreEqual(5, result);
		}
	};
}

