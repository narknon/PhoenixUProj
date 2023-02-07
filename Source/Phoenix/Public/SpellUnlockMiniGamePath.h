#pragma once
#include "CoreMinimal.h"
#include "SpellUnlockMiniGamePathSegment.h"
#include "SpellUnlockMiniGamePath.generated.h"

USTRUCT(BlueprintType)
struct FSpellUnlockMiniGamePath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpellUnlockMiniGamePathSegment> PathSegments;
    
    PHOENIX_API FSpellUnlockMiniGamePath();
};

