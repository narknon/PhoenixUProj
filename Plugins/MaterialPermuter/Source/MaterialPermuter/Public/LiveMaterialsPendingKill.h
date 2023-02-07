#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LiveMaterialsPendingKill.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FLiveMaterialsPendingKill {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan LastTouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan DeathDelay;
    
    FLiveMaterialsPendingKill();
};

