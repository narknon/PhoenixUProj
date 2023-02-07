#pragma once
#include "CoreMinimal.h"
#include "ELocDirectStringData.generated.h"

UENUM(BlueprintType)
enum class ELocDirectStringData : uint8 {
    identifierName,
    stringType,
    folderPath,
    lastModified,
    text,
    language,
    INVALID,
};

