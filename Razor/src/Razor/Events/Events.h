#pragma once

#include "../Core/Types.h"

namespace Razor
{
	/// <summary>
	/// A coordinator for the engine's event system.
	/// </summary>
	class Events
	{
	public:
		/// <summary>
		/// Creates a new event and returns its key.
		/// </summary>
		/// <returns>The new event's key.</returns>
		static EventKey CreateEvent();

		/// <summary>
		/// Deletes an event with the given key.
		/// </summary>
		/// <param name="key">The key of the target event.</param>
		static void DeleteEvent(EventKey key);

		/// <summary>
		/// Triggers an event with a given key.
		/// </summary>
		/// <param name="key">The key of the target event.</param>
		static void Invoke(EventKey key);
	};
}