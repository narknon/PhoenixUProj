#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BlendDomainState.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FBlendDomainState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> BlendDomains;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLowQuality;
    
    FBlendDomainState();
};

