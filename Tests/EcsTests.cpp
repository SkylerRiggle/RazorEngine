#include "pch.h"
#include <CppUnitTest.h>

#include "../RazorEngine/src/ecs/Types.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ECSTest)
	{
	public:
		TEST_METHOD(TestECSTypes)
		{
			rz::uint32 int_id = rz::ComponentID::Get<int>();
			rz::uint32 float_id = rz::ComponentID::Get<float>();
			rz::uint32 entity_id = rz::ComponentID::Get<rz::EntityID>();

			Assert::AreNotEqual(int_id, float_id);
			Assert::AreNotEqual(int_id, entity_id);
			Assert::AreNotEqual(float_id, entity_id);

			Assert::AreEqual(int_id, rz::uint32(0));
			Assert::AreEqual(float_id, rz::uint32(1));
			Assert::AreEqual(entity_id, rz::uint32(2));
		}
	};
}
