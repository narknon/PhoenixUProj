#pragma once
#include "CoreMinimal.h"
#include "NamedBoneInfluences.generated.h"

USTRUCT(BlueprintType)
struct FNamedBoneInfluences {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weights[12];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Names[12];
    
    DYNAMICSPLINESRUNTIME_API FNamedBoneInfluences();
};

