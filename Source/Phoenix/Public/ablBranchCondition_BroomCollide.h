#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EFlyingBroomHitObjectType.h"
#include "ablBranchCondition_BroomCollide.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablBranchCondition_BroomCollide : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFlyingBroomHitObjectType> FlyingBroomCheckHitObject;
    
public:
    UablBranchCondition_BroomCollide();
};

