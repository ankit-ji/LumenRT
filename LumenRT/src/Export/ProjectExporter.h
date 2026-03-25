#pragma once

#include "lrtpch.h"
#include "Export/ExportSettings.h"

namespace LumenRT
{

	bool ExportProject(
		const std::string& projectName,
		const std::filesystem::path dstfolderpath,
		const std::filesystem::path srcfilepath,
		const ExportSettings& exportSettings);
}