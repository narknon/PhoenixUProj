#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DistanceFogExtraVariables.generated.h"

USTRUCT(BlueprintType)
struct FDistanceFogExtraVariables {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLinearColor> Colors;
    
    RENDERSETTINGS_API FDistanceFogExtraVariables();
};

