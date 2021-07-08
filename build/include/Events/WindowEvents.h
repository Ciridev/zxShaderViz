#pragma once

#include "Event.h"

class WindowResized : public Event 
{
public:
	WindowResized(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

	virtual EventType	GetEventType()		const override { return EventType::WindowResized; }
	virtual const char* GetEventName()		const override { return "WindowResized"; }
	virtual std::string GetEventNameStr()   const override { return "WindowResized"; }
	virtual std::string GetEventInfo()		const override 
	{ 
		std::stringstream ss;
		ss << "WindowResized: [x(" << m_Width << ") | y(" << m_Height << ")]";
		return ss.str(); 
	}

	unsigned int GetWidth()  const { return m_Width;  }
	unsigned int GetHeigth() const { return m_Height; }

	static EventType GetEventStaticType() { return EventType::WindowResized; }

	virtual bool IsHandled() const override { return m_Handled; };

private:
	unsigned int m_Width;
	unsigned int m_Height;
};

class WindowClosed : public Event 
{ 
public:
	virtual EventType	GetEventType()		const override { return EventType::WindowClosed; }
	virtual const char* GetEventName()		const override { return "WindowClosed"; }
	virtual std::string GetEventNameStr()   const override { return "WindowClosed"; }
	virtual std::string GetEventInfo()		const override { return "WindowClosed [No info]"; }

	static EventType GetEventStaticType() { return EventType::WindowClosed; }

	virtual bool IsHandled() const override { return m_Handled; };
};

class AppTick : public Event 
{ 
public:
	virtual EventType	GetEventType()		const override { return EventType::AppTick; }
	virtual const char* GetEventName()		const override { return "AppTick"; }
	virtual std::string GetEventNameStr()   const override { return "AppTick"; }
	virtual std::string GetEventInfo()		const override { return "AppTick [No info]"; }

	static EventType GetEventStaticType() { return EventType::AppTick; }

	virtual bool IsHandled() const override { return m_Handled; };
};

class AppRender : public Event 
{
public:
	virtual EventType	GetEventType()		const override { return EventType::AppRender; }
	virtual const char* GetEventName()		const override { return "AppRender"; }
	virtual std::string GetEventNameStr()   const override { return "AppRender"; }
	virtual std::string GetEventInfo()		const override { return "AppRender [No info]"; }

	static EventType GetEventStaticType() { return EventType::AppRender; }

	virtual bool IsHandled() const override { return m_Handled; };
};

