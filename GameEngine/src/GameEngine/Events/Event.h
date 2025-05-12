#pragma once

#include "GameEngine/core/Base.h"
#include<hzpch.h>

namespace GameEngine {
	//Events in GameEngine are Currently blocking, meaning when an event occur it
	//immediately gets dispatched and must be dealt with right then and there
	//_______________________for the future_______________________________
	//A better strategy might be to buffer events in an event 
	//bus and process them during the "Event" part of the update stage

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, Windowfocus, WindowLostfocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    =	BIT(0),
		EventCategoryInput          =	BIT(1),
		EventCategoryKeyboard       =	BIT(2),
		EventCategoryMouse          =	BIT(3),
		EventCategoryMouseButton    =	BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual ~Event() = default;
		bool Handled = false;
		virtual EventType GetEventType()			const = 0;
		virtual const char*	GetName()				const = 0;
		virtual int	GetCategoryFlags()				const = 0;
		virtual std::string	ToString()				const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;

	};


	class EventDispatcher
	{
	
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	};


}


