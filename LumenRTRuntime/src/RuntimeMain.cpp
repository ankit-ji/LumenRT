#include <LumenRT.h>
#include <LumenRTEntrypoint.h>
#include <filesystem>
#include "RuntimeLayer.h"
#include "RuntimeCfg.h"

namespace LumenRT
{

	class LumenRTRuntime : public Application {
	public:
		LumenRTRuntime(WindowProps windowProps)
			: Application(windowProps) {

			_LayerStack->PushLayer(std::make_shared<RuntimeLayer>(_Window, _Profiler, _LayerStack, _ProjectManager));
		}

		~LumenRTRuntime() {

		}
	};

	Application* CreateApplication(const std::filesystem::path& exeDir) {
		RuntimeCfg::Init(exeDir); // init EXECUTABLE_DIR
		WindowProps spec;
		spec.CustomTitlebar = false;
		return new LumenRTRuntime(spec);
	}
}
