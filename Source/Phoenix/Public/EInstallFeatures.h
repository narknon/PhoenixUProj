#pragma once
#include "CoreMinimal.h"
#include "EInstallFeatures.generated.h"

UENUM(BlueprintType)
enum class EInstallFeatures : uint8 {
    FullGame,
    SonyContent,
    HighDefTextures,
    LanguagePack_EN,
    LanguagePack_DE,
    LanguagePack_ES,
    LanguagePack_ESMX,
    LanguagePack_FR,
    LanguagePack_IT,
    LanguagePack_JA,
    LanguagePack_PT,
    Count,
};

