#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "QualifierConsideration.h"
#include "SelfCharacterMovementModeConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCharacterMovementModeConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> MovementMode;
    
    USelfCharacterMovementModeConsideration();
};

