#include "pch.h"
#include <CppUnitTest.h>

#include "../RazorEngine/src/ecs/Types.h"
#include "../RazorEngine/src/ecs/Registry.h"

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

		TEST_METHOD(TestEntityCreation)
		{
			rz::Registry registry;

			const rz::EntityID entityA = registry.SpawnEntity();
			const rz::EntityID entityB = registry.SpawnEntity();
			const rz::EntityID entityC = registry.SpawnEntity();

			Assert::AreEqual(entityA, rz::EntityID(0));
			Assert::AreEqual(entityB, rz::EntityID(1));
			Assert::AreEqual(entityC, rz::EntityID(2));

			registry.DestroyEntity(entityB);

			const rz::EntityID entityD = registry.SpawnEntity();

			Assert::AreEqual(entityB, entityD);
		}
	};
}
