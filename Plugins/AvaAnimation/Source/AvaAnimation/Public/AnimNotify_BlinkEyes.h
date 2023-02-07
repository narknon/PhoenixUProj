#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimRequestProvider.h"
#include "AnimNotify_BlinkEyes.generated.h"

class UPoseSampler_BlinkEyes;

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_BlinkEyes : public UAnimNotify, public IAnimRequestProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoubleBlink;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlinkSpeed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPoseSampler_BlinkEyes* PoseSampler;
    
public:
    UAnimNotify_BlinkEyes();
    
    // Fix for true pure virtual functions not being implemented
};

