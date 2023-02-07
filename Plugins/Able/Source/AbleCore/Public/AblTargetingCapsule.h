#pragma once
#include "CoreMinimal.h"
#include "AblTargetingBase.h"
#include "AblTargetingCapsule.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTargetingCapsule : public UAblTargetingBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
public:
    UAblTargetingCapsule();
};

