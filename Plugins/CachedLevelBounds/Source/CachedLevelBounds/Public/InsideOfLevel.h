#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFriendlyLevelName.h"
#include "InsideOfLevel.generated.h"

class ULevel;

USTRUCT(BlueprintType)
struct FInsideOfLevel : public FGameFriendlyLevelName {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULevel> Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox Bounds;
    
    CACHEDLEVELBOUNDS_API FInsideOfLevel();
};

