/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/


#include "Platforms/AkPlatform_PS4/AkPS4InitializationSettings.h"
#include "AkAudioDevice.h"


#if PLATFORM_PS4
namespace AkLowLevelMemory
{
	constexpr auto PS4_TRUEPAGESIZE = 16 * 1024;
#if FORCE_ANSI_ALLOCATOR
	void* Alloc(size_t Size)
	{
		const auto AlignedSize = Align(Size, PS4_TRUEPAGESIZE);

		off_t DirectMem = 0;
		int ret = sceKernelAllocateDirectMemory(0, SCE_KERNEL_MAIN_DMEM_SIZE, AlignedSize, PS4_TRUEPAGESIZE, SCE_KERNEL_WB_ONION, &DirectMem);
		check(ret == SCE_OK);

		void* Addr = NULL;
		ret = sceKernelMapDirectMemory(&Addr, AlignedSize, SCE_KERNEL_PROT_CPU_RW, 0, DirectMem, PS4_TRUEPAGESIZE);
		check(ret == SCE_OK);

		return Addr;
	}

	void Free(void* Addr, size_t Size)
	{
		const auto AlignedSize = Align(Size, PS4_TRUEPAGESIZE);

		SceKernelVirtualQueryInfo Info;
		sceKernelVirtualQuery(Addr, 0, &Info, sizeof(Info));
		int64 virtual_offset = (uint64)Addr - (uint64)Info.start;
		sceKernelReleaseDirectMemory(Info.offset + virtual_offset, AlignedSize);
	}
#else
	void* Alloc(size_t Size)
	{
		const auto AlignedSize = Align(Size, PS4_TRUEPAGESIZE);
		return FMemory::Malloc(AlignedSize, PS4_TRUEPAGESIZE);
	}

	void Free(void* Addr, size_t Size)
	{
		FMemory::Free(Addr);
	}
#endif
}
#endif // PLATFORM_PS4


//////////////////////////////////////////////////////////////////////////
// FAkPS4AdvancedInitializationSettings

void FAkPS4AdvancedInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

#if PLATFORM_PS4
	InitializationStructure.PlatformInitSettings.uLEngineAcpBatchBufferSize = ACPBatchBufferSize;
	InitializationStructure.PlatformInitSettings.bHwCodecLowLatencyMode = UseHardwareCodecLowLatencyMode;
#endif
}


//////////////////////////////////////////////////////////////////////////
// UAkPS4InitializationSettings

UAkPS4InitializationSettings::UAkPS4InitializationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CommonSettings.SamplesPerFrame = 512;
}

void UAkPS4InitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	InitializationStructure.SetPluginDllPath("PS4");

	CommonSettings.FillInitializationStructure(InitializationStructure);
	CommunicationSettings.FillInitializationStructure(InitializationStructure);
	AdvancedSettings.FillInitializationStructure(InitializationStructure);

#if PLATFORM_PS4
	InitializationStructure.SetupLLMAllocFunctions(AkLowLevelMemory::Alloc, AkLowLevelMemory::Free);
#endif
}
