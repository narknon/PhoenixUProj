#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimRequestProvider.h"
#include "AnimNotify_CloseEyes.generated.h"

class UPoseSampler_CloseEyes;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotify_CloseEyes : public UAnimNotifyState, public IAnimRequestProvider {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPoseSampler_CloseEyes* PoseSampler;
    
public:
    UAnimNotify_CloseEyes();
    
    // Fix for true pure virtual functions not being implemented
};

