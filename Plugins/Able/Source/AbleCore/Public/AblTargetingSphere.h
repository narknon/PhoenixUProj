#pragma once
#include "CoreMinimal.h"
#include "AblTargetingBase.h"
#include "AblTargetingSphere.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTargetingSphere : public UAblTargetingBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_radius;
    
public:
    UAblTargetingSphere();
};

