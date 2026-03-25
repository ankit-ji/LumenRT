#include "GUID.h"
#include <random>
#include <cstdint>

namespace LumenRT
{

	// global for this translation unit (static)
	static std::random_device s_RandomDevice;
	static std::mt19937_64 s_RandomEngine(s_RandomDevice());
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;
	const LRT_GUID LRT_GUID::INVALID = LRT_GUID(0);

	LRT_GUID::LRT_GUID()
		: m_GUID(s_UniformDistribution(s_RandomEngine)) {
	}

	LRT_GUID::LRT_GUID(uint64_t guid)
		: m_GUID(guid) {
	}

	LRT_GUID::LRT_GUID(const LRT_GUID& other)
		: m_GUID(other.m_GUID) {
	}
}
