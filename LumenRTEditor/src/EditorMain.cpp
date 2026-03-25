#include <LumenRT.h>
#include <LumenRTEntrypoint.h>
#include "EditorLayer.h"
#include "EditorCfg.h"

namespace LumenRT
{

	class LumenRTEditor : public Application {
	public:
		LumenRTEditor()
			: Application() {

			m_ImGuiContext = std::make_shared<ImGuiContext>(_Window);
			m_ImGuiContext->Init();

			_LayerStack->PushLayer(std::make_shared<EditorLayer>(_Window, _Profiler, _LayerStack, _ProjectManager, m_ImGuiContext));
		}

		virtual void Shutdown() override {
			m_ImGuiContext->Shutdown();
			Application::Shutdown();
		}
		
		~LumenRTEditor() {
		}

	private:
		std::shared_ptr<ImGuiContext> m_ImGuiContext;
	};

	Application* CreateApplication(const std::filesystem::path& exeDir) {
		EditorCfg::Init(exeDir); // init EditorCfg::EXECUTABLE_DIR, EditorCfg::RESOURCES_PATH
		return new LumenRTEditor();
	}
}