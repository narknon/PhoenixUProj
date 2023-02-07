#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ETargetID.h"
#include "EInteractUseTargetTracker.h"
#include "RootMotionModifierProperties_Interact.generated.h"

class URootMotionModProperties_Interact;

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_Interact : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractUseTargetTracker UseTargetTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseActorFromTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetID::Type> SpecificTargetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URootMotionModProperties_Interact* Properties;
    
    URootMotionModifierProperties_Interact();
};

