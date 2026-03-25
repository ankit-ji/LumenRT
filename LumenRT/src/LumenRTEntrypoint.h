#pragma once

#include "Core/application.h"
#include "EngineCfg.h"

// returns new heap allocated polymorphic application
extern LumenRT::Application* LumenRT::CreateApplication(const std::filesystem::path& exeDir);

int main(int argc, char** argv) {
    std::filesystem::path exePath = std::filesystem::weakly_canonical(argv[0]);
    std::filesystem::path exeDir = exePath.parent_path();

    LumenRT::EngineCfg::Init(exeDir); // init EngineCfg::RESOURCES_PATH

    LumenRT::Application* app = LumenRT::CreateApplication(exeDir);
    app->run();
    delete app;
}