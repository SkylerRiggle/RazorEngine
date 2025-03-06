#include "pch.h"
#include <CppUnitTest.h>

#include "../RazorEngine/src/dstruct/Tuple.h"
#include "../RazorEngine/src/dstruct/BlockList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(DStructTest)
	{
	public:
		TEST_METHOD(TestBlockList)
		{
			const size_t block_size = 10;
			const size_t total_size = block_size * 10;
			rz::BlockList<size_t> list(block_size);

			for (size_t iter = 0; iter < 10; iter++) {
				for (size_t i = 0; i < total_size; i++) {
					list.Push(i);
					Assert::AreEqual(i + 1, list.Size());
					Assert::AreEqual(i, list.Peek());
					Assert::IsFalse(list.IsEmpty());
				}

				size_t pop_count = 0;
				while (!list.IsEmpty()) {
					Assert::AreEqual(total_size - pop_count - 1, list.Peek());

					list.Pop();
					pop_count++;

					Assert::AreEqual(total_size - pop_count, list.Size());
				}
			}
		}

		TEST_METHOD(TestTuple)
		{
			rz::Tuple<int, float, double> tuple(1, 2.0f, 3.0);

			Assert::AreEqual(1, tuple.Get<int>());
			Assert::AreEqual(2.0f, tuple.Get<float>());
			Assert::AreEqual(3.0, tuple.Get<double>());

			tuple.Get<int>() = 10;
			tuple.Get<float>() = 20.0f;
			tuple.Get<double>() = 30.0;

			Assert::AreEqual(10, tuple.Get<int>());
			Assert::AreEqual(20.0f, tuple.Get<float>());
			Assert::AreEqual(30.0, tuple.Get<double>());
		}
	};
}
