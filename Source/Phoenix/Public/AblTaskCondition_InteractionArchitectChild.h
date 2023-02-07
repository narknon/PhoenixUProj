#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "EInteractionProject.h"
#include "AblTaskCondition_InteractionArchitectChild.generated.h"

class UInteractionArchitectAsset;

UCLASS(Blueprintable, EditInlineNew)
class UAblTaskCondition_InteractionArchitectChild : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* Parent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeSelf;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractionProject Project;
    
    UAblTaskCondition_InteractionArchitectChild();
};

