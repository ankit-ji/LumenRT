#pragma once 

#include "lrtpch.h"
#include "Renderer/RenderSettings.h"
#include "Core/GUID.h"

// Forward declarations
namespace LumenRT {
    class SceneManager;
    class AssetManager;
}

namespace LumenRT 
{

	// ============================================================================ 
	// PROJECT FILE (.lrtproj)
	// ----------------------------------------------------------------------------
	// Provides serialization and deserialization of project settings.
	// Used internally by the ProjectManager to persist global project data.
	// ============================================================================
	#define PROJECT_FILE_EXTENSION ".lrtproj"

	struct ProjectFile {
		LRT_GUID bootSceneGuid = LRT_GUID::INVALID;
		RenderSettings runtimeRenderSettings{};

		ProjectFile(LRT_GUID bootSceneGuid = LRT_GUID::INVALID) : bootSceneGuid(bootSceneGuid) {}
	};
	
	/// Serialize the 'projectFile' as-is at the location 'projectFilepath'.
	/// Returns true on success.
	bool SaveProjectFile(const std::filesystem::path& projectFilepath, const ProjectFile& projectFile);

	/// Deserialize from 'projectFilepath' and return 'ProjectFile'.
	/// Returns std::nullopt if unsuccessful.
	std::optional<ProjectFile> LoadProjectFile(const std::filesystem::path& projectFilepath);

	/// Computes the absolute path to the project file (.lrtproj) given the project folder.
	/// Example: Input folder `/MyProject/` -> Output `/MyProject/MyProject.lrtproj`
	inline std::filesystem::path ComposeProjectFilepath(const std::filesystem::path& folderpath) {
		if (folderpath.empty()) {
			LOG_ENGINE_ERROR("ComposeProjectFilepath: folderpath is empty");
			return std::filesystem::path{};
		}
		if (!std::filesystem::exists(folderpath)) {
			LOG_ENGINE_ERROR("ComposeProjectFilepath: folderpath does not exist: {}", folderpath.string());
			return std::filesystem::path{};
		}
		std::string folderName = folderpath.filename().string();
		if (folderName.empty()) {
			LOG_ENGINE_ERROR("ComposeProjectFilepath: could not extract folder name from: {}", folderpath.string());
			return std::filesystem::path{};
		}
		return folderpath / (folderName + PROJECT_FILE_EXTENSION);
	}




	// ============================================================================
	// PROJECT MANAGER
	// ----------------------------------------------------------------------------
	// High-level system responsible for creating, opening, saving, and managing
	// the lifetime of a project.
	// Owns the AssetManager and SceneManager used throughout the editor session.
	// ============================================================================
	class ProjectManager {
	public:
		ProjectManager() = default;
		~ProjectManager() = default;

		/// Creates a new project in the given folder.
		/// Initializes the AssetManager and SceneManager.
		/// Saves an initial project file.
		/// Returns true on success.
		bool NewProject(const std::filesystem::path& folderpath);

		/// Opens an existing project from the given folder.
		/// Loads the project file and initializes managers.
		/// Returns true on success.
		bool OpenProject(const std::filesystem::path& projectfilePath);

		/// Saves the current project file (.lrtproj) into the project folder.
		/// Returns true on success.
		bool SaveProject();

		/// Shuts down managers and clears project data without saving.
		void CloseProject();

		inline bool ProjectIsOpen() const { return !m_ProjectFolder.empty(); }
		inline std::shared_ptr<SceneManager> GetSceneManager() const { return m_SceneManager; }
		inline std::shared_ptr<AssetManager> GetAssetManager() const { return m_AssetManager; }

		inline void SetBootSceneGuid(LRT_GUID guid) { m_ProjectFile.bootSceneGuid = guid; }
		inline LRT_GUID GetBootSceneGuid() const { return m_ProjectFile.bootSceneGuid; }
		inline bool IsBootScene(LRT_GUID guid) { return m_ProjectFile.bootSceneGuid == guid; }

		inline std::string GetProjectName() { return m_ProjectFolder.filename().string(); }
		inline std::filesystem::path GetProjectFolder() { return m_ProjectFolder; }

		inline RenderSettings& GetMutableRuntimeRenderSettings() { return m_ProjectFile.runtimeRenderSettings; }
	private:
		/// Filesystem path to the current project folder (where .lrtproj lives).
		std::filesystem::path m_ProjectFolder;
		ProjectFile m_ProjectFile;

		std::shared_ptr<SceneManager> m_SceneManager = nullptr;
		std::shared_ptr<AssetManager> m_AssetManager = nullptr;
	};
}