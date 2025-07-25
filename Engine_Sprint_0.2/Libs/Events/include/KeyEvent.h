#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include "Event.h"
#include <sstream>

namespace Azul
{
	class EVENTSLIBRARY_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode;  }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) 
			: m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class EVENTSLIBRARY_API KeyPressedEvent : public KeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyPressed);

		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	protected:
		int m_RepeatCount;
	};

	class EVENTSLIBRARY_API KeyReleasedEvent : public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(KeyReleased);

		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
	};
}

#endif