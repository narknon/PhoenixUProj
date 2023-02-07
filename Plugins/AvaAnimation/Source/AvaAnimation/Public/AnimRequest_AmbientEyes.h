#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimRequestProvider.h"
#include "AnimRequest_AmbientEyes.generated.h"

class UPoseSampler_AmbientEyes;

UCLASS(Blueprintable)
class AVAANIMATION_API UAnimRequest_AmbientEyes : public UObject, public IAnimRequestProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseSampler_AmbientEyes* PoseSampler;
    
    UAnimRequest_AmbientEyes();
    
    // Fix for true pure virtual functions not being implemented
};

