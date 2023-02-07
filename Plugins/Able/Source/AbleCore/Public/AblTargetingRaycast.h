#pragma once
#include "CoreMinimal.h"
#include "AblTargetingBase.h"
#include "AblTargetingRaycast.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTargetingRaycast : public UAblTargetingBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_OnlyWantBlockingObject;
    
public:
    UAblTargetingRaycast();
};

