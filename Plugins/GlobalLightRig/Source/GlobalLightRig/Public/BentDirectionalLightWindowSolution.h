#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BentDirectionalLightWindowSolution.generated.h"

USTRUCT(BlueprintType)
struct FBentDirectionalLightWindowSolution {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SunDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeltaCos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    GLOBALLIGHTRIG_API FBentDirectionalLightWindowSolution();
};

