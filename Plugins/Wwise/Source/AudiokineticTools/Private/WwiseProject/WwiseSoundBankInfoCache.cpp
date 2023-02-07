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

#include "WwiseSoundBankInfoCache.h"

#include "AssetManagement/AkAssetDatabase.h"
#include "AkUnrealHelper.h"
#include "HAL/FileManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Misc/Paths.h"
#include "WwiseProjectInfo.h"

namespace WwiseSoundBankInfoCacheHelpers
{
	constexpr auto CacheVersion = 1;
	constexpr auto SFXLanguageID = 393239870;
}

bool WwiseSoundBankInfoCache::Load(const FString& Path)
{
	WwiseProjectInfo wwiseProjectInfo;
	wwiseProjectInfo.Parse();

	for (auto& platform : wwiseProjectInfo.GetSupportedPlatforms())
	{
		platformNameToGuidMap.Add(platform.Name, platform.ID);
	}

	auto& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	TUniquePtr<FArchive> ar(IFileManager::Get().CreateFileReader(*Path));

	uint32 readVersion = 0;
	*ar << readVersion;

	if (readVersion != WwiseSoundBankInfoCacheHelpers::CacheVersion)
	{
		return false;
	}

	uint32 flagsHash = 0;
	*ar << flagsHash;

	FGuid currentPlatform;
	uint32 currentLanguage = 0;
	CacheType currentCacheType = static_cast<CacheType>(0);

	SerializeState serializeState = SerializeState::None;
	*ar << serializeState;

	while (serializeState != SerializeState::EndOfData)
	{
		switch (serializeState)
		{
			case SerializeState::None:
			case SerializeState::EndOfData:
				break;
			case SerializeState::Platform:
			{
				readGuid(*ar, currentPlatform);
				break;
			}
			case SerializeState::Language:
			{
				*ar << currentLanguage;
				break;
			}
			case SerializeState::BankInfo:
			{
				FString name;
				readString(*ar, name);

				auto key = CacheKey(name, currentPlatform, currentLanguage);

				BankInfo& info = bankInfoMap.Emplace(key);
				*ar << info;
				break;
			}
			case SerializeState::InfoFile:
			{
				FString name;
				readString(*ar, name);

				FileInfo info;
				*ar << info;
				break;
			}
			case SerializeState::InfoFileType:
			{
				*ar << currentCacheType;
				break;
			}
		}

		*ar << serializeState;
	}

	return true;
}

void WwiseSoundBankInfoCache::readString(FArchive& Ar, FString& Value)
{
	uint32 stringSize = 0;
	Ar << stringSize;

	TArray<uint8> rawString;
	rawString.SetNumUninitialized(stringSize);

	Ar.Serialize(rawString.GetData(), stringSize);

	FUTF8ToTCHAR utf8(reinterpret_cast<const char*>(rawString.GetData()), stringSize);
	Value = FString(utf8.Length(), utf8.Get());
}

void WwiseSoundBankInfoCache::readGuid(FArchive& Ar, FGuid& Id)
{
	uint32 data1;
	uint16 data2;
	uint16 data3;
	uint8 data4[8];

	Ar << data1;
	Ar << data2;
	Ar << data3;
	Ar.Serialize(data4, sizeof(data4));

	Id.A = data1;
	Id.B = data3 | (data2 << 16);
	Id.C = data4[3] | (data4[2] << 8) | (data4[1] << 16) | (data4[0] << 24);
	Id.D = data4[7] | (data4[6] << 8) | (data4[5] << 16) | (data4[4] << 24);
}

void WwiseSoundBankInfoCache::readBool(FArchive& Ar, bool& Value)
{
	uint8 temp = 0;
	Ar.Serialize(&temp, 1);
	Value = temp > 0;
}

bool WwiseSoundBankInfoCache::IsSoundBankUpToUpdate(const FGuid& Id, const FString& Platform, const FString& Language, const uint32 Hash) const
{
	FString bankName = AkUnrealHelper::GuidToBankName(Id);

	FGuid platformGuid;
	
	if (auto platformIt = platformNameToGuidMap.Find(Platform))
	{
		platformGuid = *platformIt;
	}

	uint32 languageId = WwiseSoundBankInfoCacheHelpers::SFXLanguageID;

	if (Language != TEXT("SFX") && Language.Len()>0)
	{
		AK::FNVHash32 hash;
		FTCHARToUTF8 utf8(*Language.ToLower());
		languageId = hash.Compute(utf8.Get(), utf8.Length());
	}

	CacheKey key(bankName, platformGuid, languageId);

	if (auto* cacheEntry = bankInfoMap.Find(key))
	{
		return cacheEntry->Hash == Hash;
	}

	return false;
}

FArchive& operator<<(FArchive& Ar, WwiseSoundBankInfoCache::FileInfo& Value)
{
	Ar << Value.Hash;
	Ar << Value.Timestamp;
	WwiseSoundBankInfoCache::readBool(Ar, Value.Updated);
	return Ar;
}

FArchive& operator<<(FArchive& Ar, WwiseSoundBankInfoCache::BankInfo& Value)
{
	Ar << static_cast<WwiseSoundBankInfoCache::FileInfo&>(Value);
	Ar << Value.Stats;
	WwiseSoundBankInfoCache::readBool(Ar, Value.IsTemporary);

	return Ar;
}

FArchive& operator<<(FArchive& Ar, WwiseSoundBankInfoCache::MemoryStats& Value)
{
	Ar << Value.Timestamp;
	Ar << Value.DataSize;
	Ar << Value.FileSize;
	Ar << Value.DecodedSize;
	Ar << Value.SFXPreFetchSize;
	Ar << Value.SFXInMemorySize;
	Ar << Value.SFXMissingFiles;
	Ar << Value.MusicPreFetchSize;
	Ar << Value.MusicInMemorySize;
	Ar << Value.MusicMissingFiles;
	Ar << Value.VoicePreFetchSize;
	Ar << Value.VoiceInMemorySize;
	Ar << Value.VoiceMissingFiles;
	Ar << Value.ReplacedFiles;

	return Ar;
}

uint32 GetTypeHash(const WwiseSoundBankInfoCache::CacheKey& Key)
{
	AK::FNVHash32 hash;
	hash.Compute(*Key.Name, sizeof(TCHAR) * Key.Name.Len());
	hash.Compute(&Key.Platform, sizeof(FGuid));
	hash.Compute(&Key.Language, sizeof(uint32));
	return hash.Get();
}