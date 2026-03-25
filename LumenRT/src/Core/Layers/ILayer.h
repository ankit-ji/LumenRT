#pragma once

#include "Core/Events/IEvent.h"

namespace LumenRT 
{

	class ILayer {
	public:
		virtual ~ILayer() = default;

		virtual void onAttach() {};
		virtual void onDetach() {};
		virtual void onUpdate() {};
		virtual void onEvent(std::shared_ptr<IEvent> event) {};
	};
}