#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StarCatalogDebugStar.generated.h"

USTRUCT(BlueprintType)
struct FStarCatalogDebugStar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DebugColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugBrightness;
    
    NIAGARASTARFIELD_API FStarCatalogDebugStar();
};

