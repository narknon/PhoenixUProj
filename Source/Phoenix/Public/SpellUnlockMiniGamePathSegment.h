#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpellUnlockMiniGamePathSegment.generated.h"

USTRUCT(BlueprintType)
struct FSpellUnlockMiniGamePathSegment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D StartPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D EndPoint;
    
    PHOENIX_API FSpellUnlockMiniGamePathSegment();
};

