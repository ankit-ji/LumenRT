#pragma once

#include "lrtpch.h"

namespace LumenRT
{

	// Globally Unique IDentifier
	// A wrapper for a uint64_t
	class LRT_GUID {
	public:
		static const LRT_GUID INVALID;

		LRT_GUID(); // constructs a random uint64_t GUID
		LRT_GUID(uint64_t guid);
		LRT_GUID(const LRT_GUID& other); // copy constructor
		~LRT_GUID() = default;
		
		bool operator==(const LRT_GUID& other) const { return m_GUID == other.m_GUID; }
		bool operator!=(const LRT_GUID& other) const { return m_GUID != other.m_GUID; }
		operator uint64_t() const { return m_GUID; } // uint64_t conversion operator 

		inline std::string string() const {
			return std::to_string(m_GUID);
		}
		
	private:
		uint64_t m_GUID;
	};
}


// Hashing specialization for GUIDs for use in std::unordered_map ...
namespace std
{
	template<>
	struct hash<LumenRT::LRT_GUID>
	{
		std::size_t operator()(const LumenRT::LRT_GUID& guid) const
		{
			return std::hash<uint64_t>()((uint64_t)guid);
		}
	};
}