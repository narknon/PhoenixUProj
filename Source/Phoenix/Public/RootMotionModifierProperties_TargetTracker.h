#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ETargetID.h"
#include "UObject/NoExportTypes.h"
#include "ECustomInterpType.h"
#include "ERootMotionModTargetType.h"
#include "RootMotionModifierProperties_TargetTracker.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_TargetTracker : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERootMotionModTargetType TargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGetActorFromTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetID::Type> GetActorFromTargetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> InterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    URootMotionModifierProperties_TargetTracker();
};

