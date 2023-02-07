#pragma once
#include "CoreMinimal.h"
#include "ECreditEntryType.generated.h"

UENUM(BlueprintType)
enum class ECreditEntryType : uint8 {
    Header1,
    Header2,
    Header3,
    Header4,
    Line,
    Multiline,
    Image,
    Spacer,
};

