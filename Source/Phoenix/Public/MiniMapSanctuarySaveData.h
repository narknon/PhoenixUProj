#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryMiniMapType.h"
#include "MiniMapSanctuarySaveData.generated.h"

USTRUCT(BlueprintType)
struct FMiniMapSanctuarySaveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESanctuaryMiniMapType::Type> CurrentMapType;
    
    PHOENIX_API FMiniMapSanctuarySaveData();
};

